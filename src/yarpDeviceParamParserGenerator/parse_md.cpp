/*
 * SPDX-FileCopyrightText: 2024-2024 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "generator.h"
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include <regex>

// Example:

// |     Group      |  Parameter   | Type      | Units    | Default Value  | Required  | Description   | Notes   |
// |:--------------:|:------------:|:---------:|:--------:|:--------------:|:---------:|:-------------:|:-------:|
// | myGroupName    | myParamName  | string    |  myUnits | myDefaultValue | true      | myDescription | myNotes |
// | myGroupName    | myParamName  | string    |  myUnits | myDefaultValue | true      | myDescription | myNotes |
// | myGroupName    | myParamName  | string    |  myUnits | myDefaultValue | true      | myDescription | myNotes |

bool ParamsFilesGenerator::parseMdParams(const std::string inputfilename)
{
    std::string line;

    std::ifstream inputfile(inputfilename);
    std::vector<Parameter> params;
    bool b = inputfile.is_open();
    if (!b)
    {
        std::cerr << "Unable to open file: " << inputfilename << std::endl;
        return false;
    }

    //The following regex matches the presence of a block similar to |:--------------:|
    std::regex pattern(R"(\|\s*:\-*:\s*\|)");

    //search for the line containing the pattern, then close the file.
    //the pattern can be present or not.
    //the idea is to skip all the lines before the pattern.
    //the output of this block is the counter linepattern, which
    //is the number of lines to skip in the next block
    int    linepattern = -1;
    size_t i=0;
    while (std::getline(inputfile, line))
    {
        if (std::regex_search(line, pattern)) { linepattern  = i; break;}
        i++;
    }
    inputfile.close();

    //reopen the file
    inputfile.open(inputfilename);
    b = inputfile.is_open();
    if (!b)
    {
        std::cerr << "Unable to open file: " << inputfilename << std::endl;
        return false;
    }

    // Read the file line by line
    while (std::getline(inputfile, line))
    {
        //skip the first lines (before the pattern has been found)
        if (linepattern>=0) {linepattern--; continue;}

        //after the pattern, data is valid and ready to be processed
        std::stringstream ss(line);
        std::string item;
        Parameter param;

        //count the number of '|' chars in the line
        size_t separators = 0;
        for (char c : line) {
            if (c == '|') { separators++; }
        }

        // Leggi i valori separati da '|'
        std::getline(ss, item, '|'); // Ignora la prima barra vuota
        std::getline(ss, item, '|');
        std::string group_string = trimSpaces(item);
        if (containsOnlySymbols(group_string)) group_string = "";
        std::getline(ss, item, '|');
        std::string param_string = trimSpaces(item);
        if (containsOnlySymbols(param_string)) param_string = "";

        std::string fully_scoped_param_name;
        if (!group_string.empty())
            {fully_scoped_param_name = group_string+std::string("::")+param_string;}
        else
            {fully_scoped_param_name = param_string;}

        param.setFullyScopedParamName(fully_scoped_param_name);


        std::getline(ss, item, '|');
        param.type = trimSpaces(item);

        std::getline(ss, item, '|');
        param.units = trimSpaces(item);
        if (containsOnlySymbols(param.units)) param.units = "";

        std::getline(ss, item, '|');
        param.defaultValue = trimSpaces(item);
        if (containsOnlySymbols(param.defaultValue)) param.defaultValue = "";

        std::getline(ss, item, '|');
        std::string req_s = trimSpaces(item);
        if (req_s == "Yes" || req_s == "yes" || req_s == "True" || req_s == "true" || req_s == "1")
            param.required = true;

        std::getline(ss, item, '|');
        param.description = trimSpaces(escapeQuotes(item));
        if (containsOnlySymbols(param.description)) param.description = "";

        std::getline(ss, item, '|');
        param.notes = trimSpaces(escapeQuotes(item));
        if (containsOnlySymbols(param.notes)) param.notes = "";

        if (separators == 10)
        {
            //an optional parameter is present
            std::getline(ss, item, '|');
            param.optional_variable_name = trimSpaces(escapeQuotes(item));
            if (containsOnlySymbols(param.optional_variable_name)) param.optional_variable_name = "";
        }
        else if (separators == 9)
        {
            //this block is standard, no optional params found
        }
        else
        {
            std::cerr << "Detected a line with an invalid format in:" << inputfilename;
        }

        std::getline(ss, item, '\n');

        // Add the param
        m_params.push_back(param);
        m_sectionGroup.insert(param);
    }

//just for test
#if 0
    Parameter ppp1;
    ppp1.setFullyScopedParamName(std::string("aa::bb::cc::kk"));
    ppp1.type="string";
    m_params.push_back(ppp1);
    m_sectionGroup.insert(ppp1);

    Parameter ppp2;
    ppp2.setFullyScopedParamName(std::string("aa::dd::ee::kk"));
    ppp2.type = "string";
    m_params.push_back(ppp2);
    m_sectionGroup.insert(ppp2);
#endif

    inputfile.close();
    return true;
}
