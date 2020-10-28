// Copyright (C) 2020 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef PARSER_CONTEXT_H
#define PARSER_CONTEXT_H
#include <string>
#include <map>
#include <cc/data.h>
#include <cc/parser.h>
#include <cc/parser_context_decl.h>
#include <exceptions/exceptions.h>

// Tell Flex the lexer's prototype ...
#define YY_DECL \
    isc::data::Parser::symbol_type parserlex (ParserContext& driver)

// ... and declare it for the parser's sake.
YY_DECL;

namespace isc {
namespace data {

/// @brief Evaluation error exception raised when trying to parse.
class ParseError : public isc::Exception {
public:
    ParseError(const char* file, size_t line, const char* what) :
        isc::Exception(file, line, what) { };
};

/// @brief Evaluation context, an interface to the data parser.
class ParserContext
{
public:

    /// @brief destructor
    virtual ~ParserContext();

    /// @brief Method called before scanning starts on a string.
    ///
    /// @param str string to be parsed.
    void scanStringBegin(const std::string& str);

    /// @brief Method called before scanning starts on a file.
    ///
    /// @param f stdio FILE pointer.
    /// @param filename file to be parsed.
    void scanFileBegin(FILE* f, const std::string& filename);

    /// @brief Method called after the last tokens are scanned.
    void scanEnd();

    /// @brief Run the parser on the string specified.
    ///
    /// @param str string to be parsed
    /// @return Element structure representing parsed text.
    ElementPtr parseString(const std::string& str);

    /// @brief Run the parser on the file specified.
    ///
    /// @param filename file to be parsed.
    /// @return Element structure representing parsed text.
    ElementPtr parseFile(const std::string& filename);

    /// @brief The name of the file being parsed.
    /// Used later to pass the file name to the location tracker.
    std::string file_;

    /// @brief The string being parsed.
    std::string string_;

    /// @brief Error handler.
    ///
    /// @param loc location within the parsed file when experienced a problem.
    /// @param what string explaining the nature of the error.
    /// @param pos optional position for in string errors.
    /// @throw ParseError.
    static void error(const isc::data::location& loc,
		      const std::string& what,
		      size_t pos = 0);

    /// @brief Error handler.
    ///
    /// This is a simplified error reporting tool for possible future
    /// cases when the Parser is not able to handle the packet.
    ///
    /// @param what string explaining the nature of the error.
    /// @throw ParseError
    static void error(const std::string& what);

    /// @brief Fatal error handler.
    ///
    /// This is for should not happen but fatal errors.
    ///
    /// @param what string explaining the nature of the error.
    /// @throw isc::Unexpected.
    static void fatal(const std::string& what);

private:
    /// @brief Common part of parseXXX.
    ///
    /// @return Element structure representing parsed text.
    ElementPtr parseCommon();
};

} // end of isc::data namespace
} // end of isc namespace

#endif
