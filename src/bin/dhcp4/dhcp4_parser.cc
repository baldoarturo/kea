// A Bison parser, made by GNU Bison 3.7.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.


// Take the name prefix into account.
#define yylex   parser4_lex



#include "dhcp4_parser.h"


// Unqualified %code blocks.
#line 34 "dhcp4_parser.yy"

#include <dhcp4/parser_context.h>

// Avoid warnings with the error counter.
#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#line 57 "dhcp4_parser.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if PARSER4_DEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !PARSER4_DEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !PARSER4_DEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 14 "dhcp4_parser.yy"
namespace isc { namespace dhcp {
#line 150 "dhcp4_parser.cc"

  /// Build a parser object.
  Dhcp4Parser::Dhcp4Parser (isc::dhcp::Parser4Context& ctx_yyarg)
#if PARSER4_DEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      ctx (ctx_yyarg)
  {}

  Dhcp4Parser::~Dhcp4Parser ()
  {}

  Dhcp4Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/



  // by_state.
  Dhcp4Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Dhcp4Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Dhcp4Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Dhcp4Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Dhcp4Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Dhcp4Parser::symbol_kind_type
  Dhcp4Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Dhcp4Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Dhcp4Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_value: // value
      case symbol_kind::S_map_value: // map_value
      case symbol_kind::S_ddns_replace_client_name_value: // ddns_replace_client_name_value
      case symbol_kind::S_ddns_conflict_resolution_mode_value: // ddns_conflict_resolution_mode_value
      case symbol_kind::S_socket_type: // socket_type
      case symbol_kind::S_outbound_interface_value: // outbound_interface_value
      case symbol_kind::S_db_type: // db_type
      case symbol_kind::S_on_fail_mode: // on_fail_mode
      case symbol_kind::S_hr_mode: // hr_mode
      case symbol_kind::S_ncr_protocol_value: // ncr_protocol_value
        value.YY_MOVE_OR_COPY< ElementPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOLEAN: // "boolean"
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // "floating point"
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // "integer"
        value.YY_MOVE_OR_COPY< int64_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // "constant string"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Dhcp4Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_value: // value
      case symbol_kind::S_map_value: // map_value
      case symbol_kind::S_ddns_replace_client_name_value: // ddns_replace_client_name_value
      case symbol_kind::S_ddns_conflict_resolution_mode_value: // ddns_conflict_resolution_mode_value
      case symbol_kind::S_socket_type: // socket_type
      case symbol_kind::S_outbound_interface_value: // outbound_interface_value
      case symbol_kind::S_db_type: // db_type
      case symbol_kind::S_on_fail_mode: // on_fail_mode
      case symbol_kind::S_hr_mode: // hr_mode
      case symbol_kind::S_ncr_protocol_value: // ncr_protocol_value
        value.move< ElementPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOLEAN: // "boolean"
        value.move< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // "floating point"
        value.move< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // "integer"
        value.move< int64_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // "constant string"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Dhcp4Parser::stack_symbol_type&
  Dhcp4Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_value: // value
      case symbol_kind::S_map_value: // map_value
      case symbol_kind::S_ddns_replace_client_name_value: // ddns_replace_client_name_value
      case symbol_kind::S_ddns_conflict_resolution_mode_value: // ddns_conflict_resolution_mode_value
      case symbol_kind::S_socket_type: // socket_type
      case symbol_kind::S_outbound_interface_value: // outbound_interface_value
      case symbol_kind::S_db_type: // db_type
      case symbol_kind::S_on_fail_mode: // on_fail_mode
      case symbol_kind::S_hr_mode: // hr_mode
      case symbol_kind::S_ncr_protocol_value: // ncr_protocol_value
        value.copy< ElementPtr > (that.value);
        break;

      case symbol_kind::S_BOOLEAN: // "boolean"
        value.copy< bool > (that.value);
        break;

      case symbol_kind::S_FLOAT: // "floating point"
        value.copy< double > (that.value);
        break;

      case symbol_kind::S_INTEGER: // "integer"
        value.copy< int64_t > (that.value);
        break;

      case symbol_kind::S_STRING: // "constant string"
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  Dhcp4Parser::stack_symbol_type&
  Dhcp4Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_value: // value
      case symbol_kind::S_map_value: // map_value
      case symbol_kind::S_ddns_replace_client_name_value: // ddns_replace_client_name_value
      case symbol_kind::S_ddns_conflict_resolution_mode_value: // ddns_conflict_resolution_mode_value
      case symbol_kind::S_socket_type: // socket_type
      case symbol_kind::S_outbound_interface_value: // outbound_interface_value
      case symbol_kind::S_db_type: // db_type
      case symbol_kind::S_on_fail_mode: // on_fail_mode
      case symbol_kind::S_hr_mode: // hr_mode
      case symbol_kind::S_ncr_protocol_value: // ncr_protocol_value
        value.move< ElementPtr > (that.value);
        break;

      case symbol_kind::S_BOOLEAN: // "boolean"
        value.move< bool > (that.value);
        break;

      case symbol_kind::S_FLOAT: // "floating point"
        value.move< double > (that.value);
        break;

      case symbol_kind::S_INTEGER: // "integer"
        value.move< int64_t > (that.value);
        break;

      case symbol_kind::S_STRING: // "constant string"
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Dhcp4Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if PARSER4_DEBUG
  template <typename Base>
  void
  Dhcp4Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        switch (yykind)
    {
      case symbol_kind::S_STRING: // "constant string"
#line 309 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 417 "dhcp4_parser.cc"
        break;

      case symbol_kind::S_INTEGER: // "integer"
#line 309 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < int64_t > (); }
#line 423 "dhcp4_parser.cc"
        break;

      case symbol_kind::S_FLOAT: // "floating point"
#line 309 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < double > (); }
#line 429 "dhcp4_parser.cc"
        break;

      case symbol_kind::S_BOOLEAN: // "boolean"
#line 309 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < bool > (); }
#line 435 "dhcp4_parser.cc"
        break;

      case symbol_kind::S_value: // value
#line 309 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 441 "dhcp4_parser.cc"
        break;

      case symbol_kind::S_map_value: // map_value
#line 309 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 447 "dhcp4_parser.cc"
        break;

      case symbol_kind::S_ddns_replace_client_name_value: // ddns_replace_client_name_value
#line 309 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 453 "dhcp4_parser.cc"
        break;

      case symbol_kind::S_ddns_conflict_resolution_mode_value: // ddns_conflict_resolution_mode_value
#line 309 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 459 "dhcp4_parser.cc"
        break;

      case symbol_kind::S_socket_type: // socket_type
#line 309 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 465 "dhcp4_parser.cc"
        break;

      case symbol_kind::S_outbound_interface_value: // outbound_interface_value
#line 309 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 471 "dhcp4_parser.cc"
        break;

      case symbol_kind::S_db_type: // db_type
#line 309 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 477 "dhcp4_parser.cc"
        break;

      case symbol_kind::S_on_fail_mode: // on_fail_mode
#line 309 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 483 "dhcp4_parser.cc"
        break;

      case symbol_kind::S_hr_mode: // hr_mode
#line 309 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 489 "dhcp4_parser.cc"
        break;

      case symbol_kind::S_ncr_protocol_value: // ncr_protocol_value
#line 309 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 495 "dhcp4_parser.cc"
        break;

      default:
        break;
    }
        yyo << ')';
      }
  }
#endif

  void
  Dhcp4Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Dhcp4Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Dhcp4Parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if PARSER4_DEBUG
  std::ostream&
  Dhcp4Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Dhcp4Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Dhcp4Parser::debug_level_type
  Dhcp4Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Dhcp4Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // PARSER4_DEBUG

  Dhcp4Parser::state_type
  Dhcp4Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Dhcp4Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Dhcp4Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Dhcp4Parser::operator() ()
  {
    return parse ();
  }

  int
  Dhcp4Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (ctx));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_value: // value
      case symbol_kind::S_map_value: // map_value
      case symbol_kind::S_ddns_replace_client_name_value: // ddns_replace_client_name_value
      case symbol_kind::S_ddns_conflict_resolution_mode_value: // ddns_conflict_resolution_mode_value
      case symbol_kind::S_socket_type: // socket_type
      case symbol_kind::S_outbound_interface_value: // outbound_interface_value
      case symbol_kind::S_db_type: // db_type
      case symbol_kind::S_on_fail_mode: // on_fail_mode
      case symbol_kind::S_hr_mode: // hr_mode
      case symbol_kind::S_ncr_protocol_value: // ncr_protocol_value
        yylhs.value.emplace< ElementPtr > ();
        break;

      case symbol_kind::S_BOOLEAN: // "boolean"
        yylhs.value.emplace< bool > ();
        break;

      case symbol_kind::S_FLOAT: // "floating point"
        yylhs.value.emplace< double > ();
        break;

      case symbol_kind::S_INTEGER: // "integer"
        yylhs.value.emplace< int64_t > ();
        break;

      case symbol_kind::S_STRING: // "constant string"
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // $@1: %empty
#line 318 "dhcp4_parser.yy"
                     { ctx.ctx_ = ctx.NO_KEYWORD; }
#line 777 "dhcp4_parser.cc"
    break;

  case 4: // $@2: %empty
#line 319 "dhcp4_parser.yy"
                      { ctx.ctx_ = ctx.CONFIG; }
#line 783 "dhcp4_parser.cc"
    break;

  case 6: // $@3: %empty
#line 320 "dhcp4_parser.yy"
                 { ctx.ctx_ = ctx.DHCP4; }
#line 789 "dhcp4_parser.cc"
    break;

  case 8: // $@4: %empty
#line 321 "dhcp4_parser.yy"
                       { ctx.ctx_ = ctx.INTERFACES_CONFIG; }
#line 795 "dhcp4_parser.cc"
    break;

  case 10: // $@5: %empty
#line 322 "dhcp4_parser.yy"
                   { ctx.ctx_ = ctx.SUBNET4; }
#line 801 "dhcp4_parser.cc"
    break;

  case 12: // $@6: %empty
#line 323 "dhcp4_parser.yy"
                 { ctx.ctx_ = ctx.POOLS; }
#line 807 "dhcp4_parser.cc"
    break;

  case 14: // $@7: %empty
#line 324 "dhcp4_parser.yy"
                       { ctx.ctx_ = ctx.RESERVATIONS; }
#line 813 "dhcp4_parser.cc"
    break;

  case 16: // $@8: %empty
#line 325 "dhcp4_parser.yy"
                       { ctx.ctx_ = ctx.DHCP4; }
#line 819 "dhcp4_parser.cc"
    break;

  case 18: // $@9: %empty
#line 326 "dhcp4_parser.yy"
                      { ctx.ctx_ = ctx.OPTION_DEF; }
#line 825 "dhcp4_parser.cc"
    break;

  case 20: // $@10: %empty
#line 327 "dhcp4_parser.yy"
                       { ctx.ctx_ = ctx.OPTION_DATA; }
#line 831 "dhcp4_parser.cc"
    break;

  case 22: // $@11: %empty
#line 328 "dhcp4_parser.yy"
                         { ctx.ctx_ = ctx.HOOKS_LIBRARIES; }
#line 837 "dhcp4_parser.cc"
    break;

  case 24: // $@12: %empty
#line 329 "dhcp4_parser.yy"
                     { ctx.ctx_ = ctx.DHCP_DDNS; }
#line 843 "dhcp4_parser.cc"
    break;

  case 26: // $@13: %empty
#line 330 "dhcp4_parser.yy"
                          { ctx.ctx_ = ctx.CONFIG_CONTROL; }
#line 849 "dhcp4_parser.cc"
    break;

  case 28: // value: "integer"
#line 338 "dhcp4_parser.yy"
               { yylhs.value.as < ElementPtr > () = ElementPtr(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location))); }
#line 855 "dhcp4_parser.cc"
    break;

  case 29: // value: "floating point"
#line 339 "dhcp4_parser.yy"
             { yylhs.value.as < ElementPtr > () = ElementPtr(new DoubleElement(yystack_[0].value.as < double > (), ctx.loc2pos(yystack_[0].location))); }
#line 861 "dhcp4_parser.cc"
    break;

  case 30: // value: "boolean"
#line 340 "dhcp4_parser.yy"
               { yylhs.value.as < ElementPtr > () = ElementPtr(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location))); }
#line 867 "dhcp4_parser.cc"
    break;

  case 31: // value: "constant string"
#line 341 "dhcp4_parser.yy"
              { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location))); }
#line 873 "dhcp4_parser.cc"
    break;

  case 32: // value: "null"
#line 342 "dhcp4_parser.yy"
                 { yylhs.value.as < ElementPtr > () = ElementPtr(new NullElement(ctx.loc2pos(yystack_[0].location))); }
#line 879 "dhcp4_parser.cc"
    break;

  case 33: // value: map2
#line 343 "dhcp4_parser.yy"
            { yylhs.value.as < ElementPtr > () = ctx.stack_.back(); ctx.stack_.pop_back(); }
#line 885 "dhcp4_parser.cc"
    break;

  case 34: // value: list_generic
#line 344 "dhcp4_parser.yy"
                    { yylhs.value.as < ElementPtr > () = ctx.stack_.back(); ctx.stack_.pop_back(); }
#line 891 "dhcp4_parser.cc"
    break;

  case 35: // sub_json: value
#line 347 "dhcp4_parser.yy"
                {
    // Push back the JSON value on the stack
    ctx.stack_.push_back(yystack_[0].value.as < ElementPtr > ());
}
#line 900 "dhcp4_parser.cc"
    break;

  case 36: // $@14: %empty
#line 352 "dhcp4_parser.yy"
                     {
    // This code is executed when we're about to start parsing
    // the content of the map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 911 "dhcp4_parser.cc"
    break;

  case 37: // map2: "{" $@14 map_content "}"
#line 357 "dhcp4_parser.yy"
                             {
    // map parsing completed. If we ever want to do any wrap up
    // (maybe some sanity checking), this would be the best place
    // for it.
}
#line 921 "dhcp4_parser.cc"
    break;

  case 38: // map_value: map2
#line 363 "dhcp4_parser.yy"
                { yylhs.value.as < ElementPtr > () = ctx.stack_.back(); ctx.stack_.pop_back(); }
#line 927 "dhcp4_parser.cc"
    break;

  case 41: // not_empty_map: "constant string" ":" value
#line 370 "dhcp4_parser.yy"
                                  {
                  // map containing a single entry
                  ctx.unique(yystack_[2].value.as < std::string > (), ctx.loc2pos(yystack_[2].location));
                  ctx.stack_.back()->set(yystack_[2].value.as < std::string > (), yystack_[0].value.as < ElementPtr > ());
                  }
#line 937 "dhcp4_parser.cc"
    break;

  case 42: // not_empty_map: not_empty_map "," "constant string" ":" value
#line 375 "dhcp4_parser.yy"
                                                      {
                  // map consisting of a shorter map followed by
                  // comma and string:value
                  ctx.unique(yystack_[2].value.as < std::string > (), ctx.loc2pos(yystack_[2].location));
                  ctx.stack_.back()->set(yystack_[2].value.as < std::string > (), yystack_[0].value.as < ElementPtr > ());
                  }
#line 948 "dhcp4_parser.cc"
    break;

  case 43: // not_empty_map: not_empty_map ","
#line 381 "dhcp4_parser.yy"
                                   {
                 ctx.warnAboutExtraCommas(yystack_[0].location);
                 }
#line 956 "dhcp4_parser.cc"
    break;

  case 44: // $@15: %empty
#line 386 "dhcp4_parser.yy"
                              {
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(l);
}
#line 965 "dhcp4_parser.cc"
    break;

  case 45: // list_generic: "[" $@15 list_content "]"
#line 389 "dhcp4_parser.yy"
                               {
    // list parsing complete. Put any sanity checking here
}
#line 973 "dhcp4_parser.cc"
    break;

  case 48: // not_empty_list: value
#line 397 "dhcp4_parser.yy"
                      {
                  // List consisting of a single element.
                  ctx.stack_.back()->add(yystack_[0].value.as < ElementPtr > ());
                  }
#line 982 "dhcp4_parser.cc"
    break;

  case 49: // not_empty_list: not_empty_list "," value
#line 401 "dhcp4_parser.yy"
                                           {
                  // List ending with , and a value.
                  ctx.stack_.back()->add(yystack_[0].value.as < ElementPtr > ());
                  }
#line 991 "dhcp4_parser.cc"
    break;

  case 50: // not_empty_list: not_empty_list ","
#line 405 "dhcp4_parser.yy"
                                     {
                  ctx.warnAboutExtraCommas(yystack_[0].location);
                  }
#line 999 "dhcp4_parser.cc"
    break;

  case 51: // $@16: %empty
#line 411 "dhcp4_parser.yy"
                              {
    // List parsing about to start
}
#line 1007 "dhcp4_parser.cc"
    break;

  case 52: // list_strings: "[" $@16 list_strings_content "]"
#line 413 "dhcp4_parser.yy"
                                       {
    // list parsing complete. Put any sanity checking here
    //ctx.stack_.pop_back();
}
#line 1016 "dhcp4_parser.cc"
    break;

  case 55: // not_empty_list_strings: "constant string"
#line 422 "dhcp4_parser.yy"
                               {
                          ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
                          ctx.stack_.back()->add(s);
                          }
#line 1025 "dhcp4_parser.cc"
    break;

  case 56: // not_empty_list_strings: not_empty_list_strings "," "constant string"
#line 426 "dhcp4_parser.yy"
                                                            {
                          ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
                          ctx.stack_.back()->add(s);
                          }
#line 1034 "dhcp4_parser.cc"
    break;

  case 57: // not_empty_list_strings: not_empty_list_strings ","
#line 430 "dhcp4_parser.yy"
                                                     {
                          ctx.warnAboutExtraCommas(yystack_[0].location);
                          }
#line 1042 "dhcp4_parser.cc"
    break;

  case 58: // unknown_map_entry: "constant string" ":"
#line 440 "dhcp4_parser.yy"
                                {
    const std::string& where = ctx.contextName();
    const std::string& keyword = yystack_[1].value.as < std::string > ();
    error(yystack_[1].location,
          "got unexpected keyword \"" + keyword + "\" in " + where + " map.");
}
#line 1053 "dhcp4_parser.cc"
    break;

  case 59: // $@17: %empty
#line 449 "dhcp4_parser.yy"
                           {
    // This code is executed when we're about to start parsing
    // the content of the map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 1064 "dhcp4_parser.cc"
    break;

  case 60: // syntax_map: "{" $@17 global_object "}"
#line 454 "dhcp4_parser.yy"
                               {
    // map parsing completed. If we ever want to do any wrap up
    // (maybe some sanity checking), this would be the best place
    // for it.

    // Dhcp4 is required
    ctx.require("Dhcp4", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
}
#line 1077 "dhcp4_parser.cc"
    break;

  case 61: // $@18: %empty
#line 464 "dhcp4_parser.yy"
                     {
    // This code is executed when we're about to start parsing
    // the content of the map
    // Prevent against duplicate.
    ctx.unique("Dhcp4", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("Dhcp4", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.DHCP4);
}
#line 1092 "dhcp4_parser.cc"
    break;

  case 62: // global_object: "Dhcp4" $@18 ":" "{" global_params "}"
#line 473 "dhcp4_parser.yy"
                                                    {
    // No global parameter is required
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1102 "dhcp4_parser.cc"
    break;

  case 64: // global_object_comma: global_object ","
#line 481 "dhcp4_parser.yy"
                                         {
    ctx.warnAboutExtraCommas(yystack_[0].location);
}
#line 1110 "dhcp4_parser.cc"
    break;

  case 65: // $@19: %empty
#line 487 "dhcp4_parser.yy"
                          {
    // Parse the Dhcp4 map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 1120 "dhcp4_parser.cc"
    break;

  case 66: // sub_dhcp4: "{" $@19 global_params "}"
#line 491 "dhcp4_parser.yy"
                               {
    // No global parameter is required
    // parsing completed
}
#line 1129 "dhcp4_parser.cc"
    break;

  case 69: // global_params: global_params ","
#line 498 "dhcp4_parser.yy"
                                   {
                 ctx.warnAboutExtraCommas(yystack_[0].location);
                 }
#line 1137 "dhcp4_parser.cc"
    break;

  case 138: // valid_lifetime: "valid-lifetime" ":" "integer"
#line 575 "dhcp4_parser.yy"
                                             {
    ctx.unique("valid-lifetime", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("valid-lifetime", prf);
}
#line 1147 "dhcp4_parser.cc"
    break;

  case 139: // min_valid_lifetime: "min-valid-lifetime" ":" "integer"
#line 581 "dhcp4_parser.yy"
                                                     {
    ctx.unique("min-valid-lifetime", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("min-valid-lifetime", prf);
}
#line 1157 "dhcp4_parser.cc"
    break;

  case 140: // max_valid_lifetime: "max-valid-lifetime" ":" "integer"
#line 587 "dhcp4_parser.yy"
                                                     {
    ctx.unique("max-valid-lifetime", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-valid-lifetime", prf);
}
#line 1167 "dhcp4_parser.cc"
    break;

  case 141: // renew_timer: "renew-timer" ":" "integer"
#line 593 "dhcp4_parser.yy"
                                       {
    ctx.unique("renew-timer", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("renew-timer", prf);
}
#line 1177 "dhcp4_parser.cc"
    break;

  case 142: // rebind_timer: "rebind-timer" ":" "integer"
#line 599 "dhcp4_parser.yy"
                                         {
    ctx.unique("rebind-timer", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("rebind-timer", prf);
}
#line 1187 "dhcp4_parser.cc"
    break;

  case 143: // calculate_tee_times: "calculate-tee-times" ":" "boolean"
#line 605 "dhcp4_parser.yy"
                                                       {
    ctx.unique("calculate-tee-times", ctx.loc2pos(yystack_[2].location));
    ElementPtr ctt(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("calculate-tee-times", ctt);
}
#line 1197 "dhcp4_parser.cc"
    break;

  case 144: // t1_percent: "t1-percent" ":" "floating point"
#line 611 "dhcp4_parser.yy"
                                   {
    ctx.unique("t1-percent", ctx.loc2pos(yystack_[2].location));
    ElementPtr t1(new DoubleElement(yystack_[0].value.as < double > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("t1-percent", t1);
}
#line 1207 "dhcp4_parser.cc"
    break;

  case 145: // t2_percent: "t2-percent" ":" "floating point"
#line 617 "dhcp4_parser.yy"
                                   {
    ctx.unique("t2-percent", ctx.loc2pos(yystack_[2].location));
    ElementPtr t2(new DoubleElement(yystack_[0].value.as < double > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("t2-percent", t2);
}
#line 1217 "dhcp4_parser.cc"
    break;

  case 146: // cache_threshold: "cache-threshold" ":" "floating point"
#line 623 "dhcp4_parser.yy"
                                             {
    ctx.unique("cache-threshold", ctx.loc2pos(yystack_[2].location));
    ElementPtr ct(new DoubleElement(yystack_[0].value.as < double > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("cache-threshold", ct);
}
#line 1227 "dhcp4_parser.cc"
    break;

  case 147: // cache_max_age: "cache-max-age" ":" "integer"
#line 629 "dhcp4_parser.yy"
                                           {
    ctx.unique("cache-max-age", ctx.loc2pos(yystack_[2].location));
    ElementPtr cm(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("cache-max-age", cm);
}
#line 1237 "dhcp4_parser.cc"
    break;

  case 148: // decline_probation_period: "decline-probation-period" ":" "integer"
#line 635 "dhcp4_parser.yy"
                                                                 {
    ctx.unique("decline-probation-period", ctx.loc2pos(yystack_[2].location));
    ElementPtr dpp(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("decline-probation-period", dpp);
}
#line 1247 "dhcp4_parser.cc"
    break;

  case 149: // $@20: %empty
#line 641 "dhcp4_parser.yy"
                       {
    ctx.unique("server-tag", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1256 "dhcp4_parser.cc"
    break;

  case 150: // server_tag: "server-tag" $@20 ":" "constant string"
#line 644 "dhcp4_parser.yy"
               {
    ElementPtr stag(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("server-tag", stag);
    ctx.leave();
}
#line 1266 "dhcp4_parser.cc"
    break;

  case 151: // parked_packet_limit: "parked-packet-limit" ":" "integer"
#line 650 "dhcp4_parser.yy"
                                                       {
    ctx.unique("parked-packet-limit", ctx.loc2pos(yystack_[2].location));
    ElementPtr ppl(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("parked-packet-limit", ppl);
}
#line 1276 "dhcp4_parser.cc"
    break;

  case 152: // $@21: %empty
#line 656 "dhcp4_parser.yy"
                     {
    ctx.unique("allocator", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1285 "dhcp4_parser.cc"
    break;

  case 153: // allocator: "allocator" $@21 ":" "constant string"
#line 659 "dhcp4_parser.yy"
               {
    ElementPtr al(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("allocator", al);
    ctx.leave();
}
#line 1295 "dhcp4_parser.cc"
    break;

  case 154: // echo_client_id: "echo-client-id" ":" "boolean"
#line 665 "dhcp4_parser.yy"
                                             {
    ctx.unique("echo-client-id", ctx.loc2pos(yystack_[2].location));
    ElementPtr echo(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("echo-client-id", echo);
}
#line 1305 "dhcp4_parser.cc"
    break;

  case 155: // match_client_id: "match-client-id" ":" "boolean"
#line 671 "dhcp4_parser.yy"
                                               {
    ctx.unique("match-client-id", ctx.loc2pos(yystack_[2].location));
    ElementPtr match(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("match-client-id", match);
}
#line 1315 "dhcp4_parser.cc"
    break;

  case 156: // authoritative: "authoritative" ":" "boolean"
#line 677 "dhcp4_parser.yy"
                                           {
    ctx.unique("authoritative", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("authoritative", prf);
}
#line 1325 "dhcp4_parser.cc"
    break;

  case 157: // ddns_send_updates: "ddns-send-updates" ":" "boolean"
#line 683 "dhcp4_parser.yy"
                                                   {
    ctx.unique("ddns-send-updates", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-send-updates", b);
}
#line 1335 "dhcp4_parser.cc"
    break;

  case 158: // ddns_override_no_update: "ddns-override-no-update" ":" "boolean"
#line 689 "dhcp4_parser.yy"
                                                               {
    ctx.unique("ddns-override-no-update", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-override-no-update", b);
}
#line 1345 "dhcp4_parser.cc"
    break;

  case 159: // ddns_override_client_update: "ddns-override-client-update" ":" "boolean"
#line 695 "dhcp4_parser.yy"
                                                                       {
    ctx.unique("ddns-override-client-update", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-override-client-update", b);
}
#line 1355 "dhcp4_parser.cc"
    break;

  case 160: // $@22: %empty
#line 701 "dhcp4_parser.yy"
                                                   {
    ctx.enter(ctx.REPLACE_CLIENT_NAME);
    ctx.unique("ddns-replace-client-name", ctx.loc2pos(yystack_[0].location));
}
#line 1364 "dhcp4_parser.cc"
    break;

  case 161: // ddns_replace_client_name: "ddns-replace-client-name" $@22 ":" ddns_replace_client_name_value
#line 704 "dhcp4_parser.yy"
                                       {
    ctx.stack_.back()->set("ddns-replace-client-name", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 1373 "dhcp4_parser.cc"
    break;

  case 162: // ddns_replace_client_name_value: "when-present"
#line 710 "dhcp4_parser.yy"
                 {
      yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("when-present", ctx.loc2pos(yystack_[0].location)));
      }
#line 1381 "dhcp4_parser.cc"
    break;

  case 163: // ddns_replace_client_name_value: "never"
#line 713 "dhcp4_parser.yy"
          {
      yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("never", ctx.loc2pos(yystack_[0].location)));
      }
#line 1389 "dhcp4_parser.cc"
    break;

  case 164: // ddns_replace_client_name_value: "always"
#line 716 "dhcp4_parser.yy"
           {
      yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("always", ctx.loc2pos(yystack_[0].location)));
      }
#line 1397 "dhcp4_parser.cc"
    break;

  case 165: // ddns_replace_client_name_value: "when-not-present"
#line 719 "dhcp4_parser.yy"
                     {
      yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("when-not-present", ctx.loc2pos(yystack_[0].location)));
      }
#line 1405 "dhcp4_parser.cc"
    break;

  case 166: // ddns_replace_client_name_value: "boolean"
#line 722 "dhcp4_parser.yy"
            {
      error(yystack_[0].location, "boolean values for the replace-client-name are "
                "no longer supported");
      }
#line 1414 "dhcp4_parser.cc"
    break;

  case 167: // $@23: %empty
#line 728 "dhcp4_parser.yy"
                                             {
    ctx.unique("ddns-generated-prefix", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1423 "dhcp4_parser.cc"
    break;

  case 168: // ddns_generated_prefix: "ddns-generated-prefix" $@23 ":" "constant string"
#line 731 "dhcp4_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-generated-prefix", s);
    ctx.leave();
}
#line 1433 "dhcp4_parser.cc"
    break;

  case 169: // $@24: %empty
#line 737 "dhcp4_parser.yy"
                                               {
    ctx.unique("ddns-qualifying-suffix", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1442 "dhcp4_parser.cc"
    break;

  case 170: // ddns_qualifying_suffix: "ddns-qualifying-suffix" $@24 ":" "constant string"
#line 740 "dhcp4_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-qualifying-suffix", s);
    ctx.leave();
}
#line 1452 "dhcp4_parser.cc"
    break;

  case 171: // ddns_update_on_renew: "ddns-update-on-renew" ":" "boolean"
#line 746 "dhcp4_parser.yy"
                                                         {
    ctx.unique("ddns-update-on-renew", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-update-on-renew", b);
}
#line 1462 "dhcp4_parser.cc"
    break;

  case 172: // ddns_use_conflict_resolution: "ddns-use-conflict-resolution" ":" "boolean"
#line 752 "dhcp4_parser.yy"
                                                                         {
    ctx.unique("ddns-use-conflict-resolution", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-use-conflict-resolution", b);
}
#line 1472 "dhcp4_parser.cc"
    break;

  case 173: // $@25: %empty
#line 758 "dhcp4_parser.yy"
                                                             {
    ctx.unique("ddns-conflict-resolution-mode", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.DDNS_CONFLICT_RESOLUTION_MODE);
}
#line 1481 "dhcp4_parser.cc"
    break;

  case 174: // ddns_conflict_resolution_mode: "ddns-conflict-resolution-mode" $@25 ":" ddns_conflict_resolution_mode_value
#line 761 "dhcp4_parser.yy"
                                            {
    ctx.stack_.back()->set("ddns-conflict-resolution-mode", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 1490 "dhcp4_parser.cc"
    break;

  case 175: // ddns_conflict_resolution_mode_value: "check-with-dhcid"
#line 767 "dhcp4_parser.yy"
                     {
      yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("check-with-dhcid", ctx.loc2pos(yystack_[0].location)));
      }
#line 1498 "dhcp4_parser.cc"
    break;

  case 176: // ddns_conflict_resolution_mode_value: "no-check-with-dhcid"
#line 770 "dhcp4_parser.yy"
                        {
      yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("no-check-with-dhcid", ctx.loc2pos(yystack_[0].location)));
      }
#line 1506 "dhcp4_parser.cc"
    break;

  case 177: // ddns_conflict_resolution_mode_value: "check-exists-with-dhcid"
#line 773 "dhcp4_parser.yy"
                            {
      yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("check-exists-with-dhcid", ctx.loc2pos(yystack_[0].location)));
      }
#line 1514 "dhcp4_parser.cc"
    break;

  case 178: // ddns_conflict_resolution_mode_value: "no-check-without-dhcid"
#line 776 "dhcp4_parser.yy"
                           {
      yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("no-check-without-dhcid", ctx.loc2pos(yystack_[0].location)));
      }
#line 1522 "dhcp4_parser.cc"
    break;

  case 179: // ddns_ttl_percent: "ddns-ttl-percent" ":" "floating point"
#line 781 "dhcp4_parser.yy"
                                               {
    ctx.unique("ddns-ttl-percent", ctx.loc2pos(yystack_[2].location));
    ElementPtr ttl(new DoubleElement(yystack_[0].value.as < double > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-ttl-percent", ttl);
}
#line 1532 "dhcp4_parser.cc"
    break;

  case 180: // $@26: %empty
#line 787 "dhcp4_parser.yy"
                                     {
    ctx.unique("hostname-char-set", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1541 "dhcp4_parser.cc"
    break;

  case 181: // hostname_char_set: "hostname-char-set" $@26 ":" "constant string"
#line 790 "dhcp4_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hostname-char-set", s);
    ctx.leave();
}
#line 1551 "dhcp4_parser.cc"
    break;

  case 182: // $@27: %empty
#line 796 "dhcp4_parser.yy"
                                                     {
    ctx.unique("hostname-char-replacement", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1560 "dhcp4_parser.cc"
    break;

  case 183: // hostname_char_replacement: "hostname-char-replacement" $@27 ":" "constant string"
#line 799 "dhcp4_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hostname-char-replacement", s);
    ctx.leave();
}
#line 1570 "dhcp4_parser.cc"
    break;

  case 184: // store_extended_info: "store-extended-info" ":" "boolean"
#line 805 "dhcp4_parser.yy"
                                                       {
    ctx.unique("store-extended-info", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("store-extended-info", b);
}
#line 1580 "dhcp4_parser.cc"
    break;

  case 185: // statistic_default_sample_count: "statistic-default-sample-count" ":" "integer"
#line 811 "dhcp4_parser.yy"
                                                                             {
    ctx.unique("statistic-default-sample-count", ctx.loc2pos(yystack_[2].location));
    ElementPtr count(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("statistic-default-sample-count", count);
}
#line 1590 "dhcp4_parser.cc"
    break;

  case 186: // statistic_default_sample_age: "statistic-default-sample-age" ":" "integer"
#line 817 "dhcp4_parser.yy"
                                                                         {
    ctx.unique("statistic-default-sample-age", ctx.loc2pos(yystack_[2].location));
    ElementPtr age(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("statistic-default-sample-age", age);
}
#line 1600 "dhcp4_parser.cc"
    break;

  case 187: // early_global_reservations_lookup: "early-global-reservations-lookup" ":" "boolean"
#line 823 "dhcp4_parser.yy"
                                                                                 {
    ctx.unique("early-global-reservations-lookup", ctx.loc2pos(yystack_[2].location));
    ElementPtr early(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("early-global-reservations-lookup", early);
}
#line 1610 "dhcp4_parser.cc"
    break;

  case 188: // ip_reservations_unique: "ip-reservations-unique" ":" "boolean"
#line 829 "dhcp4_parser.yy"
                                                             {
    ctx.unique("ip-reservations-unique", ctx.loc2pos(yystack_[2].location));
    ElementPtr unique(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ip-reservations-unique", unique);
}
#line 1620 "dhcp4_parser.cc"
    break;

  case 189: // reservations_lookup_first: "reservations-lookup-first" ":" "boolean"
#line 835 "dhcp4_parser.yy"
                                                                   {
    ctx.unique("reservations-lookup-first", ctx.loc2pos(yystack_[2].location));
    ElementPtr first(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reservations-lookup-first", first);
}
#line 1630 "dhcp4_parser.cc"
    break;

  case 190: // offer_lifetime: "offer-lifetime" ":" "integer"
#line 841 "dhcp4_parser.yy"
                                        {
    ctx.unique("offer-lifetime", ctx.loc2pos(yystack_[2].location));
    ElementPtr offer_lifetime(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("offer-lifetime", offer_lifetime);
}
#line 1640 "dhcp4_parser.cc"
    break;

  case 191: // $@28: %empty
#line 847 "dhcp4_parser.yy"
                                     {
    ctx.unique("interfaces-config", ctx.loc2pos(yystack_[0].location));
    ElementPtr i(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("interfaces-config", i);
    ctx.stack_.push_back(i);
    ctx.enter(ctx.INTERFACES_CONFIG);
}
#line 1652 "dhcp4_parser.cc"
    break;

  case 192: // interfaces_config: "interfaces-config" $@28 ":" "{" interfaces_config_params "}"
#line 853 "dhcp4_parser.yy"
                                                               {
    // No interfaces config param is required
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1662 "dhcp4_parser.cc"
    break;

  case 195: // interfaces_config_params: interfaces_config_params ","
#line 861 "dhcp4_parser.yy"
                                                         {
                            ctx.warnAboutExtraCommas(yystack_[0].location);
                            }
#line 1670 "dhcp4_parser.cc"
    break;

  case 206: // $@29: %empty
#line 878 "dhcp4_parser.yy"
                                {
    // Parse the interfaces-config map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 1680 "dhcp4_parser.cc"
    break;

  case 207: // sub_interfaces4: "{" $@29 interfaces_config_params "}"
#line 882 "dhcp4_parser.yy"
                                          {
    // No interfaces config param is required
    // parsing completed
}
#line 1689 "dhcp4_parser.cc"
    break;

  case 208: // $@30: %empty
#line 887 "dhcp4_parser.yy"
                            {
    ctx.unique("interfaces", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("interfaces", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1701 "dhcp4_parser.cc"
    break;

  case 209: // interfaces_list: "interfaces" $@30 ":" list_strings
#line 893 "dhcp4_parser.yy"
                     {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1710 "dhcp4_parser.cc"
    break;

  case 210: // $@31: %empty
#line 898 "dhcp4_parser.yy"
                                   {
    ctx.unique("dhcp-socket-type", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.DHCP_SOCKET_TYPE);
}
#line 1719 "dhcp4_parser.cc"
    break;

  case 211: // dhcp_socket_type: "dhcp-socket-type" $@31 ":" socket_type
#line 901 "dhcp4_parser.yy"
                    {
    ctx.stack_.back()->set("dhcp-socket-type", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 1728 "dhcp4_parser.cc"
    break;

  case 212: // socket_type: "raw"
#line 906 "dhcp4_parser.yy"
                 { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("raw", ctx.loc2pos(yystack_[0].location))); }
#line 1734 "dhcp4_parser.cc"
    break;

  case 213: // socket_type: "udp"
#line 907 "dhcp4_parser.yy"
                 { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("udp", ctx.loc2pos(yystack_[0].location))); }
#line 1740 "dhcp4_parser.cc"
    break;

  case 214: // $@32: %empty
#line 910 "dhcp4_parser.yy"
                                       {
    ctx.unique("outbound-interface", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.OUTBOUND_INTERFACE);
}
#line 1749 "dhcp4_parser.cc"
    break;

  case 215: // outbound_interface: "outbound-interface" $@32 ":" outbound_interface_value
#line 913 "dhcp4_parser.yy"
                                 {
    ctx.stack_.back()->set("outbound-interface", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 1758 "dhcp4_parser.cc"
    break;

  case 216: // outbound_interface_value: "same-as-inbound"
#line 918 "dhcp4_parser.yy"
                                          {
    yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("same-as-inbound", ctx.loc2pos(yystack_[0].location)));
}
#line 1766 "dhcp4_parser.cc"
    break;

  case 217: // outbound_interface_value: "use-routing"
#line 920 "dhcp4_parser.yy"
                {
    yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("use-routing", ctx.loc2pos(yystack_[0].location)));
    }
#line 1774 "dhcp4_parser.cc"
    break;

  case 218: // re_detect: "re-detect" ":" "boolean"
#line 924 "dhcp4_parser.yy"
                                   {
    ctx.unique("re-detect", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("re-detect", b);
}
#line 1784 "dhcp4_parser.cc"
    break;

  case 219: // service_sockets_require_all: "service-sockets-require-all" ":" "boolean"
#line 930 "dhcp4_parser.yy"
                                                                       {
    ctx.unique("service-sockets-require-all", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("service-sockets-require-all", b);
}
#line 1794 "dhcp4_parser.cc"
    break;

  case 220: // service_sockets_retry_wait_time: "service-sockets-retry-wait-time" ":" "integer"
#line 936 "dhcp4_parser.yy"
                                                                               {
    ctx.unique("service-sockets-retry-wait-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("service-sockets-retry-wait-time", n);
}
#line 1804 "dhcp4_parser.cc"
    break;

  case 221: // service_sockets_max_retries: "service-sockets-max-retries" ":" "integer"
#line 942 "dhcp4_parser.yy"
                                                                       {
    ctx.unique("service-sockets-max-retries", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("service-sockets-max-retries", n);
}
#line 1814 "dhcp4_parser.cc"
    break;

  case 222: // $@33: %empty
#line 948 "dhcp4_parser.yy"
                               {
    ctx.unique("lease-database", ctx.loc2pos(yystack_[0].location));
    ElementPtr i(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("lease-database", i);
    ctx.stack_.push_back(i);
    ctx.enter(ctx.LEASE_DATABASE);
}
#line 1826 "dhcp4_parser.cc"
    break;

  case 223: // lease_database: "lease-database" $@33 ":" "{" database_map_params "}"
#line 954 "dhcp4_parser.yy"
                                                          {
    // The type parameter is required
    ctx.require("type", ctx.loc2pos(yystack_[2].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1837 "dhcp4_parser.cc"
    break;

  case 224: // $@34: %empty
#line 961 "dhcp4_parser.yy"
                             {
    ctx.unique("sanity-checks", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("sanity-checks", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.SANITY_CHECKS);
}
#line 1849 "dhcp4_parser.cc"
    break;

  case 225: // sanity_checks: "sanity-checks" $@34 ":" "{" sanity_checks_params "}"
#line 967 "dhcp4_parser.yy"
                                                           {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1858 "dhcp4_parser.cc"
    break;

  case 228: // sanity_checks_params: sanity_checks_params ","
#line 974 "dhcp4_parser.yy"
                                                 {
                        ctx.warnAboutExtraCommas(yystack_[0].location);
                        }
#line 1866 "dhcp4_parser.cc"
    break;

  case 231: // $@35: %empty
#line 983 "dhcp4_parser.yy"
                           {
    ctx.unique("lease-checks", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1875 "dhcp4_parser.cc"
    break;

  case 232: // lease_checks: "lease-checks" $@35 ":" "constant string"
#line 986 "dhcp4_parser.yy"
               {

    if ( (string(yystack_[0].value.as < std::string > ()) == "none") ||
         (string(yystack_[0].value.as < std::string > ()) == "warn") ||
         (string(yystack_[0].value.as < std::string > ()) == "fix") ||
         (string(yystack_[0].value.as < std::string > ()) == "fix-del") ||
         (string(yystack_[0].value.as < std::string > ()) == "del")) {
        ElementPtr user(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
        ctx.stack_.back()->set("lease-checks", user);
        ctx.leave();
    } else {
        error(yystack_[0].location, "Unsupported 'lease-checks value: " + string(yystack_[0].value.as < std::string > ()) +
              ", supported values are: none, warn, fix, fix-del, del");
    }
}
#line 1895 "dhcp4_parser.cc"
    break;

  case 233: // $@36: %empty
#line 1002 "dhcp4_parser.yy"
                                           {
    ctx.unique("extended-info-checks", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1904 "dhcp4_parser.cc"
    break;

  case 234: // extended_info_checks: "extended-info-checks" $@36 ":" "constant string"
#line 1005 "dhcp4_parser.yy"
               {

    if ( (string(yystack_[0].value.as < std::string > ()) == "none") ||
         (string(yystack_[0].value.as < std::string > ()) == "fix") ||
         (string(yystack_[0].value.as < std::string > ()) == "strict") ||
         (string(yystack_[0].value.as < std::string > ()) == "pedantic")) {
        ElementPtr user(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
        ctx.stack_.back()->set("extended-info-checks", user);
        ctx.leave();
    } else {
        error(yystack_[0].location, "Unsupported 'extended-info-checks value: " + string(yystack_[0].value.as < std::string > ()) +
              ", supported values are: none, fix, strict, pedantic");
    }
}
#line 1923 "dhcp4_parser.cc"
    break;

  case 235: // $@37: %empty
#line 1020 "dhcp4_parser.yy"
                               {
    ctx.unique("hosts-database", ctx.loc2pos(yystack_[0].location));
    ElementPtr i(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hosts-database", i);
    ctx.stack_.push_back(i);
    ctx.enter(ctx.HOSTS_DATABASE);
}
#line 1935 "dhcp4_parser.cc"
    break;

  case 236: // hosts_database: "hosts-database" $@37 ":" "{" database_map_params "}"
#line 1026 "dhcp4_parser.yy"
                                                          {
    // The type parameter is required
    ctx.require("type", ctx.loc2pos(yystack_[2].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1946 "dhcp4_parser.cc"
    break;

  case 237: // $@38: %empty
#line 1033 "dhcp4_parser.yy"
                                 {
    ctx.unique("hosts-databases", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hosts-databases", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.HOSTS_DATABASE);
}
#line 1958 "dhcp4_parser.cc"
    break;

  case 238: // hosts_databases: "hosts-databases" $@38 ":" "[" database_list "]"
#line 1039 "dhcp4_parser.yy"
                                                      {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1967 "dhcp4_parser.cc"
    break;

  case 243: // not_empty_database_list: not_empty_database_list ","
#line 1050 "dhcp4_parser.yy"
                                                       {
                           ctx.warnAboutExtraCommas(yystack_[0].location);
                           }
#line 1975 "dhcp4_parser.cc"
    break;

  case 244: // $@39: %empty
#line 1055 "dhcp4_parser.yy"
                         {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 1985 "dhcp4_parser.cc"
    break;

  case 245: // database: "{" $@39 database_map_params "}"
#line 1059 "dhcp4_parser.yy"
                                     {
    // The type parameter is required
    ctx.require("type", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 1995 "dhcp4_parser.cc"
    break;

  case 248: // database_map_params: database_map_params ","
#line 1067 "dhcp4_parser.yy"
                                               {
                       ctx.warnAboutExtraCommas(yystack_[0].location);
                       }
#line 2003 "dhcp4_parser.cc"
    break;

  case 271: // $@40: %empty
#line 1096 "dhcp4_parser.yy"
                    {
    ctx.unique("type", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.DATABASE_TYPE);
}
#line 2012 "dhcp4_parser.cc"
    break;

  case 272: // database_type: "type" $@40 ":" db_type
#line 1099 "dhcp4_parser.yy"
                {
    ctx.stack_.back()->set("type", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 2021 "dhcp4_parser.cc"
    break;

  case 273: // db_type: "memfile"
#line 1104 "dhcp4_parser.yy"
                 { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("memfile", ctx.loc2pos(yystack_[0].location))); }
#line 2027 "dhcp4_parser.cc"
    break;

  case 274: // db_type: "mysql"
#line 1105 "dhcp4_parser.yy"
               { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("mysql", ctx.loc2pos(yystack_[0].location))); }
#line 2033 "dhcp4_parser.cc"
    break;

  case 275: // db_type: "postgresql"
#line 1106 "dhcp4_parser.yy"
                    { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("postgresql", ctx.loc2pos(yystack_[0].location))); }
#line 2039 "dhcp4_parser.cc"
    break;

  case 276: // $@41: %empty
#line 1109 "dhcp4_parser.yy"
           {
    ctx.unique("user", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2048 "dhcp4_parser.cc"
    break;

  case 277: // user: "user" $@41 ":" "constant string"
#line 1112 "dhcp4_parser.yy"
               {
    ElementPtr user(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("user", user);
    ctx.leave();
}
#line 2058 "dhcp4_parser.cc"
    break;

  case 278: // $@42: %empty
#line 1118 "dhcp4_parser.yy"
                   {
    ctx.unique("password", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2067 "dhcp4_parser.cc"
    break;

  case 279: // password: "password" $@42 ":" "constant string"
#line 1121 "dhcp4_parser.yy"
               {
    ElementPtr pwd(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("password", pwd);
    ctx.leave();
}
#line 2077 "dhcp4_parser.cc"
    break;

  case 280: // $@43: %empty
#line 1127 "dhcp4_parser.yy"
           {
    ctx.unique("host", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2086 "dhcp4_parser.cc"
    break;

  case 281: // host: "host" $@43 ":" "constant string"
#line 1130 "dhcp4_parser.yy"
               {
    ElementPtr h(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("host", h);
    ctx.leave();
}
#line 2096 "dhcp4_parser.cc"
    break;

  case 282: // port: "port" ":" "integer"
#line 1136 "dhcp4_parser.yy"
                         {
    ctx.unique("port", ctx.loc2pos(yystack_[2].location));
    ElementPtr p(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("port", p);
}
#line 2106 "dhcp4_parser.cc"
    break;

  case 283: // $@44: %empty
#line 1142 "dhcp4_parser.yy"
           {
    ctx.unique("name", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2115 "dhcp4_parser.cc"
    break;

  case 284: // name: "name" $@44 ":" "constant string"
#line 1145 "dhcp4_parser.yy"
               {
    ElementPtr name(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("name", name);
    ctx.leave();
}
#line 2125 "dhcp4_parser.cc"
    break;

  case 285: // persist: "persist" ":" "boolean"
#line 1151 "dhcp4_parser.yy"
                               {
    ctx.unique("persist", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("persist", n);
}
#line 2135 "dhcp4_parser.cc"
    break;

  case 286: // lfc_interval: "lfc-interval" ":" "integer"
#line 1157 "dhcp4_parser.yy"
                                         {
    ctx.unique("lfc-interval", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("lfc-interval", n);
}
#line 2145 "dhcp4_parser.cc"
    break;

  case 287: // readonly: "readonly" ":" "boolean"
#line 1163 "dhcp4_parser.yy"
                                 {
    ctx.unique("readonly", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("readonly", n);
}
#line 2155 "dhcp4_parser.cc"
    break;

  case 288: // connect_timeout: "connect-timeout" ":" "integer"
#line 1169 "dhcp4_parser.yy"
                                               {
    ctx.unique("connect-timeout", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("connect-timeout", n);
}
#line 2165 "dhcp4_parser.cc"
    break;

  case 289: // read_timeout: "read-timeout" ":" "integer"
#line 1175 "dhcp4_parser.yy"
                                         {
    ctx.unique("read-timeout", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("read-timeout", n);
}
#line 2175 "dhcp4_parser.cc"
    break;

  case 290: // write_timeout: "write-timeout" ":" "integer"
#line 1181 "dhcp4_parser.yy"
                                           {
    ctx.unique("write-timeout", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("write-timeout", n);
}
#line 2185 "dhcp4_parser.cc"
    break;

  case 291: // tcp_user_timeout: "tcp-user-timeout" ":" "integer"
#line 1187 "dhcp4_parser.yy"
                                                 {
    ctx.unique("tcp-user-timeout", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("tcp-user-timeout", n);
}
#line 2195 "dhcp4_parser.cc"
    break;

  case 292: // max_reconnect_tries: "max-reconnect-tries" ":" "integer"
#line 1193 "dhcp4_parser.yy"
                                                       {
    ctx.unique("max-reconnect-tries", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-reconnect-tries", n);
}
#line 2205 "dhcp4_parser.cc"
    break;

  case 293: // reconnect_wait_time: "reconnect-wait-time" ":" "integer"
#line 1199 "dhcp4_parser.yy"
                                                       {
    ctx.unique("reconnect-wait-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reconnect-wait-time", n);
}
#line 2215 "dhcp4_parser.cc"
    break;

  case 294: // $@45: %empty
#line 1205 "dhcp4_parser.yy"
                 {
    ctx.unique("on-fail", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.DATABASE_ON_FAIL);
}
#line 2224 "dhcp4_parser.cc"
    break;

  case 295: // on_fail: "on-fail" $@45 ":" on_fail_mode
#line 1208 "dhcp4_parser.yy"
                     {
    ctx.stack_.back()->set("on-fail", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 2233 "dhcp4_parser.cc"
    break;

  case 296: // on_fail_mode: "stop-retry-exit"
#line 1213 "dhcp4_parser.yy"
                              { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("stop-retry-exit", ctx.loc2pos(yystack_[0].location))); }
#line 2239 "dhcp4_parser.cc"
    break;

  case 297: // on_fail_mode: "serve-retry-exit"
#line 1214 "dhcp4_parser.yy"
                               { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("serve-retry-exit", ctx.loc2pos(yystack_[0].location))); }
#line 2245 "dhcp4_parser.cc"
    break;

  case 298: // on_fail_mode: "serve-retry-continue"
#line 1215 "dhcp4_parser.yy"
                                   { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("serve-retry-continue", ctx.loc2pos(yystack_[0].location))); }
#line 2251 "dhcp4_parser.cc"
    break;

  case 299: // max_row_errors: "max-row-errors" ":" "integer"
#line 1218 "dhcp4_parser.yy"
                                             {
    ctx.unique("max-row-errors", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-row-errors", n);
}
#line 2261 "dhcp4_parser.cc"
    break;

  case 300: // $@46: %empty
#line 1224 "dhcp4_parser.yy"
                           {
    ctx.unique("trust-anchor", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2270 "dhcp4_parser.cc"
    break;

  case 301: // trust_anchor: "trust-anchor" $@46 ":" "constant string"
#line 1227 "dhcp4_parser.yy"
               {
    ElementPtr ca(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("trust-anchor", ca);
    ctx.leave();
}
#line 2280 "dhcp4_parser.cc"
    break;

  case 302: // $@47: %empty
#line 1233 "dhcp4_parser.yy"
                     {
    ctx.unique("cert-file", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2289 "dhcp4_parser.cc"
    break;

  case 303: // cert_file: "cert-file" $@47 ":" "constant string"
#line 1236 "dhcp4_parser.yy"
               {
    ElementPtr cert(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("cert-file", cert);
    ctx.leave();
}
#line 2299 "dhcp4_parser.cc"
    break;

  case 304: // $@48: %empty
#line 1242 "dhcp4_parser.yy"
                   {
    ctx.unique("key-file", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2308 "dhcp4_parser.cc"
    break;

  case 305: // key_file: "key-file" $@48 ":" "constant string"
#line 1245 "dhcp4_parser.yy"
               {
    ElementPtr key(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("key-file", key);
    ctx.leave();
}
#line 2318 "dhcp4_parser.cc"
    break;

  case 306: // $@49: %empty
#line 1251 "dhcp4_parser.yy"
                         {
    ctx.unique("cipher-list", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2327 "dhcp4_parser.cc"
    break;

  case 307: // cipher_list: "cipher-list" $@49 ":" "constant string"
#line 1254 "dhcp4_parser.yy"
               {
    ElementPtr cl(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("cipher-list", cl);
    ctx.leave();
}
#line 2337 "dhcp4_parser.cc"
    break;

  case 308: // $@50: %empty
#line 1260 "dhcp4_parser.yy"
                                                           {
    ctx.unique("host-reservation-identifiers", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("host-reservation-identifiers", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.HOST_RESERVATION_IDENTIFIERS);
}
#line 2349 "dhcp4_parser.cc"
    break;

  case 309: // host_reservation_identifiers: "host-reservation-identifiers" $@50 ":" "[" host_reservation_identifiers_list "]"
#line 1266 "dhcp4_parser.yy"
                                                                          {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2358 "dhcp4_parser.cc"
    break;

  case 312: // host_reservation_identifiers_list: host_reservation_identifiers_list ","
#line 1273 "dhcp4_parser.yy"
                                              {
        ctx.warnAboutExtraCommas(yystack_[0].location);
        }
#line 2366 "dhcp4_parser.cc"
    break;

  case 318: // duid_id: "duid"
#line 1285 "dhcp4_parser.yy"
              {
    ElementPtr duid(new StringElement("duid", ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(duid);
}
#line 2375 "dhcp4_parser.cc"
    break;

  case 319: // hw_address_id: "hw-address"
#line 1290 "dhcp4_parser.yy"
                          {
    ElementPtr hwaddr(new StringElement("hw-address", ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(hwaddr);
}
#line 2384 "dhcp4_parser.cc"
    break;

  case 320: // circuit_id: "circuit-id"
#line 1295 "dhcp4_parser.yy"
                       {
    ElementPtr circuit(new StringElement("circuit-id", ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(circuit);
}
#line 2393 "dhcp4_parser.cc"
    break;

  case 321: // client_id: "client-id"
#line 1300 "dhcp4_parser.yy"
                     {
    ElementPtr client(new StringElement("client-id", ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(client);
}
#line 2402 "dhcp4_parser.cc"
    break;

  case 322: // flex_id: "flex-id"
#line 1305 "dhcp4_parser.yy"
                 {
    ElementPtr flex_id(new StringElement("flex-id", ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(flex_id);
}
#line 2411 "dhcp4_parser.cc"
    break;

  case 323: // $@51: %empty
#line 1312 "dhcp4_parser.yy"
                                           {
    ctx.unique("multi-threading", ctx.loc2pos(yystack_[0].location));
    ElementPtr mt(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("multi-threading", mt);
    ctx.stack_.push_back(mt);
    ctx.enter(ctx.DHCP_MULTI_THREADING);
}
#line 2423 "dhcp4_parser.cc"
    break;

  case 324: // dhcp_multi_threading: "multi-threading" $@51 ":" "{" multi_threading_params "}"
#line 1318 "dhcp4_parser.yy"
                                                             {
    // The enable parameter is required.
    ctx.require("enable-multi-threading", ctx.loc2pos(yystack_[2].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2434 "dhcp4_parser.cc"
    break;

  case 327: // multi_threading_params: multi_threading_params ","
#line 1327 "dhcp4_parser.yy"
                                                     {
                          ctx.warnAboutExtraCommas(yystack_[0].location);
                          }
#line 2442 "dhcp4_parser.cc"
    break;

  case 334: // enable_multi_threading: "enable-multi-threading" ":" "boolean"
#line 1340 "dhcp4_parser.yy"
                                                             {
    ctx.unique("enable-multi-threading", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("enable-multi-threading", b);
}
#line 2452 "dhcp4_parser.cc"
    break;

  case 335: // thread_pool_size: "thread-pool-size" ":" "integer"
#line 1346 "dhcp4_parser.yy"
                                                 {
    ctx.unique("thread-pool-size", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("thread-pool-size", prf);
}
#line 2462 "dhcp4_parser.cc"
    break;

  case 336: // packet_queue_size: "packet-queue-size" ":" "integer"
#line 1352 "dhcp4_parser.yy"
                                                   {
    ctx.unique("packet-queue-size", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("packet-queue-size", prf);
}
#line 2472 "dhcp4_parser.cc"
    break;

  case 337: // $@52: %empty
#line 1358 "dhcp4_parser.yy"
                                 {
    ctx.unique("hooks-libraries", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hooks-libraries", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.HOOKS_LIBRARIES);
}
#line 2484 "dhcp4_parser.cc"
    break;

  case 338: // hooks_libraries: "hooks-libraries" $@52 ":" "[" hooks_libraries_list "]"
#line 1364 "dhcp4_parser.yy"
                                                             {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2493 "dhcp4_parser.cc"
    break;

  case 343: // not_empty_hooks_libraries_list: not_empty_hooks_libraries_list ","
#line 1375 "dhcp4_parser.yy"
                                           {
        ctx.warnAboutExtraCommas(yystack_[0].location);
        }
#line 2501 "dhcp4_parser.cc"
    break;

  case 344: // $@53: %empty
#line 1380 "dhcp4_parser.yy"
                              {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 2511 "dhcp4_parser.cc"
    break;

  case 345: // hooks_library: "{" $@53 hooks_params "}"
#line 1384 "dhcp4_parser.yy"
                              {
    // The library hooks parameter is required
    ctx.require("library", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 2521 "dhcp4_parser.cc"
    break;

  case 346: // $@54: %empty
#line 1390 "dhcp4_parser.yy"
                                  {
    // Parse the hooks-libraries list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 2531 "dhcp4_parser.cc"
    break;

  case 347: // sub_hooks_library: "{" $@54 hooks_params "}"
#line 1394 "dhcp4_parser.yy"
                              {
    // The library hooks parameter is required
    ctx.require("library", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    // parsing completed
}
#line 2541 "dhcp4_parser.cc"
    break;

  case 350: // hooks_params: hooks_params ","
#line 1402 "dhcp4_parser.yy"
                                 {
                ctx.warnAboutExtraCommas(yystack_[0].location);
                }
#line 2549 "dhcp4_parser.cc"
    break;

  case 354: // $@55: %empty
#line 1412 "dhcp4_parser.yy"
                 {
    ctx.unique("library", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2558 "dhcp4_parser.cc"
    break;

  case 355: // library: "library" $@55 ":" "constant string"
#line 1415 "dhcp4_parser.yy"
               {
    ElementPtr lib(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("library", lib);
    ctx.leave();
}
#line 2568 "dhcp4_parser.cc"
    break;

  case 356: // $@56: %empty
#line 1421 "dhcp4_parser.yy"
                       {
    ctx.unique("parameters", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2577 "dhcp4_parser.cc"
    break;

  case 357: // parameters: "parameters" $@56 ":" map_value
#line 1424 "dhcp4_parser.yy"
                  {
    ctx.stack_.back()->set("parameters", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 2586 "dhcp4_parser.cc"
    break;

  case 358: // $@57: %empty
#line 1430 "dhcp4_parser.yy"
                                                     {
    ctx.unique("expired-leases-processing", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("expired-leases-processing", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.EXPIRED_LEASES_PROCESSING);
}
#line 2598 "dhcp4_parser.cc"
    break;

  case 359: // expired_leases_processing: "expired-leases-processing" $@57 ":" "{" expired_leases_params "}"
#line 1436 "dhcp4_parser.yy"
                                                            {
    // No expired lease parameter is required
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2608 "dhcp4_parser.cc"
    break;

  case 362: // expired_leases_params: expired_leases_params ","
#line 1444 "dhcp4_parser.yy"
                                                   {
                         ctx.warnAboutExtraCommas(yystack_[0].location);
                         }
#line 2616 "dhcp4_parser.cc"
    break;

  case 369: // reclaim_timer_wait_time: "reclaim-timer-wait-time" ":" "integer"
#line 1457 "dhcp4_parser.yy"
                                                               {
    ctx.unique("reclaim-timer-wait-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reclaim-timer-wait-time", value);
}
#line 2626 "dhcp4_parser.cc"
    break;

  case 370: // flush_reclaimed_timer_wait_time: "flush-reclaimed-timer-wait-time" ":" "integer"
#line 1463 "dhcp4_parser.yy"
                                                                               {
    ctx.unique("flush-reclaimed-timer-wait-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("flush-reclaimed-timer-wait-time", value);
}
#line 2636 "dhcp4_parser.cc"
    break;

  case 371: // hold_reclaimed_time: "hold-reclaimed-time" ":" "integer"
#line 1469 "dhcp4_parser.yy"
                                                       {
    ctx.unique("hold-reclaimed-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hold-reclaimed-time", value);
}
#line 2646 "dhcp4_parser.cc"
    break;

  case 372: // max_reclaim_leases: "max-reclaim-leases" ":" "integer"
#line 1475 "dhcp4_parser.yy"
                                                     {
    ctx.unique("max-reclaim-leases", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-reclaim-leases", value);
}
#line 2656 "dhcp4_parser.cc"
    break;

  case 373: // max_reclaim_time: "max-reclaim-time" ":" "integer"
#line 1481 "dhcp4_parser.yy"
                                                 {
    ctx.unique("max-reclaim-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-reclaim-time", value);
}
#line 2666 "dhcp4_parser.cc"
    break;

  case 374: // unwarned_reclaim_cycles: "unwarned-reclaim-cycles" ":" "integer"
#line 1487 "dhcp4_parser.yy"
                                                               {
    ctx.unique("unwarned-reclaim-cycles", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("unwarned-reclaim-cycles", value);
}
#line 2676 "dhcp4_parser.cc"
    break;

  case 375: // $@58: %empty
#line 1496 "dhcp4_parser.yy"
                      {
    ctx.unique("subnet4", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("subnet4", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.SUBNET4);
}
#line 2688 "dhcp4_parser.cc"
    break;

  case 376: // subnet4_list: "subnet4" $@58 ":" "[" subnet4_list_content "]"
#line 1502 "dhcp4_parser.yy"
                                                             {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2697 "dhcp4_parser.cc"
    break;

  case 381: // not_empty_subnet4_list: not_empty_subnet4_list ","
#line 1516 "dhcp4_parser.yy"
                                                     {
                          ctx.warnAboutExtraCommas(yystack_[0].location);
                          }
#line 2705 "dhcp4_parser.cc"
    break;

  case 382: // $@59: %empty
#line 1525 "dhcp4_parser.yy"
                        {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 2715 "dhcp4_parser.cc"
    break;

  case 383: // subnet4: "{" $@59 subnet4_params "}"
#line 1529 "dhcp4_parser.yy"
                                {
    // Once we reached this place, the subnet parsing is now complete.
    // If we want to, we can implement default values here.
    // In particular we can do things like this:
    // if (!ctx.stack_.back()->get("interface")) {
    //     ctx.stack_.back()->set("interface", StringElement("loopback"));
    // }
    //
    // We can also stack up one level (Dhcp4) and copy over whatever
    // global parameters we want to:
    // if (!ctx.stack_.back()->get("renew-timer")) {
    //     ElementPtr renew = ctx_stack_[...].get("renew-timer");
    //     if (renew) {
    //         ctx.stack_.back()->set("renew-timer", renew);
    //     }
    // }

    // The subnet subnet4 parameter is required
    ctx.require("subnet", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 2741 "dhcp4_parser.cc"
    break;

  case 384: // $@60: %empty
#line 1551 "dhcp4_parser.yy"
                            {
    // Parse the subnet4 list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 2751 "dhcp4_parser.cc"
    break;

  case 385: // sub_subnet4: "{" $@60 subnet4_params "}"
#line 1555 "dhcp4_parser.yy"
                                {
    // The subnet subnet4 parameter is required
    ctx.require("subnet", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    // parsing completed
}
#line 2761 "dhcp4_parser.cc"
    break;

  case 388: // subnet4_params: subnet4_params ","
#line 1564 "dhcp4_parser.yy"
                                     {
                  ctx.warnAboutExtraCommas(yystack_[0].location);
                  }
#line 2769 "dhcp4_parser.cc"
    break;

  case 438: // $@61: %empty
#line 1621 "dhcp4_parser.yy"
               {
    ctx.unique("subnet", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2778 "dhcp4_parser.cc"
    break;

  case 439: // subnet: "subnet" $@61 ":" "constant string"
#line 1624 "dhcp4_parser.yy"
               {
    ElementPtr subnet(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("subnet", subnet);
    ctx.leave();
}
#line 2788 "dhcp4_parser.cc"
    break;

  case 440: // $@62: %empty
#line 1630 "dhcp4_parser.yy"
                                           {
    ctx.unique("4o6-interface", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2797 "dhcp4_parser.cc"
    break;

  case 441: // subnet_4o6_interface: "4o6-interface" $@62 ":" "constant string"
#line 1633 "dhcp4_parser.yy"
               {
    ElementPtr iface(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("4o6-interface", iface);
    ctx.leave();
}
#line 2807 "dhcp4_parser.cc"
    break;

  case 442: // $@63: %empty
#line 1639 "dhcp4_parser.yy"
                                                 {
    ctx.unique("4o6-interface-id", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2816 "dhcp4_parser.cc"
    break;

  case 443: // subnet_4o6_interface_id: "4o6-interface-id" $@63 ":" "constant string"
#line 1642 "dhcp4_parser.yy"
               {
    ElementPtr iface(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("4o6-interface-id", iface);
    ctx.leave();
}
#line 2826 "dhcp4_parser.cc"
    break;

  case 444: // $@64: %empty
#line 1648 "dhcp4_parser.yy"
                                     {
    ctx.unique("4o6-subnet", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2835 "dhcp4_parser.cc"
    break;

  case 445: // subnet_4o6_subnet: "4o6-subnet" $@64 ":" "constant string"
#line 1651 "dhcp4_parser.yy"
               {
    ElementPtr iface(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("4o6-subnet", iface);
    ctx.leave();
}
#line 2845 "dhcp4_parser.cc"
    break;

  case 446: // $@65: %empty
#line 1657 "dhcp4_parser.yy"
                     {
    ctx.unique("interface", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2854 "dhcp4_parser.cc"
    break;

  case 447: // interface: "interface" $@65 ":" "constant string"
#line 1660 "dhcp4_parser.yy"
               {
    ElementPtr iface(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("interface", iface);
    ctx.leave();
}
#line 2864 "dhcp4_parser.cc"
    break;

  case 448: // $@66: %empty
#line 1666 "dhcp4_parser.yy"
                           {
    ctx.unique("client-class", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2873 "dhcp4_parser.cc"
    break;

  case 449: // client_class: "client-class" $@66 ":" "constant string"
#line 1669 "dhcp4_parser.yy"
               {
    ElementPtr cls(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("client-class", cls);
    ctx.leave();
}
#line 2883 "dhcp4_parser.cc"
    break;

  case 450: // $@67: %empty
#line 1675 "dhcp4_parser.yy"
                                               {
    ctx.unique("require-client-classes", ctx.loc2pos(yystack_[0].location));
    ElementPtr c(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("require-client-classes", c);
    ctx.stack_.push_back(c);
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2895 "dhcp4_parser.cc"
    break;

  case 451: // require_client_classes: "require-client-classes" $@67 ":" list_strings
#line 1681 "dhcp4_parser.yy"
                     {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2904 "dhcp4_parser.cc"
    break;

  case 452: // reservations_global: "reservations-global" ":" "boolean"
#line 1686 "dhcp4_parser.yy"
                                                       {
    ctx.unique("reservations-global", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reservations-global", b);
}
#line 2914 "dhcp4_parser.cc"
    break;

  case 453: // reservations_in_subnet: "reservations-in-subnet" ":" "boolean"
#line 1692 "dhcp4_parser.yy"
                                                             {
    ctx.unique("reservations-in-subnet", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reservations-in-subnet", b);
}
#line 2924 "dhcp4_parser.cc"
    break;

  case 454: // reservations_out_of_pool: "reservations-out-of-pool" ":" "boolean"
#line 1698 "dhcp4_parser.yy"
                                                                 {
    ctx.unique("reservations-out-of-pool", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reservations-out-of-pool", b);
}
#line 2934 "dhcp4_parser.cc"
    break;

  case 455: // $@68: %empty
#line 1704 "dhcp4_parser.yy"
                                   {
    ctx.unique("reservation-mode", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.RESERVATION_MODE);
}
#line 2943 "dhcp4_parser.cc"
    break;

  case 456: // reservation_mode: "reservation-mode" $@68 ":" hr_mode
#line 1707 "dhcp4_parser.yy"
                {
    ctx.stack_.back()->set("reservation-mode", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 2952 "dhcp4_parser.cc"
    break;

  case 457: // hr_mode: "disabled"
#line 1712 "dhcp4_parser.yy"
                  { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("disabled", ctx.loc2pos(yystack_[0].location))); }
#line 2958 "dhcp4_parser.cc"
    break;

  case 458: // hr_mode: "out-of-pool"
#line 1713 "dhcp4_parser.yy"
                     { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("out-of-pool", ctx.loc2pos(yystack_[0].location))); }
#line 2964 "dhcp4_parser.cc"
    break;

  case 459: // hr_mode: "global"
#line 1714 "dhcp4_parser.yy"
                { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("global", ctx.loc2pos(yystack_[0].location))); }
#line 2970 "dhcp4_parser.cc"
    break;

  case 460: // hr_mode: "all"
#line 1715 "dhcp4_parser.yy"
             { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("all", ctx.loc2pos(yystack_[0].location))); }
#line 2976 "dhcp4_parser.cc"
    break;

  case 461: // id: "id" ":" "integer"
#line 1718 "dhcp4_parser.yy"
                     {
    ctx.unique("id", ctx.loc2pos(yystack_[2].location));
    ElementPtr id(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("id", id);
}
#line 2986 "dhcp4_parser.cc"
    break;

  case 462: // $@69: %empty
#line 1726 "dhcp4_parser.yy"
                                 {
    ctx.unique("shared-networks", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("shared-networks", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.SHARED_NETWORK);
}
#line 2998 "dhcp4_parser.cc"
    break;

  case 463: // shared_networks: "shared-networks" $@69 ":" "[" shared_networks_content "]"
#line 1732 "dhcp4_parser.yy"
                                                                {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3007 "dhcp4_parser.cc"
    break;

  case 468: // shared_networks_list: shared_networks_list ","
#line 1745 "dhcp4_parser.yy"
                                                 {
                        ctx.warnAboutExtraCommas(yystack_[0].location);
                        }
#line 3015 "dhcp4_parser.cc"
    break;

  case 469: // $@70: %empty
#line 1750 "dhcp4_parser.yy"
                               {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 3025 "dhcp4_parser.cc"
    break;

  case 470: // shared_network: "{" $@70 shared_network_params "}"
#line 1754 "dhcp4_parser.yy"
                                       {
    ctx.stack_.pop_back();
}
#line 3033 "dhcp4_parser.cc"
    break;

  case 473: // shared_network_params: shared_network_params ","
#line 1760 "dhcp4_parser.yy"
                                                   {
                         ctx.warnAboutExtraCommas(yystack_[0].location);
                         }
#line 3041 "dhcp4_parser.cc"
    break;

  case 518: // $@71: %empty
#line 1815 "dhcp4_parser.yy"
                            {
    ctx.unique("option-def", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("option-def", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.OPTION_DEF);
}
#line 3053 "dhcp4_parser.cc"
    break;

  case 519: // option_def_list: "option-def" $@71 ":" "[" option_def_list_content "]"
#line 1821 "dhcp4_parser.yy"
                                                                {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3062 "dhcp4_parser.cc"
    break;

  case 520: // $@72: %empty
#line 1829 "dhcp4_parser.yy"
                                    {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 3071 "dhcp4_parser.cc"
    break;

  case 521: // sub_option_def_list: "{" $@72 option_def_list "}"
#line 1832 "dhcp4_parser.yy"
                                 {
    // parsing completed
}
#line 3079 "dhcp4_parser.cc"
    break;

  case 526: // not_empty_option_def_list: not_empty_option_def_list ","
#line 1844 "dhcp4_parser.yy"
                                                           {
                             ctx.warnAboutExtraCommas(yystack_[0].location);
                             }
#line 3087 "dhcp4_parser.cc"
    break;

  case 527: // $@73: %empty
#line 1851 "dhcp4_parser.yy"
                                 {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 3097 "dhcp4_parser.cc"
    break;

  case 528: // option_def_entry: "{" $@73 option_def_params "}"
#line 1855 "dhcp4_parser.yy"
                                   {
    // The name, code and type option def parameters are required.
    ctx.require("name", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.require("code", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.require("type", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 3109 "dhcp4_parser.cc"
    break;

  case 529: // $@74: %empty
#line 1866 "dhcp4_parser.yy"
                               {
    // Parse the option-def list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 3119 "dhcp4_parser.cc"
    break;

  case 530: // sub_option_def: "{" $@74 option_def_params "}"
#line 1870 "dhcp4_parser.yy"
                                   {
    // The name, code and type option def parameters are required.
    ctx.require("name", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.require("code", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.require("type", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    // parsing completed
}
#line 3131 "dhcp4_parser.cc"
    break;

  case 535: // not_empty_option_def_params: not_empty_option_def_params ","
#line 1886 "dhcp4_parser.yy"
                                                               {
                               ctx.warnAboutExtraCommas(yystack_[0].location);
                               }
#line 3139 "dhcp4_parser.cc"
    break;

  case 547: // code: "code" ":" "integer"
#line 1905 "dhcp4_parser.yy"
                         {
    ctx.unique("code", ctx.loc2pos(yystack_[2].location));
    ElementPtr code(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("code", code);
}
#line 3149 "dhcp4_parser.cc"
    break;

  case 549: // $@75: %empty
#line 1913 "dhcp4_parser.yy"
                      {
    ctx.unique("type", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3158 "dhcp4_parser.cc"
    break;

  case 550: // option_def_type: "type" $@75 ":" "constant string"
#line 1916 "dhcp4_parser.yy"
               {
    ElementPtr prf(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("type", prf);
    ctx.leave();
}
#line 3168 "dhcp4_parser.cc"
    break;

  case 551: // $@76: %empty
#line 1922 "dhcp4_parser.yy"
                                      {
    ctx.unique("record-types", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3177 "dhcp4_parser.cc"
    break;

  case 552: // option_def_record_types: "record-types" $@76 ":" "constant string"
#line 1925 "dhcp4_parser.yy"
               {
    ElementPtr rtypes(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("record-types", rtypes);
    ctx.leave();
}
#line 3187 "dhcp4_parser.cc"
    break;

  case 553: // $@77: %empty
#line 1931 "dhcp4_parser.yy"
             {
    ctx.unique("space", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3196 "dhcp4_parser.cc"
    break;

  case 554: // space: "space" $@77 ":" "constant string"
#line 1934 "dhcp4_parser.yy"
               {
    ElementPtr space(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("space", space);
    ctx.leave();
}
#line 3206 "dhcp4_parser.cc"
    break;

  case 556: // $@78: %empty
#line 1942 "dhcp4_parser.yy"
                                    {
    ctx.unique("encapsulate", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3215 "dhcp4_parser.cc"
    break;

  case 557: // option_def_encapsulate: "encapsulate" $@78 ":" "constant string"
#line 1945 "dhcp4_parser.yy"
               {
    ElementPtr encap(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("encapsulate", encap);
    ctx.leave();
}
#line 3225 "dhcp4_parser.cc"
    break;

  case 558: // option_def_array: "array" ":" "boolean"
#line 1951 "dhcp4_parser.yy"
                                      {
    ctx.unique("array", ctx.loc2pos(yystack_[2].location));
    ElementPtr array(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("array", array);
}
#line 3235 "dhcp4_parser.cc"
    break;

  case 559: // $@79: %empty
#line 1961 "dhcp4_parser.yy"
                              {
    ctx.unique("option-data", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("option-data", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.OPTION_DATA);
}
#line 3247 "dhcp4_parser.cc"
    break;

  case 560: // option_data_list: "option-data" $@79 ":" "[" option_data_list_content "]"
#line 1967 "dhcp4_parser.yy"
                                                                 {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3256 "dhcp4_parser.cc"
    break;

  case 565: // not_empty_option_data_list: not_empty_option_data_list ","
#line 1982 "dhcp4_parser.yy"
                                                             {
                              ctx.warnAboutExtraCommas(yystack_[0].location);
                              }
#line 3264 "dhcp4_parser.cc"
    break;

  case 566: // $@80: %empty
#line 1989 "dhcp4_parser.yy"
                                  {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 3274 "dhcp4_parser.cc"
    break;

  case 567: // option_data_entry: "{" $@80 option_data_params "}"
#line 1993 "dhcp4_parser.yy"
                                    {
    /// @todo: the code or name parameters are required.
    ctx.stack_.pop_back();
}
#line 3283 "dhcp4_parser.cc"
    break;

  case 568: // $@81: %empty
#line 2001 "dhcp4_parser.yy"
                                {
    // Parse the option-data list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 3293 "dhcp4_parser.cc"
    break;

  case 569: // sub_option_data: "{" $@81 option_data_params "}"
#line 2005 "dhcp4_parser.yy"
                                    {
    /// @todo: the code or name parameters are required.
    // parsing completed
}
#line 3302 "dhcp4_parser.cc"
    break;

  case 574: // not_empty_option_data_params: not_empty_option_data_params ","
#line 2021 "dhcp4_parser.yy"
                                         {
        ctx.warnAboutExtraCommas(yystack_[0].location);
        }
#line 3310 "dhcp4_parser.cc"
    break;

  case 586: // $@82: %empty
#line 2042 "dhcp4_parser.yy"
                       {
    ctx.unique("data", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3319 "dhcp4_parser.cc"
    break;

  case 587: // option_data_data: "data" $@82 ":" "constant string"
#line 2045 "dhcp4_parser.yy"
               {
    ElementPtr data(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("data", data);
    ctx.leave();
}
#line 3329 "dhcp4_parser.cc"
    break;

  case 590: // option_data_csv_format: "csv-format" ":" "boolean"
#line 2055 "dhcp4_parser.yy"
                                                 {
    ctx.unique("csv-format", ctx.loc2pos(yystack_[2].location));
    ElementPtr csv(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("csv-format", csv);
}
#line 3339 "dhcp4_parser.cc"
    break;

  case 591: // option_data_always_send: "always-send" ":" "boolean"
#line 2061 "dhcp4_parser.yy"
                                                   {
    ctx.unique("always-send", ctx.loc2pos(yystack_[2].location));
    ElementPtr persist(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("always-send", persist);
}
#line 3349 "dhcp4_parser.cc"
    break;

  case 592: // option_data_never_send: "never-send" ":" "boolean"
#line 2067 "dhcp4_parser.yy"
                                                 {
    ctx.unique("never-send", ctx.loc2pos(yystack_[2].location));
    ElementPtr cancel(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("never-send", cancel);
}
#line 3359 "dhcp4_parser.cc"
    break;

  case 593: // $@83: %empty
#line 2076 "dhcp4_parser.yy"
                  {
    ctx.unique("pools", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("pools", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.POOLS);
}
#line 3371 "dhcp4_parser.cc"
    break;

  case 594: // pools_list: "pools" $@83 ":" "[" pools_list_content "]"
#line 2082 "dhcp4_parser.yy"
                                                           {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3380 "dhcp4_parser.cc"
    break;

  case 599: // not_empty_pools_list: not_empty_pools_list ","
#line 2095 "dhcp4_parser.yy"
                                                 {
                        ctx.warnAboutExtraCommas(yystack_[0].location);
                        }
#line 3388 "dhcp4_parser.cc"
    break;

  case 600: // $@84: %empty
#line 2100 "dhcp4_parser.yy"
                                {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 3398 "dhcp4_parser.cc"
    break;

  case 601: // pool_list_entry: "{" $@84 pool_params "}"
#line 2104 "dhcp4_parser.yy"
                             {
    // The pool parameter is required.
    ctx.require("pool", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 3408 "dhcp4_parser.cc"
    break;

  case 602: // $@85: %empty
#line 2110 "dhcp4_parser.yy"
                          {
    // Parse the pool list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 3418 "dhcp4_parser.cc"
    break;

  case 603: // sub_pool4: "{" $@85 pool_params "}"
#line 2114 "dhcp4_parser.yy"
                             {
    // The pool parameter is required.
    ctx.require("pool", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    // parsing completed
}
#line 3428 "dhcp4_parser.cc"
    break;

  case 606: // pool_params: pool_params ","
#line 2122 "dhcp4_parser.yy"
                               {
               ctx.warnAboutExtraCommas(yystack_[0].location);
               }
#line 3436 "dhcp4_parser.cc"
    break;

  case 614: // $@86: %empty
#line 2136 "dhcp4_parser.yy"
                 {
    ctx.unique("pool", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3445 "dhcp4_parser.cc"
    break;

  case 615: // pool_entry: "pool" $@86 ":" "constant string"
#line 2139 "dhcp4_parser.yy"
               {
    ElementPtr pool(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("pool", pool);
    ctx.leave();
}
#line 3455 "dhcp4_parser.cc"
    break;

  case 616: // $@87: %empty
#line 2145 "dhcp4_parser.yy"
                           {
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3463 "dhcp4_parser.cc"
    break;

  case 617: // user_context: "user-context" $@87 ":" map_value
#line 2147 "dhcp4_parser.yy"
                  {
    ElementPtr parent = ctx.stack_.back();
    ElementPtr user_context = yystack_[0].value.as < ElementPtr > ();
    ConstElementPtr old = parent->get("user-context");

    // Handle already existing user context
    if (old) {
        // Check if it was a comment or a duplicate
        if ((old->size() != 1) || !old->contains("comment")) {
            std::stringstream msg;
            msg << "duplicate user-context entries (previous at "
                << old->getPosition().str() << ")";
            error(yystack_[3].location, msg.str());
        }
        // Merge the comment
        user_context->set("comment", old->get("comment"));
    }

    // Set the user context
    parent->set("user-context", user_context);
    ctx.leave();
}
#line 3490 "dhcp4_parser.cc"
    break;

  case 618: // $@88: %empty
#line 2170 "dhcp4_parser.yy"
                 {
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3498 "dhcp4_parser.cc"
    break;

  case 619: // comment: "comment" $@88 ":" "constant string"
#line 2172 "dhcp4_parser.yy"
               {
    ElementPtr parent = ctx.stack_.back();
    ElementPtr user_context(new MapElement(ctx.loc2pos(yystack_[3].location)));
    ElementPtr comment(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    user_context->set("comment", comment);

    // Handle already existing user context
    ConstElementPtr old = parent->get("user-context");
    if (old) {
        // Check for duplicate comment
        if (old->contains("comment")) {
            std::stringstream msg;
            msg << "duplicate user-context/comment entries (previous at "
                << old->getPosition().str() << ")";
            error(yystack_[3].location, msg.str());
        }
        // Merge the user context in the comment
        merge(user_context, old);
    }

    // Set the user context
    parent->set("user-context", user_context);
    ctx.leave();
}
#line 3527 "dhcp4_parser.cc"
    break;

  case 620: // $@89: %empty
#line 2200 "dhcp4_parser.yy"
                           {
    ctx.unique("reservations", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reservations", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.RESERVATIONS);
}
#line 3539 "dhcp4_parser.cc"
    break;

  case 621: // reservations: "reservations" $@89 ":" "[" reservations_list "]"
#line 2206 "dhcp4_parser.yy"
                                                          {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3548 "dhcp4_parser.cc"
    break;

  case 626: // not_empty_reservations_list: not_empty_reservations_list ","
#line 2217 "dhcp4_parser.yy"
                                                               {
                               ctx.warnAboutExtraCommas(yystack_[0].location);
                               }
#line 3556 "dhcp4_parser.cc"
    break;

  case 627: // $@90: %empty
#line 2222 "dhcp4_parser.yy"
                            {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 3566 "dhcp4_parser.cc"
    break;

  case 628: // reservation: "{" $@90 reservation_params "}"
#line 2226 "dhcp4_parser.yy"
                                    {
    /// @todo: an identifier parameter is required.
    ctx.stack_.pop_back();
}
#line 3575 "dhcp4_parser.cc"
    break;

  case 629: // $@91: %empty
#line 2231 "dhcp4_parser.yy"
                                {
    // Parse the reservations list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 3585 "dhcp4_parser.cc"
    break;

  case 630: // sub_reservation: "{" $@91 reservation_params "}"
#line 2235 "dhcp4_parser.yy"
                                    {
    /// @todo: an identifier parameter is required.
    // parsing completed
}
#line 3594 "dhcp4_parser.cc"
    break;

  case 635: // not_empty_reservation_params: not_empty_reservation_params ","
#line 2246 "dhcp4_parser.yy"
                                         {
        ctx.warnAboutExtraCommas(yystack_[0].location);
        }
#line 3602 "dhcp4_parser.cc"
    break;

  case 651: // $@92: %empty
#line 2269 "dhcp4_parser.yy"
                         {
    ctx.unique("next-server", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3611 "dhcp4_parser.cc"
    break;

  case 652: // next_server: "next-server" $@92 ":" "constant string"
#line 2272 "dhcp4_parser.yy"
               {
    ElementPtr next_server(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("next-server", next_server);
    ctx.leave();
}
#line 3621 "dhcp4_parser.cc"
    break;

  case 653: // $@93: %empty
#line 2278 "dhcp4_parser.yy"
                                 {
    ctx.unique("server-hostname", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3630 "dhcp4_parser.cc"
    break;

  case 654: // server_hostname: "server-hostname" $@93 ":" "constant string"
#line 2281 "dhcp4_parser.yy"
               {
    ElementPtr srv(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("server-hostname", srv);
    ctx.leave();
}
#line 3640 "dhcp4_parser.cc"
    break;

  case 655: // $@94: %empty
#line 2287 "dhcp4_parser.yy"
                               {
    ctx.unique("boot-file-name", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3649 "dhcp4_parser.cc"
    break;

  case 656: // boot_file_name: "boot-file-name" $@94 ":" "constant string"
#line 2290 "dhcp4_parser.yy"
               {
    ElementPtr bootfile(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("boot-file-name", bootfile);
    ctx.leave();
}
#line 3659 "dhcp4_parser.cc"
    break;

  case 657: // $@95: %empty
#line 2296 "dhcp4_parser.yy"
                       {
    ctx.unique("ip-address", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3668 "dhcp4_parser.cc"
    break;

  case 658: // ip_address: "ip-address" $@95 ":" "constant string"
#line 2299 "dhcp4_parser.yy"
               {
    ElementPtr addr(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ip-address", addr);
    ctx.leave();
}
#line 3678 "dhcp4_parser.cc"
    break;

  case 659: // $@96: %empty
#line 2305 "dhcp4_parser.yy"
                           {
    ctx.unique("ip-addresses", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ip-addresses", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3690 "dhcp4_parser.cc"
    break;

  case 660: // ip_addresses: "ip-addresses" $@96 ":" list_strings
#line 2311 "dhcp4_parser.yy"
                     {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3699 "dhcp4_parser.cc"
    break;

  case 661: // $@97: %empty
#line 2316 "dhcp4_parser.yy"
           {
    ctx.unique("duid", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3708 "dhcp4_parser.cc"
    break;

  case 662: // duid: "duid" $@97 ":" "constant string"
#line 2319 "dhcp4_parser.yy"
               {
    ElementPtr d(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("duid", d);
    ctx.leave();
}
#line 3718 "dhcp4_parser.cc"
    break;

  case 663: // $@98: %empty
#line 2325 "dhcp4_parser.yy"
                       {
    ctx.unique("hw-address", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3727 "dhcp4_parser.cc"
    break;

  case 664: // hw_address: "hw-address" $@98 ":" "constant string"
#line 2328 "dhcp4_parser.yy"
               {
    ElementPtr hw(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hw-address", hw);
    ctx.leave();
}
#line 3737 "dhcp4_parser.cc"
    break;

  case 665: // $@99: %empty
#line 2334 "dhcp4_parser.yy"
                           {
    ctx.unique("client-id", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3746 "dhcp4_parser.cc"
    break;

  case 666: // client_id_value: "client-id" $@99 ":" "constant string"
#line 2337 "dhcp4_parser.yy"
               {
    ElementPtr hw(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("client-id", hw);
    ctx.leave();
}
#line 3756 "dhcp4_parser.cc"
    break;

  case 667: // $@100: %empty
#line 2343 "dhcp4_parser.yy"
                             {
    ctx.unique("circuit-id", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3765 "dhcp4_parser.cc"
    break;

  case 668: // circuit_id_value: "circuit-id" $@100 ":" "constant string"
#line 2346 "dhcp4_parser.yy"
               {
    ElementPtr hw(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("circuit-id", hw);
    ctx.leave();
}
#line 3775 "dhcp4_parser.cc"
    break;

  case 669: // $@101: %empty
#line 2352 "dhcp4_parser.yy"
                       {
    ctx.unique("flex-id", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3784 "dhcp4_parser.cc"
    break;

  case 670: // flex_id_value: "flex-id" $@101 ":" "constant string"
#line 2355 "dhcp4_parser.yy"
               {
    ElementPtr hw(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("flex-id", hw);
    ctx.leave();
}
#line 3794 "dhcp4_parser.cc"
    break;

  case 671: // $@102: %empty
#line 2361 "dhcp4_parser.yy"
                   {
    ctx.unique("hostname", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3803 "dhcp4_parser.cc"
    break;

  case 672: // hostname: "hostname" $@102 ":" "constant string"
#line 2364 "dhcp4_parser.yy"
               {
    ElementPtr host(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hostname", host);
    ctx.leave();
}
#line 3813 "dhcp4_parser.cc"
    break;

  case 673: // $@103: %empty
#line 2370 "dhcp4_parser.yy"
                                           {
    ctx.unique("client-classes", ctx.loc2pos(yystack_[0].location));
    ElementPtr c(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("client-classes", c);
    ctx.stack_.push_back(c);
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3825 "dhcp4_parser.cc"
    break;

  case 674: // reservation_client_classes: "client-classes" $@103 ":" list_strings
#line 2376 "dhcp4_parser.yy"
                     {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3834 "dhcp4_parser.cc"
    break;

  case 675: // $@104: %empty
#line 2384 "dhcp4_parser.yy"
             {
    ctx.unique("relay", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("relay", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.RELAY);
}
#line 3846 "dhcp4_parser.cc"
    break;

  case 676: // relay: "relay" $@104 ":" "{" relay_map "}"
#line 2390 "dhcp4_parser.yy"
                                                {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3855 "dhcp4_parser.cc"
    break;

  case 679: // $@105: %empty
#line 2402 "dhcp4_parser.yy"
                               {
    ctx.unique("client-classes", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("client-classes", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.CLIENT_CLASSES);
}
#line 3867 "dhcp4_parser.cc"
    break;

  case 680: // client_classes: "client-classes" $@105 ":" "[" client_classes_list "]"
#line 2408 "dhcp4_parser.yy"
                                                            {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3876 "dhcp4_parser.cc"
    break;

  case 683: // client_classes_list: client_classes_list ","
#line 2415 "dhcp4_parser.yy"
                                               {
                       ctx.warnAboutExtraCommas(yystack_[0].location);
                       }
#line 3884 "dhcp4_parser.cc"
    break;

  case 684: // $@106: %empty
#line 2420 "dhcp4_parser.yy"
                                   {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 3894 "dhcp4_parser.cc"
    break;

  case 685: // client_class_entry: "{" $@106 client_class_params "}"
#line 2424 "dhcp4_parser.yy"
                                     {
    // The name client class parameter is required.
    ctx.require("name", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 3904 "dhcp4_parser.cc"
    break;

  case 690: // not_empty_client_class_params: not_empty_client_class_params ","
#line 2436 "dhcp4_parser.yy"
                                          {
        ctx.warnAboutExtraCommas(yystack_[0].location);
        }
#line 3912 "dhcp4_parser.cc"
    break;

  case 708: // $@107: %empty
#line 2461 "dhcp4_parser.yy"
                        {
    ctx.unique("test", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3921 "dhcp4_parser.cc"
    break;

  case 709: // client_class_test: "test" $@107 ":" "constant string"
#line 2464 "dhcp4_parser.yy"
               {
    ElementPtr test(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("test", test);
    ctx.leave();
}
#line 3931 "dhcp4_parser.cc"
    break;

  case 710: // $@108: %empty
#line 2470 "dhcp4_parser.yy"
                                          {
    ctx.unique("template-test", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3940 "dhcp4_parser.cc"
    break;

  case 711: // client_class_template_test: "template-test" $@108 ":" "constant string"
#line 2473 "dhcp4_parser.yy"
               {
    ElementPtr template_test(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("template-test", template_test);
    ctx.leave();
}
#line 3950 "dhcp4_parser.cc"
    break;

  case 712: // only_if_required: "only-if-required" ":" "boolean"
#line 2479 "dhcp4_parser.yy"
                                                 {
    ctx.unique("only-if-required", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("only-if-required", b);
}
#line 3960 "dhcp4_parser.cc"
    break;

  case 713: // dhcp4o6_port: "dhcp4o6-port" ":" "integer"
#line 2487 "dhcp4_parser.yy"
                                         {
    ctx.unique("dhcp4o6-port", ctx.loc2pos(yystack_[2].location));
    ElementPtr time(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("dhcp4o6-port", time);
}
#line 3970 "dhcp4_parser.cc"
    break;

  case 714: // $@109: %empty
#line 2495 "dhcp4_parser.yy"
                               {
    ctx.unique("control-socket", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("control-socket", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.CONTROL_SOCKET);
}
#line 3982 "dhcp4_parser.cc"
    break;

  case 715: // control_socket: "control-socket" $@109 ":" "{" control_socket_params "}"
#line 2501 "dhcp4_parser.yy"
                                                            {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3991 "dhcp4_parser.cc"
    break;

  case 718: // control_socket_params: control_socket_params ","
#line 2508 "dhcp4_parser.yy"
                                                   {
                          ctx.warnAboutExtraCommas(yystack_[0].location);
                          }
#line 3999 "dhcp4_parser.cc"
    break;

  case 724: // $@110: %empty
#line 2520 "dhcp4_parser.yy"
                                 {
    ctx.unique("socket-type", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4008 "dhcp4_parser.cc"
    break;

  case 725: // control_socket_type: "socket-type" $@110 ":" "constant string"
#line 2523 "dhcp4_parser.yy"
               {
    ElementPtr stype(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("socket-type", stype);
    ctx.leave();
}
#line 4018 "dhcp4_parser.cc"
    break;

  case 726: // $@111: %empty
#line 2529 "dhcp4_parser.yy"
                                 {
    ctx.unique("socket-name", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4027 "dhcp4_parser.cc"
    break;

  case 727: // control_socket_name: "socket-name" $@111 ":" "constant string"
#line 2532 "dhcp4_parser.yy"
               {
    ElementPtr name(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("socket-name", name);
    ctx.leave();
}
#line 4037 "dhcp4_parser.cc"
    break;

  case 728: // $@112: %empty
#line 2541 "dhcp4_parser.yy"
                                       {
    ctx.unique("dhcp-queue-control", ctx.loc2pos(yystack_[0].location));
    ElementPtr qc(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("dhcp-queue-control", qc);
    ctx.stack_.push_back(qc);
    ctx.enter(ctx.DHCP_QUEUE_CONTROL);
}
#line 4049 "dhcp4_parser.cc"
    break;

  case 729: // dhcp_queue_control: "dhcp-queue-control" $@112 ":" "{" queue_control_params "}"
#line 2547 "dhcp4_parser.yy"
                                                           {
    // The enable queue parameter is required.
    ctx.require("enable-queue", ctx.loc2pos(yystack_[2].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4060 "dhcp4_parser.cc"
    break;

  case 732: // queue_control_params: queue_control_params ","
#line 2556 "dhcp4_parser.yy"
                                                 {
                        ctx.warnAboutExtraCommas(yystack_[0].location);
                        }
#line 4068 "dhcp4_parser.cc"
    break;

  case 739: // enable_queue: "enable-queue" ":" "boolean"
#line 2569 "dhcp4_parser.yy"
                                         {
    ctx.unique("enable-queue", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("enable-queue", b);
}
#line 4078 "dhcp4_parser.cc"
    break;

  case 740: // $@113: %empty
#line 2575 "dhcp4_parser.yy"
                       {
    ctx.unique("queue-type", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4087 "dhcp4_parser.cc"
    break;

  case 741: // queue_type: "queue-type" $@113 ":" "constant string"
#line 2578 "dhcp4_parser.yy"
               {
    ElementPtr qt(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("queue-type", qt);
    ctx.leave();
}
#line 4097 "dhcp4_parser.cc"
    break;

  case 742: // capacity: "capacity" ":" "integer"
#line 2584 "dhcp4_parser.yy"
                                 {
    ctx.unique("capacity", ctx.loc2pos(yystack_[2].location));
    ElementPtr c(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("capacity", c);
}
#line 4107 "dhcp4_parser.cc"
    break;

  case 743: // $@114: %empty
#line 2590 "dhcp4_parser.yy"
                            {
    ctx.unique(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4116 "dhcp4_parser.cc"
    break;

  case 744: // arbitrary_map_entry: "constant string" $@114 ":" value
#line 2593 "dhcp4_parser.yy"
              {
    ctx.stack_.back()->set(yystack_[3].value.as < std::string > (), yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 4125 "dhcp4_parser.cc"
    break;

  case 745: // $@115: %empty
#line 2600 "dhcp4_parser.yy"
                     {
    ctx.unique("dhcp-ddns", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("dhcp-ddns", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.DHCP_DDNS);
}
#line 4137 "dhcp4_parser.cc"
    break;

  case 746: // dhcp_ddns: "dhcp-ddns" $@115 ":" "{" dhcp_ddns_params "}"
#line 2606 "dhcp4_parser.yy"
                                                       {
    // The enable updates DHCP DDNS parameter is required.
    ctx.require("enable-updates", ctx.loc2pos(yystack_[2].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4148 "dhcp4_parser.cc"
    break;

  case 747: // $@116: %empty
#line 2613 "dhcp4_parser.yy"
                              {
    // Parse the dhcp-ddns map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 4158 "dhcp4_parser.cc"
    break;

  case 748: // sub_dhcp_ddns: "{" $@116 dhcp_ddns_params "}"
#line 2617 "dhcp4_parser.yy"
                                  {
    // The enable updates DHCP DDNS parameter is required.
    ctx.require("enable-updates", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    // parsing completed
}
#line 4168 "dhcp4_parser.cc"
    break;

  case 751: // dhcp_ddns_params: dhcp_ddns_params ","
#line 2625 "dhcp4_parser.yy"
                                         {
                    ctx.warnAboutExtraCommas(yystack_[0].location);
                    }
#line 4176 "dhcp4_parser.cc"
    break;

  case 770: // enable_updates: "enable-updates" ":" "boolean"
#line 2650 "dhcp4_parser.yy"
                                             {
    ctx.unique("enable-updates", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("enable-updates", b);
}
#line 4186 "dhcp4_parser.cc"
    break;

  case 771: // $@117: %empty
#line 2656 "dhcp4_parser.yy"
                     {
    ctx.unique("server-ip", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4195 "dhcp4_parser.cc"
    break;

  case 772: // server_ip: "server-ip" $@117 ":" "constant string"
#line 2659 "dhcp4_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("server-ip", s);
    ctx.leave();
}
#line 4205 "dhcp4_parser.cc"
    break;

  case 773: // server_port: "server-port" ":" "integer"
#line 2665 "dhcp4_parser.yy"
                                       {
    ctx.unique("server-port", ctx.loc2pos(yystack_[2].location));
    ElementPtr i(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("server-port", i);
}
#line 4215 "dhcp4_parser.cc"
    break;

  case 774: // $@118: %empty
#line 2671 "dhcp4_parser.yy"
                     {
    ctx.unique("sender-ip", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4224 "dhcp4_parser.cc"
    break;

  case 775: // sender_ip: "sender-ip" $@118 ":" "constant string"
#line 2674 "dhcp4_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("sender-ip", s);
    ctx.leave();
}
#line 4234 "dhcp4_parser.cc"
    break;

  case 776: // sender_port: "sender-port" ":" "integer"
#line 2680 "dhcp4_parser.yy"
                                       {
    ctx.unique("sender-port", ctx.loc2pos(yystack_[2].location));
    ElementPtr i(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("sender-port", i);
}
#line 4244 "dhcp4_parser.cc"
    break;

  case 777: // max_queue_size: "max-queue-size" ":" "integer"
#line 2686 "dhcp4_parser.yy"
                                             {
    ctx.unique("max-queue-size", ctx.loc2pos(yystack_[2].location));
    ElementPtr i(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-queue-size", i);
}
#line 4254 "dhcp4_parser.cc"
    break;

  case 778: // $@119: %empty
#line 2692 "dhcp4_parser.yy"
                           {
    ctx.unique("ncr-protocol", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NCR_PROTOCOL);
}
#line 4263 "dhcp4_parser.cc"
    break;

  case 779: // ncr_protocol: "ncr-protocol" $@119 ":" ncr_protocol_value
#line 2695 "dhcp4_parser.yy"
                           {
    ctx.stack_.back()->set("ncr-protocol", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 4272 "dhcp4_parser.cc"
    break;

  case 780: // ncr_protocol_value: "udp"
#line 2701 "dhcp4_parser.yy"
        { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("UDP", ctx.loc2pos(yystack_[0].location))); }
#line 4278 "dhcp4_parser.cc"
    break;

  case 781: // ncr_protocol_value: "tcp"
#line 2702 "dhcp4_parser.yy"
        { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("TCP", ctx.loc2pos(yystack_[0].location))); }
#line 4284 "dhcp4_parser.cc"
    break;

  case 782: // $@120: %empty
#line 2705 "dhcp4_parser.yy"
                       {
    ctx.unique("ncr-format", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NCR_FORMAT);
}
#line 4293 "dhcp4_parser.cc"
    break;

  case 783: // ncr_format: "ncr-format" $@120 ":" "JSON"
#line 2708 "dhcp4_parser.yy"
             {
    ElementPtr json(new StringElement("JSON", ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ncr-format", json);
    ctx.leave();
}
#line 4303 "dhcp4_parser.cc"
    break;

  case 784: // $@121: %empty
#line 2715 "dhcp4_parser.yy"
                                         {
    ctx.unique("qualifying-suffix", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4312 "dhcp4_parser.cc"
    break;

  case 785: // dep_qualifying_suffix: "qualifying-suffix" $@121 ":" "constant string"
#line 2718 "dhcp4_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("qualifying-suffix", s);
    ctx.leave();
}
#line 4322 "dhcp4_parser.cc"
    break;

  case 786: // dep_override_no_update: "override-no-update" ":" "boolean"
#line 2725 "dhcp4_parser.yy"
                                                         {
    ctx.unique("override-no-update", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("override-no-update", b);
}
#line 4332 "dhcp4_parser.cc"
    break;

  case 787: // dep_override_client_update: "override-client-update" ":" "boolean"
#line 2732 "dhcp4_parser.yy"
                                                                 {
    ctx.unique("override-client-update", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("override-client-update", b);
}
#line 4342 "dhcp4_parser.cc"
    break;

  case 788: // $@122: %empty
#line 2739 "dhcp4_parser.yy"
                                             {
    ctx.unique("replace-client-name", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.REPLACE_CLIENT_NAME);
}
#line 4351 "dhcp4_parser.cc"
    break;

  case 789: // dep_replace_client_name: "replace-client-name" $@122 ":" ddns_replace_client_name_value
#line 2742 "dhcp4_parser.yy"
                                       {
    ctx.stack_.back()->set("replace-client-name", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 4360 "dhcp4_parser.cc"
    break;

  case 790: // $@123: %empty
#line 2748 "dhcp4_parser.yy"
                                       {
    ctx.unique("generated-prefix", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4369 "dhcp4_parser.cc"
    break;

  case 791: // dep_generated_prefix: "generated-prefix" $@123 ":" "constant string"
#line 2751 "dhcp4_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("generated-prefix", s);
    ctx.leave();
}
#line 4379 "dhcp4_parser.cc"
    break;

  case 792: // $@124: %empty
#line 2758 "dhcp4_parser.yy"
                                         {
    ctx.unique("hostname-char-set", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4388 "dhcp4_parser.cc"
    break;

  case 793: // dep_hostname_char_set: "hostname-char-set" $@124 ":" "constant string"
#line 2761 "dhcp4_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hostname-char-set", s);
    ctx.leave();
}
#line 4398 "dhcp4_parser.cc"
    break;

  case 794: // $@125: %empty
#line 2768 "dhcp4_parser.yy"
                                                         {
    ctx.unique("hostname-char-replacement", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4407 "dhcp4_parser.cc"
    break;

  case 795: // dep_hostname_char_replacement: "hostname-char-replacement" $@125 ":" "constant string"
#line 2771 "dhcp4_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hostname-char-replacement", s);
    ctx.leave();
}
#line 4417 "dhcp4_parser.cc"
    break;

  case 796: // $@126: %empty
#line 2780 "dhcp4_parser.yy"
                               {
    ctx.unique("config-control", ctx.loc2pos(yystack_[0].location));
    ElementPtr i(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("config-control", i);
    ctx.stack_.push_back(i);
    ctx.enter(ctx.CONFIG_CONTROL);
}
#line 4429 "dhcp4_parser.cc"
    break;

  case 797: // config_control: "config-control" $@126 ":" "{" config_control_params "}"
#line 2786 "dhcp4_parser.yy"
                                                            {
    // No config control params are required
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4439 "dhcp4_parser.cc"
    break;

  case 798: // $@127: %empty
#line 2792 "dhcp4_parser.yy"
                                   {
    // Parse the config-control map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 4449 "dhcp4_parser.cc"
    break;

  case 799: // sub_config_control: "{" $@127 config_control_params "}"
#line 2796 "dhcp4_parser.yy"
                                       {
    // No config_control params are required
    // parsing completed
}
#line 4458 "dhcp4_parser.cc"
    break;

  case 802: // config_control_params: config_control_params ","
#line 2804 "dhcp4_parser.yy"
                                                   {
                         ctx.warnAboutExtraCommas(yystack_[0].location);
                         }
#line 4466 "dhcp4_parser.cc"
    break;

  case 805: // $@128: %empty
#line 2814 "dhcp4_parser.yy"
                                   {
    ctx.unique("config-databases", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("config-databases", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.CONFIG_DATABASE);
}
#line 4478 "dhcp4_parser.cc"
    break;

  case 806: // config_databases: "config-databases" $@128 ":" "[" database_list "]"
#line 2820 "dhcp4_parser.yy"
                                                      {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4487 "dhcp4_parser.cc"
    break;

  case 807: // config_fetch_wait_time: "config-fetch-wait-time" ":" "integer"
#line 2825 "dhcp4_parser.yy"
                                                             {
    ctx.unique("config-fetch-wait-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("config-fetch-wait-time", value);
}
#line 4497 "dhcp4_parser.cc"
    break;

  case 808: // $@129: %empty
#line 2833 "dhcp4_parser.yy"
                 {
    ctx.unique("loggers", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("loggers", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.LOGGERS);
}
#line 4509 "dhcp4_parser.cc"
    break;

  case 809: // loggers: "loggers" $@129 ":" "[" loggers_entries "]"
#line 2839 "dhcp4_parser.yy"
                                                         {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4518 "dhcp4_parser.cc"
    break;

  case 812: // loggers_entries: loggers_entries ","
#line 2848 "dhcp4_parser.yy"
                                       {
                   ctx.warnAboutExtraCommas(yystack_[0].location);
                   }
#line 4526 "dhcp4_parser.cc"
    break;

  case 813: // $@130: %empty
#line 2854 "dhcp4_parser.yy"
                             {
    ElementPtr l(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(l);
    ctx.stack_.push_back(l);
}
#line 4536 "dhcp4_parser.cc"
    break;

  case 814: // logger_entry: "{" $@130 logger_params "}"
#line 2858 "dhcp4_parser.yy"
                               {
    ctx.stack_.pop_back();
}
#line 4544 "dhcp4_parser.cc"
    break;

  case 817: // logger_params: logger_params ","
#line 2864 "dhcp4_parser.yy"
                                   {
                 ctx.warnAboutExtraCommas(yystack_[0].location);
                 }
#line 4552 "dhcp4_parser.cc"
    break;

  case 825: // debuglevel: "debuglevel" ":" "integer"
#line 2878 "dhcp4_parser.yy"
                                     {
    ctx.unique("debuglevel", ctx.loc2pos(yystack_[2].location));
    ElementPtr dl(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("debuglevel", dl);
}
#line 4562 "dhcp4_parser.cc"
    break;

  case 826: // $@131: %empty
#line 2884 "dhcp4_parser.yy"
                   {
    ctx.unique("severity", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4571 "dhcp4_parser.cc"
    break;

  case 827: // severity: "severity" $@131 ":" "constant string"
#line 2887 "dhcp4_parser.yy"
               {
    ElementPtr sev(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("severity", sev);
    ctx.leave();
}
#line 4581 "dhcp4_parser.cc"
    break;

  case 828: // $@132: %empty
#line 2893 "dhcp4_parser.yy"
                                    {
    ctx.unique("output_options", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("output_options", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.OUTPUT_OPTIONS);
}
#line 4593 "dhcp4_parser.cc"
    break;

  case 829: // output_options_list: "output_options" $@132 ":" "[" output_options_list_content "]"
#line 2899 "dhcp4_parser.yy"
                                                                    {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4602 "dhcp4_parser.cc"
    break;

  case 832: // output_options_list_content: output_options_list_content ","
#line 2906 "dhcp4_parser.yy"
                                                               {
                               ctx.warnAboutExtraCommas(yystack_[0].location);
                               }
#line 4610 "dhcp4_parser.cc"
    break;

  case 833: // $@133: %empty
#line 2911 "dhcp4_parser.yy"
                             {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 4620 "dhcp4_parser.cc"
    break;

  case 834: // output_entry: "{" $@133 output_params_list "}"
#line 2915 "dhcp4_parser.yy"
                                    {
    ctx.stack_.pop_back();
}
#line 4628 "dhcp4_parser.cc"
    break;

  case 837: // output_params_list: output_params_list ","
#line 2921 "dhcp4_parser.yy"
                                             {
                      ctx.warnAboutExtraCommas(yystack_[0].location);
                      }
#line 4636 "dhcp4_parser.cc"
    break;

  case 843: // $@134: %empty
#line 2933 "dhcp4_parser.yy"
               {
    ctx.unique("output", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4645 "dhcp4_parser.cc"
    break;

  case 844: // output: "output" $@134 ":" "constant string"
#line 2936 "dhcp4_parser.yy"
               {
    ElementPtr sev(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("output", sev);
    ctx.leave();
}
#line 4655 "dhcp4_parser.cc"
    break;

  case 845: // flush: "flush" ":" "boolean"
#line 2942 "dhcp4_parser.yy"
                           {
    ctx.unique("flush", ctx.loc2pos(yystack_[2].location));
    ElementPtr flush(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("flush", flush);
}
#line 4665 "dhcp4_parser.cc"
    break;

  case 846: // maxsize: "maxsize" ":" "integer"
#line 2948 "dhcp4_parser.yy"
                               {
    ctx.unique("maxsize", ctx.loc2pos(yystack_[2].location));
    ElementPtr maxsize(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("maxsize", maxsize);
}
#line 4675 "dhcp4_parser.cc"
    break;

  case 847: // maxver: "maxver" ":" "integer"
#line 2954 "dhcp4_parser.yy"
                             {
    ctx.unique("maxver", ctx.loc2pos(yystack_[2].location));
    ElementPtr maxver(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("maxver", maxver);
}
#line 4685 "dhcp4_parser.cc"
    break;

  case 848: // $@135: %empty
#line 2960 "dhcp4_parser.yy"
                 {
    ctx.unique("pattern", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4694 "dhcp4_parser.cc"
    break;

  case 849: // pattern: "pattern" $@135 ":" "constant string"
#line 2963 "dhcp4_parser.yy"
               {
    ElementPtr sev(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("pattern", sev);
    ctx.leave();
}
#line 4704 "dhcp4_parser.cc"
    break;

  case 850: // $@136: %empty
#line 2969 "dhcp4_parser.yy"
                             {
    ctx.unique("compatibility", ctx.loc2pos(yystack_[0].location));
    ElementPtr i(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("compatibility", i);
    ctx.stack_.push_back(i);
    ctx.enter(ctx.COMPATIBILITY);
}
#line 4716 "dhcp4_parser.cc"
    break;

  case 851: // compatibility: "compatibility" $@136 ":" "{" compatibility_params "}"
#line 2975 "dhcp4_parser.yy"
                                                           {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4725 "dhcp4_parser.cc"
    break;

  case 854: // compatibility_params: compatibility_params ","
#line 2982 "dhcp4_parser.yy"
                                                 {
                        ctx.warnAboutExtraCommas(yystack_[0].location);
                        }
#line 4733 "dhcp4_parser.cc"
    break;

  case 860: // lenient_option_parsing: "lenient-option-parsing" ":" "boolean"
#line 2994 "dhcp4_parser.yy"
                                                             {
    ctx.unique("lenient-option-parsing", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("lenient-option-parsing", b);
}
#line 4743 "dhcp4_parser.cc"
    break;

  case 861: // ignore_dhcp_server_identifier: "ignore-dhcp-server-identifier" ":" "boolean"
#line 3000 "dhcp4_parser.yy"
                                                                   {
    ctx.unique("ignore-dhcp-server-identifier", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ignore-dhcp-server-identifier", b);
}
#line 4753 "dhcp4_parser.cc"
    break;

  case 862: // ignore_rai_link_selection: "ignore-rai-link-selection" ":" "boolean"
#line 3006 "dhcp4_parser.yy"
                                                             {
    ctx.unique("ignore-rai-link-selection", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ignore-rai-link-selection", b);
}
#line 4763 "dhcp4_parser.cc"
    break;

  case 863: // exclude_first_last_24: "exclude-first-last-24" ":" "boolean"
#line 3012 "dhcp4_parser.yy"
                                                           {
    ctx.unique("exclude-first-last-24", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("exclude-first-last-24", b);
}
#line 4773 "dhcp4_parser.cc"
    break;


#line 4777 "dhcp4_parser.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Dhcp4Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Dhcp4Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  Dhcp4Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // Dhcp4Parser::context.
  Dhcp4Parser::context::context (const Dhcp4Parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  Dhcp4Parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        int yychecklim = yylast_ - yyn + 1;
        int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }



  int
  Dhcp4Parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  Dhcp4Parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short Dhcp4Parser::yypact_ninf_ = -1018;

  const signed char Dhcp4Parser::yytable_ninf_ = -1;

  const short
  Dhcp4Parser::yypact_[] =
  {
     437, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018,    40,    38,    24,    39,    56,    74,
      90,   107,   117,   128,   146,   178,   192,   201, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018,    38,  -181,    50,   196,   171,   656,
      16,    33,   -45,   -10,   307,  -110,   636,   179, -1018,   106,
      76,    91,   152,   172, -1018,    41, -1018, -1018, -1018, -1018,
     174,   200,   213, -1018, -1018, -1018,   217, -1018, -1018, -1018,
     220,   232,   243,   250,   252,   290,   294,   303,   322,   332,
     357, -1018,   358,   364,   365,   369,   370, -1018, -1018, -1018,
     373,   378,   385,   397, -1018, -1018, -1018,   405, -1018, -1018,
   -1018, -1018, -1018, -1018,   406,   407,   408, -1018, -1018, -1018,
   -1018, -1018,   409, -1018, -1018, -1018, -1018, -1018, -1018,   410,
     412,   413, -1018, -1018,   414, -1018,   105, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,   415,   420,
     421,   422, -1018,   135, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
     423, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018,   153, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
     156, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018,   230,   343, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018,   424, -1018, -1018,   425, -1018, -1018, -1018,   426, -1018,
   -1018,   427,   428, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018,   429,   430,   435, -1018,
   -1018, -1018, -1018,   432,   438, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,   160, -1018,
   -1018, -1018,   439, -1018, -1018,   440, -1018,   441,   442, -1018,
   -1018,   443,   444, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
     176, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,   445,   197,
   -1018, -1018, -1018, -1018,    38,    38, -1018,   209,   446, -1018,
   -1018,   448,   449,   450,   233,   235,   236,   452,   455,   456,
     241,   458,   460,   461,   247,   248,   251,   253,   254,   260,
     249,   262,   264,   255,   258,   468,   268,   269,   270,   272,
     274,   486,   494,   496,   279,   282,   286,   293,   504,   505,
     506,   296,   508,   513,   515,   518,   519,   521,   306,   312,
     313,   523,   532,   533,   534,   535,   320,   539,   542,   543,
     545,   546,   547,   330,   331,   334,   550,   554, -1018,   196,
   -1018,   555,   558,   559,   344,   347,   350,   353,   171, -1018,
     561,   563,   570,   573,   574,   576,   361,   581,   582,   584,
     656, -1018,   587,    16, -1018,   588,   589,   592,   595,   599,
     600,   602,   603, -1018,    33, -1018,   605,   606,   391,   610,
     616,   631,   434, -1018,   -10,   632,   436,   447,   453, -1018,
     307,   633,   657,   -92, -1018,   454,   658,   659,   451,   661,
     459,   462,   662,   663,   463,   470,   664,   666,   668,   670,
     636, -1018,   674,   464,   179, -1018, -1018, -1018,   676,   653,
     686,   687,   688, -1018, -1018, -1018,   477,   478,   479, -1018,
     694,   696,   678, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018,   485, -1018, -1018, -1018, -1018, -1018,
    -133,   488,   489, -1018, -1018, -1018, -1018,   700,   704,   705,
   -1018,   492,   256,   707,   706,   497,   257, -1018, -1018, -1018,
     710,   726,   727,   728,   738, -1018,   742,   746,   751,   752,
     541,   548, -1018, -1018, -1018,   729,   754, -1018,   759,    73,
     168, -1018, -1018, -1018, -1018, -1018,   549,   551,   560,   760,
     565,   566, -1018,   759,   568,   770, -1018,   569, -1018,   759,
     575,   577,   580,   583,   598,   601,   607, -1018,   608,   609,
   -1018,   611,   612,   613, -1018, -1018,   614, -1018, -1018, -1018,
   -1018,   615,   706, -1018, -1018,   617,   618, -1018,   619, -1018,
   -1018,    17,   499, -1018, -1018,  -133,   620,   621,   622, -1018,
     761, -1018, -1018,    38,   196,   179,   171,   287, -1018, -1018,
   -1018,   578,   578,   771, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018,   773,   782,   785, -1018, -1018, -1018, -1018,
   -1018, -1018,   786, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018,   112,   788,   793,   794,    62,    87,   -42,     1,   636,
   -1018, -1018,   796,   -22, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018,   811, -1018, -1018, -1018, -1018,
     214, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,   771,
   -1018,   198,   215,   234, -1018, -1018,   285, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018,   815,   817,   818,   821,   825,   831,
     838,   841,   842,   843, -1018,   844, -1018, -1018, -1018, -1018,
   -1018,   288, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018,   289, -1018,   845,   846, -1018, -1018,
     847,   849, -1018, -1018,   848,   853, -1018, -1018,   851,   855,
   -1018, -1018,   854,   856, -1018, -1018, -1018, -1018, -1018, -1018,
      80, -1018, -1018, -1018, -1018, -1018, -1018, -1018,    98, -1018,
   -1018,   857,   858, -1018, -1018,   859,   861, -1018,   862,   863,
     864,   865,   866,   867,   292, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018,   868,   869,   870, -1018,   301, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,   302, -1018,
   -1018, -1018,   872, -1018,   873, -1018, -1018, -1018,   310, -1018,
   -1018, -1018, -1018, -1018,   324, -1018,   122, -1018,   874,   875,
     876,   877, -1018,   325, -1018, -1018, -1018, -1018, -1018,   643,
   -1018,   878,   879, -1018, -1018, -1018, -1018,   880,   881, -1018,
   -1018, -1018,   882,   885,   287, -1018,   886,   887,   888,   889,
     630,   672,   665,   673,   677,   679,   680,   681,   682,   683,
     892,   684,   894,   901,   902,   903,   578, -1018, -1018,   578,
   -1018,   771,   656, -1018,   773,   -10, -1018,   782,   307, -1018,
     785,  1318, -1018,   786,   112, -1018,   305,   788, -1018,    33,
   -1018,   793,  -110, -1018,   794,   689,   690,   691,   692,   693,
     695,    62, -1018,   697,   698,   701,    87, -1018,   904,   910,
     -42, -1018,   702,   912,   703,   913,     1, -1018, -1018,   124,
     796, -1018,   708,   709,   711,   712,   -22, -1018, -1018,   914,
     919,    16, -1018,   811,   921, -1018, -1018,   713,   716, -1018,
     351,   717,   718,   719, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018,   337, -1018,   720,   721,   722,   723,
   -1018,   326, -1018,   327, -1018,   918, -1018,   920, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018,   339, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,   923,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018,   935,   926, -1018, -1018, -1018, -1018, -1018,
   -1018,   936, -1018,   342, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018,   730,   731, -1018, -1018,
     732, -1018,    38, -1018, -1018,   941, -1018, -1018, -1018, -1018,
   -1018,   345, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018,   733,   346, -1018,   759, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,  1318, -1018,
     942,   943,   734, -1018,   305, -1018, -1018, -1018, -1018, -1018,
   -1018,   944,   737,   949,   124, -1018, -1018, -1018, -1018, -1018,
     735,   740, -1018, -1018,   955, -1018,   743, -1018, -1018, -1018,
     956, -1018, -1018,   139, -1018,  -122,   956, -1018, -1018,   962,
     966,   976, -1018,   352, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018,   977,   764,   777,   778,   995,  -122, -1018,   781, -1018,
   -1018, -1018,   787, -1018, -1018, -1018
  };

  const short
  Dhcp4Parser::yydefact_[] =
  {
       0,     2,     4,     6,     8,    10,    12,    14,    16,    18,
      20,    22,    24,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,    44,
      36,    32,    31,    28,    29,    30,    35,     3,    33,    34,
      59,     5,    65,     7,   206,     9,   384,    11,   602,    13,
     629,    15,   520,    17,   529,    19,   568,    21,   346,    23,
     747,    25,   798,    27,    46,    39,     0,     0,     0,     0,
       0,   631,     0,   531,   570,     0,     0,     0,    48,     0,
      47,     0,     0,    40,    61,     0,    63,   796,   191,   224,
       0,     0,     0,   651,   653,   655,     0,   222,   235,   237,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   149,     0,     0,     0,     0,     0,   160,   167,   169,
       0,     0,     0,     0,   375,   518,   559,     0,   152,   173,
     462,   616,   618,   455,     0,     0,     0,   308,   679,   620,
     337,   358,     0,   323,   714,   728,   745,   180,   182,     0,
       0,     0,   808,   850,     0,   137,     0,    67,    70,    71,
      72,    73,    74,   108,   109,   110,   111,   112,    75,   103,
     134,   135,    92,    93,    94,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   114,   115,   126,   127,   128,
     130,   131,   132,   136,    78,    79,   100,    80,    81,    82,
     129,    86,    87,    76,   105,   106,   107,   104,    77,    84,
      85,    98,    99,   101,    95,    96,    97,    83,    88,    89,
      90,    91,   102,   113,   133,   208,   210,   214,     0,     0,
       0,     0,   205,     0,   193,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   440,   442,   444,   593,   438,   446,
       0,   450,   448,   675,   437,   389,   390,   391,   392,   393,
     417,   418,   419,   420,   421,   435,   407,   408,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   436,     0,   386,   396,   412,   413,   414,   397,   399,
     400,   403,   404,   405,   402,   398,   394,   395,   415,   416,
     401,   409,   410,   411,   406,   614,   613,   609,   610,   608,
       0,   604,   607,   611,   612,   673,   661,   663,   667,   665,
     671,   669,   657,   650,   644,   648,   649,     0,   632,   633,
     645,   646,   647,   641,   636,   642,   638,   639,   640,   643,
     637,     0,   549,   283,     0,   553,   551,   556,     0,   545,
     546,     0,   532,   533,   536,   548,   537,   538,   539,   555,
     540,   541,   542,   543,   544,   586,     0,     0,     0,   584,
     585,   588,   589,     0,   571,   572,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   354,   356,   351,     0,   348,
     352,   353,     0,   784,   771,     0,   774,     0,     0,   778,
     782,     0,     0,   788,   790,   792,   794,   769,   767,   768,
       0,   749,   752,   753,   754,   755,   756,   757,   758,   759,
     764,   760,   761,   762,   763,   765,   766,   805,     0,     0,
     800,   803,   804,    45,    50,     0,    37,    43,     0,    64,
      60,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    58,    69,
      66,     0,     0,     0,     0,     0,     0,     0,   195,   207,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     388,   385,     0,   606,   603,     0,     0,     0,     0,     0,
       0,     0,     0,   630,   635,   521,     0,     0,     0,     0,
       0,     0,     0,   530,   535,     0,     0,     0,     0,   569,
     574,     0,     0,   350,   347,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     751,   748,     0,     0,   802,   799,    49,    41,     0,     0,
       0,     0,     0,   154,   155,   156,     0,     0,     0,   190,
       0,     0,     0,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,     0,   185,   186,   157,   158,   159,
       0,     0,     0,   171,   172,   179,   184,     0,     0,     0,
     151,     0,     0,     0,     0,     0,     0,   452,   453,   454,
       0,     0,     0,     0,     0,   713,     0,     0,     0,     0,
       0,     0,   187,   188,   189,     0,     0,    68,     0,     0,
       0,   218,   219,   220,   221,   194,     0,     0,     0,     0,
       0,     0,   461,     0,     0,     0,   387,     0,   605,     0,
       0,     0,     0,     0,     0,     0,     0,   634,     0,     0,
     547,     0,     0,     0,   558,   534,     0,   590,   591,   592,
     573,     0,     0,   349,   770,     0,     0,   773,     0,   776,
     777,     0,     0,   786,   787,     0,     0,     0,     0,   750,
       0,   807,   801,     0,     0,     0,     0,     0,   652,   654,
     656,     0,     0,   239,   150,   162,   163,   164,   165,   166,
     161,   168,   170,   377,   522,   561,   153,   175,   176,   177,
     178,   174,   464,    38,   617,   619,   457,   458,   459,   460,
     456,     0,     0,   622,   339,     0,     0,     0,     0,     0,
     181,   183,     0,     0,    51,   209,   212,   213,   211,   216,
     217,   215,   441,   443,   445,   595,   439,   447,   451,   449,
       0,   615,   674,   662,   664,   668,   666,   672,   670,   658,
     550,   284,   554,   552,   557,   587,   355,   357,   785,   772,
     775,   780,   781,   779,   783,   789,   791,   793,   795,   239,
      42,     0,     0,     0,   231,   233,     0,   226,   229,   230,
     271,   276,   278,   280,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   294,     0,   300,   302,   304,   306,
     270,     0,   246,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,     0,   244,     0,   240,   241,   382,
       0,   378,   379,   527,     0,   523,   524,   566,     0,   562,
     563,   469,     0,   465,   466,   318,   319,   320,   321,   322,
       0,   310,   313,   314,   315,   316,   317,   684,     0,   681,
     627,     0,   623,   624,   344,     0,   340,   341,     0,     0,
       0,     0,     0,     0,     0,   360,   363,   364,   365,   366,
     367,   368,     0,     0,     0,   333,     0,   325,   328,   329,
     330,   331,   332,   724,   726,   723,   721,   722,     0,   716,
     719,   720,     0,   740,     0,   743,   736,   737,     0,   730,
     733,   734,   735,   738,     0,   813,     0,   810,     0,     0,
       0,     0,   859,     0,   852,   855,   856,   857,   858,    53,
     600,     0,   596,   597,   659,   677,   678,     0,     0,    62,
     797,   192,     0,     0,   228,   225,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   248,   223,   236,     0,
     238,   243,     0,   376,   381,   531,   519,   526,   570,   560,
     565,     0,   463,   468,   312,   309,   686,   683,   680,   631,
     621,   626,     0,   338,   343,     0,     0,     0,     0,     0,
       0,   362,   359,     0,     0,     0,   327,   324,     0,     0,
     718,   715,     0,     0,     0,     0,   732,   729,   746,     0,
     812,   809,     0,     0,     0,     0,   854,   851,    55,     0,
      54,     0,   594,   599,     0,   676,   806,     0,     0,   227,
       0,     0,     0,     0,   282,   285,   286,   287,   288,   289,
     290,   291,   292,   293,     0,   299,     0,     0,     0,     0,
     247,     0,   242,     0,   380,     0,   525,     0,   564,   517,
     492,   493,   494,   477,   478,   497,   498,   499,   500,   501,
     515,   480,   481,   502,   503,   504,   505,   506,   507,   508,
     509,   510,   511,   512,   513,   514,   516,   474,   475,   476,
     490,   491,   487,   488,   489,   486,     0,   471,   479,   495,
     496,   482,   483,   484,   485,   467,   311,   708,   710,     0,
     702,   703,   704,   705,   706,   707,   695,   696,   700,   701,
     697,   698,   699,     0,   687,   688,   691,   692,   693,   694,
     682,     0,   625,     0,   342,   369,   370,   371,   372,   373,
     374,   361,   334,   335,   336,   326,     0,     0,   717,   739,
       0,   742,     0,   731,   828,     0,   826,   824,   818,   822,
     823,     0,   815,   820,   821,   819,   811,   860,   861,   862,
     863,   853,    52,    57,     0,   598,     0,   232,   234,   273,
     274,   275,   272,   277,   279,   281,   296,   297,   298,   295,
     301,   303,   305,   307,   245,   383,   528,   567,   473,   470,
       0,     0,     0,   685,   690,   628,   345,   725,   727,   741,
     744,     0,     0,     0,   817,   814,    56,   601,   660,   472,
       0,     0,   712,   689,     0,   825,     0,   816,   709,   711,
       0,   827,   833,     0,   830,     0,   832,   829,   843,     0,
       0,     0,   848,     0,   835,   838,   839,   840,   841,   842,
     831,     0,     0,     0,     0,     0,   837,   834,     0,   845,
     846,   847,     0,   836,   844,   849
  };

  const short
  Dhcp4Parser::yypgoto_[] =
  {
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018,   -59, -1018,  -595, -1018,   181,
   -1018, -1018, -1018, -1018, -1018, -1018,  -647, -1018, -1018, -1018,
     -67, -1018, -1018, -1018, -1018, -1018, -1018, -1018,   277,   503,
     -28,    -1,    15,   -54,   -39,   -27,    30,    34,    46,    49,
   -1018, -1018, -1018, -1018,    52, -1018, -1018,    53,    54,    57,
      60,    64,    65, -1018,   300,    67, -1018,    68, -1018,    70,
      71,    72, -1018, -1018,    75,    78, -1018,    82, -1018,    83,
   -1018, -1018, -1018, -1018, -1018,    42, -1018, -1018,   297,   487,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,    32,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,   199, -1018,
       4, -1018,  -720,    22, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018,   -40, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
       6, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,   -15,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018,    28, -1018, -1018,
   -1018,     3,   480, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
       8, -1018, -1018, -1018, -1018, -1018, -1018, -1017, -1018, -1018,
   -1018,    36, -1018, -1018, -1018,    93,   525, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1015, -1018,   -53, -1018,   -47,
   -1018,    85,    86,    88,    89, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018,    79, -1018, -1018,  -140,   -62, -1018, -1018, -1018,
   -1018, -1018,    94, -1018, -1018, -1018,    97, -1018,   571, -1018,
     -63, -1018, -1018, -1018, -1018, -1018,   -61, -1018, -1018, -1018,
   -1018, -1018,     0, -1018, -1018, -1018,    96, -1018, -1018, -1018,
      95, -1018,   564, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018,    44, -1018, -1018, -1018,    47,
     596, -1018, -1018,   -49, -1018,   -12, -1018,   -51, -1018, -1018,
   -1018,    92, -1018, -1018, -1018,    99, -1018,   586,    11, -1018,
      27, -1018,    31, -1018,   341, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1003, -1018, -1018, -1018, -1018, -1018,   100, -1018,
   -1018, -1018,  -132, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018,    81, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018,    69, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018,   367,   562, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018,   418,   556, -1018, -1018, -1018, -1018, -1018,
   -1018,    77, -1018, -1018,  -135, -1018, -1018, -1018, -1018, -1018,
   -1018,  -162, -1018, -1018,  -172, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018,    84, -1018, -1018, -1018, -1018
  };

  const short
  Dhcp4Parser::yydefgoto_[] =
  {
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    36,    37,    38,    65,   754,
      82,    83,    39,    64,    79,    80,   775,   979,  1079,  1080,
     850,    41,    66,    85,   438,    86,    43,    67,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   465,   170,   171,   482,   172,   173,   174,   175,
     176,   177,   178,   471,   740,   179,   472,   180,   473,   181,
     182,   183,   483,   751,   184,   185,   501,   186,   502,   187,
     188,   189,   190,   191,   192,   193,   194,   442,   233,   234,
      45,    68,   235,   511,   236,   512,   778,   237,   513,   781,
     238,   239,   240,   241,   195,   451,   196,   443,   826,   827,
     828,   992,   829,   993,   197,   452,   198,   453,   876,   877,
     878,  1019,   851,   852,   853,   996,  1242,   854,   997,   855,
     998,   856,   999,   857,   858,   547,   859,   860,   861,   862,
     863,   864,   865,   866,   867,   868,  1010,  1249,   869,   870,
    1012,   871,  1013,   872,  1014,   873,  1015,   199,   491,   900,
     901,   902,   903,   904,   905,   906,   200,   497,   936,   937,
     938,   939,   940,   201,   494,   915,   916,   917,  1042,    59,
      75,   388,   389,   390,   561,   391,   562,   202,   495,   924,
     925,   926,   927,   928,   929,   930,   931,   203,   478,   880,
     881,   882,  1022,    47,    69,   282,   283,   284,   524,   285,
     520,   286,   521,   287,   522,   288,   525,   289,   528,   290,
     527,   204,   205,   206,   207,   487,   760,   295,   208,   484,
     892,   893,   894,  1031,  1156,  1157,   209,   479,    53,    72,
     884,   885,   886,  1025,    55,    73,   351,   352,   353,   354,
     355,   356,   357,   546,   358,   550,   359,   549,   360,   361,
     551,   362,   210,   480,   888,   889,   890,  1028,    57,    74,
     373,   374,   375,   376,   377,   555,   378,   379,   380,   381,
     382,   297,   523,   981,   982,   983,  1081,    49,    70,   310,
     311,   312,   532,   211,   485,   212,   486,   213,   493,   911,
     912,   913,  1039,    51,    71,   327,   328,   329,   214,   447,
     215,   448,   216,   449,   333,   542,   986,  1084,   334,   536,
     335,   537,   336,   539,   337,   538,   338,   541,   339,   540,
     340,   535,   304,   529,   987,   217,   492,   908,   909,  1036,
    1183,  1184,  1185,  1186,  1187,  1260,  1188,  1261,  1189,   218,
     219,   498,   948,   949,   950,  1058,   951,  1059,   220,   499,
     958,   959,   960,   961,  1063,   962,   963,  1065,   221,   500,
      61,    76,   410,   411,   412,   413,   567,   414,   415,   569,
     416,   417,   418,   572,   813,   419,   573,   420,   566,   421,
     422,   423,   576,   424,   577,   425,   578,   426,   579,   222,
     441,    63,    77,   429,   430,   431,   582,   432,   223,   506,
     966,   967,  1069,  1221,  1222,  1223,  1224,  1273,  1225,  1271,
    1293,  1294,  1295,  1303,  1304,  1305,  1311,  1306,  1307,  1308,
    1309,  1315,   224,   507,   973,   974,   975,   976,   977,   978
  };

  const short
  Dhcp4Parser::yytable_[] =
  {
     155,   232,   254,   306,   323,    78,   349,   369,   387,   407,
     341,   371,   874,   372,  1148,   258,  1149,   307,   300,   242,
     298,   313,   325,   308,   363,   383,   788,   408,  1164,   342,
     259,    40,   792,   350,   370,   811,   385,   386,    81,   753,
      28,   255,   260,    29,   439,    30,    42,    31,   125,   440,
     735,   736,   737,   738,   385,   386,   243,   299,   314,   326,
      84,   364,   384,    44,   409,    93,    94,    95,   256,   296,
     309,   324,  1298,   131,   132,  1299,  1300,  1301,  1302,   434,
     301,    46,   330,  1034,   257,   343,  1035,   344,   345,   739,
     776,   777,   346,   347,   348,   435,   302,    48,   331,   261,
     303,  1037,   332,   262,  1038,   131,   132,   753,   509,   154,
     126,   281,   433,   510,    50,   263,   131,   132,   264,   943,
     944,   265,   266,   267,    52,  1070,   268,   126,  1071,   269,
     305,   131,   132,   270,   271,    54,   272,   273,   518,   274,
     275,   276,  1296,   519,   277,  1297,   251,   278,   131,   132,
     252,   279,   280,    56,   291,   292,   530,   293,   294,   533,
     436,   531,   315,   563,   534,   952,   953,   954,   564,   316,
     317,   318,   319,   320,   321,   437,   322,   154,   444,   580,
     968,   969,   970,   971,   581,    58,   225,   226,   779,   780,
     227,   427,   428,   228,   229,   230,   231,   154,   812,    60,
     584,   509,   131,   132,   445,   585,   989,    87,    62,   154,
      88,   918,   919,   920,   921,   922,   923,   446,   584,   343,
     955,   450,    89,   990,   454,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   154,   455,   518,   543,   131,
     132,  1148,   991,  1149,   932,   933,   934,   456,   895,   896,
     897,   898,   154,   899,   457,  1164,   458,    32,    33,    34,
      35,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   131,   132,   994,   125,
     126,  1016,  1016,   995,   459,  1051,  1017,  1018,   460,  1111,
    1052,   127,   128,   129,  1056,  1060,   154,   461,   130,  1057,
    1061,   131,   132,  1066,   824,   825,   133,  1214,  1067,  1215,
    1216,   134,   135,   136,   137,   138,   462,   580,  1076,  1016,
     530,   139,  1068,  1077,  1254,  1255,   463,    93,    94,    95,
      96,   140,  1258,   154,   141,   563,   544,  1259,  1274,   533,
    1266,   142,   143,  1275,  1277,  1316,   144,   322,   984,   145,
    1317,   464,   466,   146,   747,   748,   749,   750,   467,   468,
     100,   101,   102,   469,   470,   586,   587,   474,   756,   757,
     758,   759,   475,   147,   148,   149,   150,   151,   152,   476,
     154,  1239,  1240,  1241,  1246,  1247,  1248,   153,   125,   126,
     343,   477,   343,   365,   344,   345,   366,   367,   368,   481,
     488,   489,   490,   496,   503,   154,   504,   505,   508,   514,
     131,   132,   131,   132,   515,   516,   517,   526,   588,   548,
     552,   554,   545,   556,   557,   553,  1167,  1168,  1169,   558,
     559,   560,   155,   565,   568,   570,   571,   574,   575,   583,
     589,   232,   590,   591,   592,   593,   596,   594,   595,   597,
     598,   599,   600,   254,   601,   602,   306,   603,   604,   242,
     609,   605,   614,   606,   607,   612,   258,   323,   613,   300,
     307,   298,   608,   610,   313,   611,   308,   349,   615,   616,
     620,   259,   617,   369,   618,   325,   619,   371,   621,   372,
     622,   623,   255,   260,   624,   363,   243,   625,   627,   628,
     629,   383,   631,   407,   350,   626,   630,   632,   299,   633,
     370,   314,   634,   635,   154,   636,   154,   640,   637,   256,
     296,   408,   326,   309,   638,   639,   641,   642,   643,   644,
     645,   301,   364,   646,   324,   257,   647,   648,   384,   649,
     650,   651,   652,   653,   655,   330,   654,   302,   656,   658,
     261,   303,   659,   660,   262,   666,   661,   667,   409,   662,
     663,   331,   281,   664,   668,   332,   263,   669,   670,   264,
     671,   672,   265,   266,   267,   673,   674,   268,   675,  1278,
     269,   677,   679,   680,   270,   271,   681,   272,   273,   682,
     274,   275,   276,   683,   684,   277,   685,   686,   278,   688,
     689,   690,   279,   280,   691,   291,   292,   830,   293,   294,
     692,   831,   832,   833,   834,   835,   836,   837,   838,   839,
     840,   841,   842,   843,   844,   693,   696,   701,   845,   846,
     847,   848,   849,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,   694,   155,   697,   232,
     724,   702,   705,   706,   820,   708,   711,   712,   715,   698,
     716,   707,   717,   343,   718,   699,   704,   242,   720,   709,
     723,   814,   710,   733,   721,   713,    91,    92,    93,    94,
      95,    96,   714,   725,   726,   727,   728,   729,   730,   935,
     945,   731,   407,   732,   734,   743,   972,   741,   742,   744,
     745,   746,   752,    30,   243,   761,   755,   941,   946,   956,
     408,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   762,   763,   764,   772,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   765,   244,   245,   246,   766,
     126,   131,   132,   767,   942,   947,   957,   409,   768,   769,
     770,   773,   128,   129,   774,   785,   819,   771,   782,   247,
     783,   131,   132,   248,   249,   250,   133,   790,   875,   784,
     879,   134,   135,   136,   786,   787,   251,   789,   791,   883,
     252,   139,   887,   891,   793,   907,   794,   154,   253,   795,
     910,   914,   796,   965,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   797,   980,  1000,
     798,  1001,  1002,   405,   406,  1003,   799,   800,   801,  1004,
     802,   803,   804,   805,   806,  1005,   808,   809,   810,   816,
     817,   818,  1006,   147,   148,  1007,  1008,  1009,  1011,  1021,
    1094,  1020,  1024,  1023,  1026,   154,  1027,  1029,  1030,  1033,
    1032,  1041,  1078,  1040,  1044,  1043,  1045,  1046,  1047,  1048,
    1049,  1050,  1053,  1054,  1055,   154,  1062,  1064,  1072,  1073,
    1074,  1075,  1083,   807,  1082,  1096,  1087,  1086,  1085,  1088,
    1090,  1091,  1092,  1093,  1095,  1097,  1104,  1098,  1106,  1099,
    1100,  1101,  1102,  1103,  1105,  1107,  1108,  1109,  1206,  1195,
    1196,  1197,  1198,  1199,  1207,  1200,  1210,  1212,  1203,  1202,
    1232,  1204,  1233,  1211,  1209,  1236,  1256,  1262,  1257,  1264,
    1227,  1228,  1237,  1229,  1230,  1238,  1243,  1244,  1245,  1250,
    1251,  1252,  1253,  1263,  1265,  1272,  1280,  1281,  1284,  1267,
    1268,  1269,  1276,  1286,  1288,   254,  1282,  1285,   349,  1289,
    1290,   369,  1291,  1292,  1119,   371,  1312,   372,   258,  1170,
    1313,   300,   323,   298,  1176,   387,   363,  1123,  1150,   383,
    1314,  1318,  1159,   259,  1151,   350,  1319,  1178,   370,   935,
     325,  1147,  1124,   945,   255,   260,  1175,  1320,  1321,  1322,
    1324,   821,  1217,  1120,  1125,   665,  1325,   941,  1171,   972,
     299,   946,   657,   364,   306,   815,   384,   956,   988,  1160,
    1219,   256,   296,   823,  1179,  1112,  1089,   326,   307,  1218,
    1121,  1158,   313,   301,   308,  1172,  1177,   257,  1110,   324,
    1166,  1205,  1161,   703,   942,  1193,  1122,  1180,   947,   302,
     330,  1173,   261,   303,   957,   676,   262,  1220,  1162,  1201,
    1114,  1126,  1163,  1181,   281,  1127,   331,  1182,   263,   314,
     332,   264,  1194,  1146,   265,   266,   267,  1128,  1174,   268,
    1129,   309,   269,  1130,  1131,  1132,   270,   271,  1133,   272,
     273,  1134,   274,   275,   276,  1135,  1136,   277,  1137,  1138,
     278,  1139,  1140,  1141,   279,   280,  1142,   291,   292,  1143,
     293,   294,  1165,  1144,  1145,  1113,  1152,  1153,  1279,  1154,
    1155,  1116,  1115,  1117,   700,   695,  1118,  1235,  1234,   678,
     687,   985,  1283,  1192,  1310,  1213,   964,  1190,  1191,  1287,
     722,  1208,   719,   822,  1323,     0,     0,  1226,     0,     0,
       0,     0,     0,  1270,     0,     0,     0,     0,     0,     0,
    1231,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1119,     0,     0,     0,     0,     0,  1170,     0,     0,
       0,     0,  1176,     0,  1123,  1150,     0,  1217,     0,  1159,
       0,  1151,     0,     0,     0,  1178,     0,     0,  1147,  1124,
       0,     0,     0,     0,  1175,  1219,     0,     0,     0,     0,
    1120,  1125,     0,     0,  1218,     0,  1171,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1160,     0,     0,     0,
       0,     0,  1179,     0,     0,     0,     0,  1121,  1158,     0,
       0,     0,  1220,  1172,  1177,     0,     0,     0,     0,  1161,
       0,     0,     0,  1122,     0,  1180,     0,     0,     0,  1173,
       0,     0,     0,     0,     0,  1162,     0,     0,  1126,  1163,
       0,  1181,  1127,     0,     0,  1182,     0,     0,     0,     0,
    1146,     0,     0,     0,  1128,     0,  1174,  1129,     0,     0,
    1130,  1131,  1132,     0,     0,  1133,     0,     0,  1134,     0,
       0,     0,  1135,  1136,     0,  1137,  1138,     0,  1139,  1140,
    1141,     0,     0,  1142,     0,     0,  1143,     0,     0,     0,
    1144,  1145,     0,  1152,  1153,     0,  1154,  1155,    91,    92,
      93,    94,    95,    96,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,     0,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,     0,     0,
       0,     0,   126,   343,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   128,   129,     0,     0,     0,     0,
       0,     0,     0,   131,   132,     0,   249,     0,   133,     0,
       0,     0,     0,   134,   135,   136,     0,     0,   251,     0,
       0,     0,   252,     0,     0,     0,     0,     0,     0,     0,
     253,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   147,   148,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   154
  };

  const short
  Dhcp4Parser::yycheck_[] =
  {
      67,    68,    69,    70,    71,    64,    73,    74,    75,    76,
      72,    74,   732,    74,  1031,    69,  1031,    70,    69,    68,
      69,    70,    71,    70,    73,    74,   673,    76,  1031,    39,
      69,     7,   679,    73,    74,    18,   146,   147,   219,   634,
       0,    69,    69,     5,     3,     7,     7,     9,    93,     8,
     183,   184,   185,   186,   146,   147,    68,    69,    70,    71,
      10,    73,    74,     7,    76,    32,    33,    34,    69,    69,
      70,    71,   194,   115,   116,   197,   198,   199,   200,     3,
      69,     7,    71,     3,    69,    95,     6,    97,    98,   222,
      17,    18,   102,   103,   104,     4,    69,     7,    71,    69,
      69,     3,    71,    69,     6,   115,   116,   702,     3,   219,
      94,    69,     6,     8,     7,    69,   115,   116,    69,   161,
     162,    69,    69,    69,     7,     3,    69,    94,     6,    69,
     114,   115,   116,    69,    69,     7,    69,    69,     3,    69,
      69,    69,     3,     8,    69,     6,   130,    69,   115,   116,
     134,    69,    69,     7,    69,    69,     3,    69,    69,     3,
       8,     8,   129,     3,     8,   164,   165,   166,     8,   136,
     137,   138,   139,   140,   141,     3,   143,   219,     4,     3,
     202,   203,   204,   205,     8,     7,    15,    16,    20,    21,
      19,    12,    13,    22,    23,    24,    25,   219,   181,     7,
       3,     3,   115,   116,     4,     8,     8,    11,     7,   219,
      14,   149,   150,   151,   152,   153,   154,     4,     3,    95,
     219,     4,    26,     8,     4,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,   219,     4,     3,     8,   115,
     116,  1258,     8,  1258,   157,   158,   159,     4,   136,   137,
     138,   139,   219,   141,     4,  1258,     4,   219,   220,   221,
     222,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,   115,   116,     3,    93,
      94,     3,     3,     8,     4,     3,     8,     8,     4,  1019,
       8,   105,   106,   107,     3,     3,   219,     4,   112,     8,
       8,   115,   116,     3,    27,    28,   120,   193,     8,   195,
     196,   125,   126,   127,   128,   129,     4,     3,     3,     3,
       3,   135,     8,     8,     8,     8,     4,    32,    33,    34,
      35,   145,     3,   219,   148,     3,     3,     8,     3,     3,
       8,   155,   156,     8,     8,     3,   160,   143,   144,   163,
       8,     4,     4,   167,   108,   109,   110,   111,     4,     4,
      65,    66,    67,     4,     4,   434,   435,     4,   121,   122,
     123,   124,     4,   187,   188,   189,   190,   191,   192,     4,
     219,    40,    41,    42,    57,    58,    59,   201,    93,    94,
      95,     4,    95,    96,    97,    98,    99,   100,   101,     4,
       4,     4,     4,     4,     4,   219,     4,     4,     4,     4,
     115,   116,   115,   116,     4,     4,     4,     4,   219,     4,
       4,     3,     8,     4,     4,     8,   131,   132,   133,     4,
       8,     3,   509,     4,     4,     4,     4,     4,     4,     4,
       4,   518,     4,     4,     4,   222,     4,   222,   222,     4,
       4,   220,     4,   530,     4,     4,   533,   220,   220,   518,
     221,   220,     4,   220,   220,   220,   530,   544,   220,   530,
     533,   530,   222,   221,   533,   221,   533,   554,   220,   220,
       4,   530,   222,   560,   222,   544,   222,   560,     4,   560,
       4,   222,   530,   530,   222,   554,   518,   221,     4,     4,
       4,   560,     4,   580,   554,   222,   220,     4,   530,     4,
     560,   533,     4,     4,   219,     4,   219,     4,   222,   530,
     530,   580,   544,   533,   222,   222,     4,     4,     4,     4,
     220,   530,   554,     4,   544,   530,     4,     4,   560,     4,
       4,     4,   222,   222,     4,   544,   222,   530,     4,     4,
     530,   530,     4,     4,   530,     4,   222,     4,   580,   222,
     220,   544,   530,   220,     4,   544,   530,     4,     4,   530,
       4,   220,   530,   530,   530,     4,     4,   530,     4,  1236,
     530,     4,     4,     4,   530,   530,     4,   530,   530,     4,
     530,   530,   530,     4,     4,   530,     4,     4,   530,     4,
       4,   220,   530,   530,     4,   530,   530,    39,   530,   530,
       4,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,     4,     4,     4,    60,    61,
      62,    63,    64,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   222,   724,   222,   726,
       7,     4,     4,     4,   723,     4,     4,     4,     4,   222,
       4,   220,     4,    95,     4,   222,   222,   726,     4,   220,
       4,   182,   220,     5,   220,   222,    30,    31,    32,    33,
      34,    35,   222,     7,     7,     7,   219,   219,   219,   766,
     767,     7,   769,     7,   219,     5,   773,   219,   219,     5,
       5,   219,     5,     7,   726,     5,   219,   766,   767,   768,
     769,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,     5,     5,     5,     5,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,     7,    90,    91,    92,     7,
      94,   115,   116,     7,   766,   767,   768,   769,     7,     7,
     219,     7,   106,   107,     5,     5,     5,   219,   219,   113,
     219,   115,   116,   117,   118,   119,   120,     7,     7,   219,
       7,   125,   126,   127,   219,   219,   130,   219,   219,     7,
     134,   135,     7,     7,   219,     7,   219,   219,   142,   219,
       7,     7,   219,     7,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   219,     7,     4,
     219,     4,     4,   187,   188,     4,   219,   219,   219,     4,
     219,   219,   219,   219,   219,     4,   219,   219,   219,   219,
     219,   219,     4,   187,   188,     4,     4,     4,     4,     3,
     220,     6,     3,     6,     6,   219,     3,     6,     3,     3,
       6,     3,   219,     6,     3,     6,     4,     4,     4,     4,
       4,     4,     4,     4,     4,   219,     4,     4,     4,     4,
       4,     4,     3,   702,     6,   220,     4,     6,     8,     4,
       4,     4,     4,     4,   222,   222,     4,   220,     4,   220,
     220,   220,   220,   220,   220,     4,     4,     4,     4,   220,
     220,   220,   220,   220,     4,   220,     4,     4,   220,   222,
       6,   220,     3,   220,   222,     4,     8,     4,     8,     3,
     222,   222,   219,   222,   222,   219,   219,   219,   219,   219,
     219,   219,   219,     8,     8,     4,     4,     4,     4,   219,
     219,   219,   219,     4,   219,  1022,   222,   220,  1025,   219,
       5,  1028,   219,     7,  1031,  1028,     4,  1028,  1022,  1036,
       4,  1022,  1039,  1022,  1036,  1042,  1025,  1031,  1031,  1028,
       4,     4,  1031,  1022,  1031,  1025,   222,  1036,  1028,  1056,
    1039,  1031,  1031,  1060,  1022,  1022,  1036,   220,   220,     4,
     219,   724,  1069,  1031,  1031,   518,   219,  1056,  1036,  1076,
    1022,  1060,   509,  1025,  1081,   715,  1028,  1066,   819,  1031,
    1069,  1022,  1022,   726,  1036,  1021,   994,  1039,  1081,  1069,
    1031,  1031,  1081,  1022,  1081,  1036,  1036,  1022,  1016,  1039,
    1034,  1056,  1031,   563,  1056,  1042,  1031,  1036,  1060,  1022,
    1039,  1036,  1022,  1022,  1066,   530,  1022,  1069,  1031,  1051,
    1024,  1031,  1031,  1036,  1022,  1031,  1039,  1036,  1022,  1081,
    1039,  1022,  1044,  1031,  1022,  1022,  1022,  1031,  1036,  1022,
    1031,  1081,  1022,  1031,  1031,  1031,  1022,  1022,  1031,  1022,
    1022,  1031,  1022,  1022,  1022,  1031,  1031,  1022,  1031,  1031,
    1022,  1031,  1031,  1031,  1022,  1022,  1031,  1022,  1022,  1031,
    1022,  1022,  1033,  1031,  1031,  1022,  1031,  1031,  1258,  1031,
    1031,  1027,  1025,  1028,   560,   554,  1030,  1083,  1081,   533,
     544,   790,  1264,  1041,  1296,  1066,   769,  1037,  1039,  1274,
     584,  1060,   580,   725,  1316,    -1,    -1,  1070,    -1,    -1,
      -1,    -1,    -1,  1212,    -1,    -1,    -1,    -1,    -1,    -1,
    1076,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1258,    -1,    -1,    -1,    -1,    -1,  1264,    -1,    -1,
      -1,    -1,  1264,    -1,  1258,  1258,    -1,  1274,    -1,  1258,
      -1,  1258,    -1,    -1,    -1,  1264,    -1,    -1,  1258,  1258,
      -1,    -1,    -1,    -1,  1264,  1274,    -1,    -1,    -1,    -1,
    1258,  1258,    -1,    -1,  1274,    -1,  1264,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1258,    -1,    -1,    -1,
      -1,    -1,  1264,    -1,    -1,    -1,    -1,  1258,  1258,    -1,
      -1,    -1,  1274,  1264,  1264,    -1,    -1,    -1,    -1,  1258,
      -1,    -1,    -1,  1258,    -1,  1264,    -1,    -1,    -1,  1264,
      -1,    -1,    -1,    -1,    -1,  1258,    -1,    -1,  1258,  1258,
      -1,  1264,  1258,    -1,    -1,  1264,    -1,    -1,    -1,    -1,
    1258,    -1,    -1,    -1,  1258,    -1,  1264,  1258,    -1,    -1,
    1258,  1258,  1258,    -1,    -1,  1258,    -1,    -1,  1258,    -1,
      -1,    -1,  1258,  1258,    -1,  1258,  1258,    -1,  1258,  1258,
    1258,    -1,    -1,  1258,    -1,    -1,  1258,    -1,    -1,    -1,
    1258,  1258,    -1,  1258,  1258,    -1,  1258,  1258,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    -1,    -1,    -1,    -1,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    -1,    -1,
      -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   115,   116,    -1,   118,    -1,   120,    -1,
      -1,    -1,    -1,   125,   126,   127,    -1,    -1,   130,    -1,
      -1,    -1,   134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   219
  };

  const short
  Dhcp4Parser::yystos_[] =
  {
       0,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,     0,     5,
       7,     9,   219,   220,   221,   222,   238,   239,   240,   245,
       7,   254,     7,   259,     7,   313,     7,   426,     7,   510,
       7,   526,     7,   461,     7,   467,     7,   491,     7,   402,
       7,   593,     7,   624,   246,   241,   255,   260,   314,   427,
     511,   527,   462,   468,   492,   403,   594,   625,   238,   247,
     248,   219,   243,   244,    10,   256,   258,    11,    14,    26,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    93,    94,   105,   106,   107,
     112,   115,   116,   120,   125,   126,   127,   128,   129,   135,
     145,   148,   155,   156,   160,   163,   167,   187,   188,   189,
     190,   191,   192,   201,   219,   253,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     276,   277,   279,   280,   281,   282,   283,   284,   285,   288,
     290,   292,   293,   294,   297,   298,   300,   302,   303,   304,
     305,   306,   307,   308,   309,   327,   329,   337,   339,   380,
     389,   396,   410,   420,   444,   445,   446,   447,   451,   459,
     485,   516,   518,   520,   531,   533,   535,   558,   572,   573,
     581,   591,   622,   631,   655,    15,    16,    19,    22,    23,
      24,    25,   253,   311,   312,   315,   317,   320,   323,   324,
     325,   326,   516,   518,    90,    91,    92,   113,   117,   118,
     119,   130,   134,   142,   253,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   277,   280,   281,   282,   283,
     284,   285,   288,   290,   292,   293,   294,   297,   298,   300,
     302,   308,   428,   429,   430,   432,   434,   436,   438,   440,
     442,   444,   445,   446,   447,   450,   485,   504,   516,   518,
     520,   531,   533,   535,   555,   114,   253,   440,   442,   485,
     512,   513,   514,   516,   518,   129,   136,   137,   138,   139,
     140,   141,   143,   253,   485,   516,   518,   528,   529,   530,
     531,   533,   535,   537,   541,   543,   545,   547,   549,   551,
     553,   459,    39,    95,    97,    98,   102,   103,   104,   253,
     357,   469,   470,   471,   472,   473,   474,   475,   477,   479,
     481,   482,   484,   516,   518,    96,    99,   100,   101,   253,
     357,   473,   479,   493,   494,   495,   496,   497,   499,   500,
     501,   502,   503,   516,   518,   146,   147,   253,   404,   405,
     406,   408,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   187,   188,   253,   516,   518,
     595,   596,   597,   598,   600,   601,   603,   604,   605,   608,
     610,   612,   613,   614,   616,   618,   620,    12,    13,   626,
     627,   628,   630,     6,     3,     4,     8,     3,   257,     3,
       8,   623,   310,   330,     4,     4,     4,   532,   534,   536,
       4,   328,   338,   340,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,   275,     4,     4,     4,     4,
       4,   286,   289,   291,     4,     4,     4,     4,   421,   460,
     486,     4,   278,   295,   452,   517,   519,   448,     4,     4,
       4,   381,   559,   521,   397,   411,     4,   390,   574,   582,
     592,   299,   301,     4,     4,     4,   632,   656,     4,     3,
       8,   316,   318,   321,     4,     4,     4,     4,     3,     8,
     433,   435,   437,   505,   431,   439,     4,   443,   441,   556,
       3,     8,   515,     3,     8,   554,   542,   544,   548,   546,
     552,   550,   538,     8,     3,     8,   476,   358,     4,   480,
     478,   483,     4,     8,     3,   498,     4,     4,     4,     8,
       3,   407,   409,     3,     8,     4,   611,   599,     4,   602,
       4,     4,   606,   609,     4,     4,   615,   617,   619,   621,
       3,     8,   629,     4,     3,     8,   238,   238,   219,     4,
       4,     4,     4,   222,   222,   222,     4,     4,     4,   220,
       4,     4,     4,   220,   220,   220,   220,   220,   222,   221,
     221,   221,   220,   220,     4,   220,   220,   222,   222,   222,
       4,     4,     4,   222,   222,   221,   222,     4,     4,     4,
     220,     4,     4,     4,     4,     4,     4,   222,   222,   222,
       4,     4,     4,     4,     4,   220,     4,     4,     4,     4,
       4,     4,   222,   222,   222,     4,     4,   262,     4,     4,
       4,   222,   222,   220,   220,   312,     4,     4,     4,     4,
       4,     4,   220,     4,     4,     4,   429,     4,   513,     4,
       4,     4,     4,     4,     4,     4,     4,   530,     4,     4,
     220,     4,     4,     4,   222,   471,     4,   222,   222,   222,
     495,     4,     4,   405,   222,     4,     4,   220,     4,   220,
     220,     4,     4,   222,   222,     4,     4,     4,     4,   596,
       4,   220,   627,     4,     7,     7,     7,     7,   219,   219,
     219,     7,     7,     5,   219,   183,   184,   185,   186,   222,
     287,   219,   219,     5,     5,     5,   219,   108,   109,   110,
     111,   296,     5,   240,   242,   219,   121,   122,   123,   124,
     449,     5,     5,     5,     5,     7,     7,     7,     7,     7,
     219,   219,     5,     7,     5,   249,    17,    18,   319,    20,
      21,   322,   219,   219,   219,     5,   219,   219,   249,   219,
       7,   219,   249,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   242,   219,   219,
     219,    18,   181,   607,   182,   287,   219,   219,   219,     5,
     238,   261,   626,   311,    27,    28,   331,   332,   333,   335,
      39,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    60,    61,    62,    63,    64,
     253,   345,   346,   347,   350,   352,   354,   356,   357,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   371,
     372,   374,   376,   378,   345,     7,   341,   342,   343,     7,
     422,   423,   424,     7,   463,   464,   465,     7,   487,   488,
     489,     7,   453,   454,   455,   136,   137,   138,   139,   141,
     382,   383,   384,   385,   386,   387,   388,     7,   560,   561,
       7,   522,   523,   524,     7,   398,   399,   400,   149,   150,
     151,   152,   153,   154,   412,   413,   414,   415,   416,   417,
     418,   419,   157,   158,   159,   253,   391,   392,   393,   394,
     395,   516,   518,   161,   162,   253,   516,   518,   575,   576,
     577,   579,   164,   165,   166,   219,   516,   518,   583,   584,
     585,   586,   588,   589,   595,     7,   633,   634,   202,   203,
     204,   205,   253,   657,   658,   659,   660,   661,   662,   250,
       7,   506,   507,   508,   144,   537,   539,   557,   341,     8,
       8,     8,   334,   336,     3,     8,   348,   351,   353,   355,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
     369,     4,   373,   375,   377,   379,     3,     8,     8,   344,
       6,     3,   425,     6,     3,   466,     6,     3,   490,     6,
       3,   456,     6,     3,     3,     6,   562,     3,     6,   525,
       6,     3,   401,     6,     3,     4,     4,     4,     4,     4,
       4,     3,     8,     4,     4,     4,     3,     8,   578,   580,
       3,     8,     4,   587,     4,   590,     3,     8,     8,   635,
       3,     6,     4,     4,     4,     4,     3,     8,   219,   251,
     252,   509,     6,     3,   540,     8,     6,     4,     4,   332,
       4,     4,     4,     4,   220,   222,   220,   222,   220,   220,
     220,   220,   220,   220,     4,   220,     4,     4,     4,     4,
     346,   345,   343,   428,   424,   469,   465,   493,   489,   253,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     277,   280,   281,   282,   283,   284,   285,   288,   290,   292,
     293,   294,   297,   298,   300,   302,   308,   357,   420,   438,
     440,   442,   444,   445,   446,   447,   457,   458,   485,   516,
     518,   531,   533,   535,   555,   455,   383,   131,   132,   133,
     253,   263,   264,   265,   308,   357,   459,   485,   516,   518,
     531,   533,   535,   563,   564,   565,   566,   567,   569,   571,
     561,   528,   524,   404,   400,   220,   220,   220,   220,   220,
     220,   413,   222,   220,   220,   392,     4,     4,   576,   222,
       4,   220,     4,   584,   193,   195,   196,   253,   357,   516,
     518,   636,   637,   638,   639,   641,   634,   222,   222,   222,
     222,   658,     6,     3,   512,   508,     4,   219,   219,    40,
      41,    42,   349,   219,   219,   219,    57,    58,    59,   370,
     219,   219,   219,   219,     8,     8,     8,     8,     3,     8,
     568,   570,     4,     8,     3,     8,     8,   219,   219,   219,
     238,   642,     4,   640,     3,     8,   219,     8,   249,   458,
       4,     4,   222,   565,     4,   220,     4,   637,   219,   219,
       5,   219,     7,   643,   644,   645,     3,     6,   194,   197,
     198,   199,   200,   646,   647,   648,   650,   651,   652,   653,
     644,   649,     4,     4,     4,   654,     3,     8,     4,   222,
     220,   220,     4,   647,   219,   219
  };

  const short
  Dhcp4Parser::yyr1_[] =
  {
       0,   223,   225,   224,   226,   224,   227,   224,   228,   224,
     229,   224,   230,   224,   231,   224,   232,   224,   233,   224,
     234,   224,   235,   224,   236,   224,   237,   224,   238,   238,
     238,   238,   238,   238,   238,   239,   241,   240,   242,   243,
     243,   244,   244,   244,   246,   245,   247,   247,   248,   248,
     248,   250,   249,   251,   251,   252,   252,   252,   253,   255,
     254,   257,   256,   256,   258,   260,   259,   261,   261,   261,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   275,
     274,   276,   278,   277,   279,   280,   281,   282,   283,   284,
     286,   285,   287,   287,   287,   287,   287,   289,   288,   291,
     290,   292,   293,   295,   294,   296,   296,   296,   296,   297,
     299,   298,   301,   300,   302,   303,   304,   305,   306,   307,
     308,   310,   309,   311,   311,   311,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   314,   313,   316,   315,
     318,   317,   319,   319,   321,   320,   322,   322,   323,   324,
     325,   326,   328,   327,   330,   329,   331,   331,   331,   332,
     332,   334,   333,   336,   335,   338,   337,   340,   339,   341,
     341,   342,   342,   342,   344,   343,   345,   345,   345,   346,
     346,   346,   346,   346,   346,   346,   346,   346,   346,   346,
     346,   346,   346,   346,   346,   346,   346,   346,   346,   346,
     346,   348,   347,   349,   349,   349,   351,   350,   353,   352,
     355,   354,   356,   358,   357,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   369,   368,   370,   370,   370,   371,
     373,   372,   375,   374,   377,   376,   379,   378,   381,   380,
     382,   382,   382,   383,   383,   383,   383,   383,   384,   385,
     386,   387,   388,   390,   389,   391,   391,   391,   392,   392,
     392,   392,   392,   392,   393,   394,   395,   397,   396,   398,
     398,   399,   399,   399,   401,   400,   403,   402,   404,   404,
     404,   404,   405,   405,   407,   406,   409,   408,   411,   410,
     412,   412,   412,   413,   413,   413,   413,   413,   413,   414,
     415,   416,   417,   418,   419,   421,   420,   422,   422,   423,
     423,   423,   425,   424,   427,   426,   428,   428,   428,   429,
     429,   429,   429,   429,   429,   429,   429,   429,   429,   429,
     429,   429,   429,   429,   429,   429,   429,   429,   429,   429,
     429,   429,   429,   429,   429,   429,   429,   429,   429,   429,
     429,   429,   429,   429,   429,   429,   429,   429,   429,   429,
     429,   429,   429,   429,   429,   429,   429,   429,   431,   430,
     433,   432,   435,   434,   437,   436,   439,   438,   441,   440,
     443,   442,   444,   445,   446,   448,   447,   449,   449,   449,
     449,   450,   452,   451,   453,   453,   454,   454,   454,   456,
     455,   457,   457,   457,   458,   458,   458,   458,   458,   458,
     458,   458,   458,   458,   458,   458,   458,   458,   458,   458,
     458,   458,   458,   458,   458,   458,   458,   458,   458,   458,
     458,   458,   458,   458,   458,   458,   458,   458,   458,   458,
     458,   458,   458,   458,   458,   458,   458,   458,   460,   459,
     462,   461,   463,   463,   464,   464,   464,   466,   465,   468,
     467,   469,   469,   470,   470,   470,   471,   471,   471,   471,
     471,   471,   471,   471,   471,   471,   472,   473,   474,   476,
     475,   478,   477,   480,   479,   481,   483,   482,   484,   486,
     485,   487,   487,   488,   488,   488,   490,   489,   492,   491,
     493,   493,   494,   494,   494,   495,   495,   495,   495,   495,
     495,   495,   495,   495,   495,   496,   498,   497,   499,   500,
     501,   502,   503,   505,   504,   506,   506,   507,   507,   507,
     509,   508,   511,   510,   512,   512,   512,   513,   513,   513,
     513,   513,   513,   513,   515,   514,   517,   516,   519,   518,
     521,   520,   522,   522,   523,   523,   523,   525,   524,   527,
     526,   528,   528,   529,   529,   529,   530,   530,   530,   530,
     530,   530,   530,   530,   530,   530,   530,   530,   530,   530,
     530,   532,   531,   534,   533,   536,   535,   538,   537,   540,
     539,   542,   541,   544,   543,   546,   545,   548,   547,   550,
     549,   552,   551,   554,   553,   556,   555,   557,   557,   559,
     558,   560,   560,   560,   562,   561,   563,   563,   564,   564,
     564,   565,   565,   565,   565,   565,   565,   565,   565,   565,
     565,   565,   565,   565,   565,   565,   565,   566,   568,   567,
     570,   569,   571,   572,   574,   573,   575,   575,   575,   576,
     576,   576,   576,   576,   578,   577,   580,   579,   582,   581,
     583,   583,   583,   584,   584,   584,   584,   584,   584,   585,
     587,   586,   588,   590,   589,   592,   591,   594,   593,   595,
     595,   595,   596,   596,   596,   596,   596,   596,   596,   596,
     596,   596,   596,   596,   596,   596,   596,   596,   596,   596,
     597,   599,   598,   600,   602,   601,   603,   604,   606,   605,
     607,   607,   609,   608,   611,   610,   612,   613,   615,   614,
     617,   616,   619,   618,   621,   620,   623,   622,   625,   624,
     626,   626,   626,   627,   627,   629,   628,   630,   632,   631,
     633,   633,   633,   635,   634,   636,   636,   636,   637,   637,
     637,   637,   637,   637,   637,   638,   640,   639,   642,   641,
     643,   643,   643,   645,   644,   646,   646,   646,   647,   647,
     647,   647,   647,   649,   648,   650,   651,   652,   654,   653,
     656,   655,   657,   657,   657,   658,   658,   658,   658,   658,
     659,   660,   661,   662
  };

  const signed char
  Dhcp4Parser::yyr2_[] =
  {
       0,     2,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     4,     1,     0,
       1,     3,     5,     2,     0,     4,     0,     1,     1,     3,
       2,     0,     4,     0,     1,     1,     3,     2,     2,     0,
       4,     0,     6,     1,     2,     0,     4,     1,     3,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     0,
       4,     3,     0,     4,     3,     3,     3,     3,     3,     3,
       0,     4,     1,     1,     1,     1,     1,     0,     4,     0,
       4,     3,     3,     0,     4,     1,     1,     1,     1,     3,
       0,     4,     0,     4,     3,     3,     3,     3,     3,     3,
       3,     0,     6,     1,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     4,     0,     4,
       0,     4,     1,     1,     0,     4,     1,     1,     3,     3,
       3,     3,     0,     6,     0,     6,     1,     3,     2,     1,
       1,     0,     4,     0,     4,     0,     6,     0,     6,     0,
       1,     1,     3,     2,     0,     4,     1,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     4,     1,     1,     1,     0,     4,     0,     4,
       0,     4,     3,     0,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     0,     4,     1,     1,     1,     3,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     6,
       1,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     6,     1,     3,     2,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     0,     6,     0,
       1,     1,     3,     2,     0,     4,     0,     4,     1,     3,
       2,     1,     1,     1,     0,     4,     0,     4,     0,     6,
       1,     3,     2,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     0,     6,     0,     1,     1,
       3,     2,     0,     4,     0,     4,     1,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     3,     3,     3,     0,     4,     1,     1,     1,
       1,     3,     0,     6,     0,     1,     1,     3,     2,     0,
       4,     1,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     6,
       0,     4,     0,     1,     1,     3,     2,     0,     4,     0,
       4,     0,     1,     1,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     0,
       4,     0,     4,     0,     4,     1,     0,     4,     3,     0,
       6,     0,     1,     1,     3,     2,     0,     4,     0,     4,
       0,     1,     1,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     4,     1,     1,
       3,     3,     3,     0,     6,     0,     1,     1,     3,     2,
       0,     4,     0,     4,     1,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     0,     4,     0,     4,     0,     4,
       0,     6,     0,     1,     1,     3,     2,     0,     4,     0,
       4,     0,     1,     1,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     6,     1,     1,     0,
       6,     1,     3,     2,     0,     4,     0,     1,     1,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     4,
       0,     4,     3,     3,     0,     6,     1,     3,     2,     1,
       1,     1,     1,     1,     0,     4,     0,     4,     0,     6,
       1,     3,     2,     1,     1,     1,     1,     1,     1,     3,
       0,     4,     3,     0,     4,     0,     6,     0,     4,     1,
       3,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     0,     4,     3,     0,     4,     3,     3,     0,     4,
       1,     1,     0,     4,     0,     4,     3,     3,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     6,     0,     4,
       1,     3,     2,     1,     1,     0,     6,     3,     0,     6,
       1,     3,     2,     0,     4,     1,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     3,     0,     4,     0,     6,
       1,     3,     2,     0,     4,     1,     3,     2,     1,     1,
       1,     1,     1,     0,     4,     3,     3,     3,     0,     4,
       0,     6,     1,     3,     2,     1,     1,     1,     1,     1,
       3,     3,     3,     3
  };


#if PARSER4_DEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Dhcp4Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "\",\"", "\":\"",
  "\"[\"", "\"]\"", "\"{\"", "\"}\"", "\"null\"", "\"Dhcp4\"",
  "\"config-control\"", "\"config-databases\"",
  "\"config-fetch-wait-time\"", "\"interfaces-config\"", "\"interfaces\"",
  "\"dhcp-socket-type\"", "\"raw\"", "\"udp\"", "\"outbound-interface\"",
  "\"same-as-inbound\"", "\"use-routing\"", "\"re-detect\"",
  "\"service-sockets-require-all\"", "\"service-sockets-retry-wait-time\"",
  "\"service-sockets-max-retries\"", "\"sanity-checks\"",
  "\"lease-checks\"", "\"extended-info-checks\"", "\"echo-client-id\"",
  "\"match-client-id\"", "\"authoritative\"", "\"next-server\"",
  "\"server-hostname\"", "\"boot-file-name\"", "\"offer-lifetime\"",
  "\"lease-database\"", "\"hosts-database\"", "\"hosts-databases\"",
  "\"type\"", "\"memfile\"", "\"mysql\"", "\"postgresql\"", "\"user\"",
  "\"password\"", "\"host\"", "\"port\"", "\"persist\"",
  "\"lfc-interval\"", "\"readonly\"", "\"connect-timeout\"",
  "\"read-timeout\"", "\"write-timeout\"", "\"tcp-user-timeout\"",
  "\"max-reconnect-tries\"", "\"reconnect-wait-time\"", "\"on-fail\"",
  "\"stop-retry-exit\"", "\"serve-retry-exit\"",
  "\"serve-retry-continue\"", "\"max-row-errors\"", "\"trust-anchor\"",
  "\"cert-file\"", "\"key-file\"", "\"cipher-list\"", "\"valid-lifetime\"",
  "\"min-valid-lifetime\"", "\"max-valid-lifetime\"", "\"renew-timer\"",
  "\"rebind-timer\"", "\"calculate-tee-times\"", "\"t1-percent\"",
  "\"t2-percent\"", "\"cache-threshold\"", "\"cache-max-age\"",
  "\"decline-probation-period\"", "\"server-tag\"",
  "\"statistic-default-sample-count\"", "\"statistic-default-sample-age\"",
  "\"ddns-send-updates\"", "\"ddns-override-no-update\"",
  "\"ddns-override-client-update\"", "\"ddns-replace-client-name\"",
  "\"ddns-generated-prefix\"", "\"ddns-qualifying-suffix\"",
  "\"ddns-update-on-renew\"", "\"ddns-use-conflict-resolution\"",
  "\"ddns-ttl-percent\"", "\"store-extended-info\"", "\"subnet4\"",
  "\"4o6-interface\"", "\"4o6-interface-id\"", "\"4o6-subnet\"",
  "\"option-def\"", "\"option-data\"", "\"name\"", "\"data\"", "\"code\"",
  "\"space\"", "\"csv-format\"", "\"always-send\"", "\"never-send\"",
  "\"record-types\"", "\"encapsulate\"", "\"array\"",
  "\"parked-packet-limit\"", "\"allocator\"",
  "\"ddns-conflict-resolution-mode\"", "\"check-with-dhcid\"",
  "\"no-check-with-dhcid\"", "\"check-exists-with-dhcid\"",
  "\"no-check-without-dhcid\"", "\"shared-networks\"", "\"pools\"",
  "\"pool\"", "\"user-context\"", "\"comment\"", "\"subnet\"",
  "\"interface\"", "\"id\"", "\"reservation-mode\"", "\"disabled\"",
  "\"out-of-pool\"", "\"global\"", "\"all\"", "\"reservations-global\"",
  "\"reservations-in-subnet\"", "\"reservations-out-of-pool\"",
  "\"host-reservation-identifiers\"", "\"client-classes\"",
  "\"require-client-classes\"", "\"test\"", "\"template-test\"",
  "\"only-if-required\"", "\"client-class\"", "\"reservations\"",
  "\"duid\"", "\"hw-address\"", "\"circuit-id\"", "\"client-id\"",
  "\"hostname\"", "\"flex-id\"", "\"relay\"", "\"ip-address\"",
  "\"ip-addresses\"", "\"hooks-libraries\"", "\"library\"",
  "\"parameters\"", "\"expired-leases-processing\"",
  "\"reclaim-timer-wait-time\"", "\"flush-reclaimed-timer-wait-time\"",
  "\"hold-reclaimed-time\"", "\"max-reclaim-leases\"",
  "\"max-reclaim-time\"", "\"unwarned-reclaim-cycles\"",
  "\"dhcp4o6-port\"", "\"multi-threading\"", "\"enable-multi-threading\"",
  "\"thread-pool-size\"", "\"packet-queue-size\"", "\"control-socket\"",
  "\"socket-type\"", "\"socket-name\"", "\"dhcp-queue-control\"",
  "\"enable-queue\"", "\"queue-type\"", "\"capacity\"", "\"dhcp-ddns\"",
  "\"enable-updates\"", "\"qualifying-suffix\"", "\"server-ip\"",
  "\"server-port\"", "\"sender-ip\"", "\"sender-port\"",
  "\"max-queue-size\"", "\"ncr-protocol\"", "\"ncr-format\"",
  "\"override-no-update\"", "\"override-client-update\"",
  "\"replace-client-name\"", "\"generated-prefix\"", "\"tcp\"", "\"JSON\"",
  "\"when-present\"", "\"never\"", "\"always\"", "\"when-not-present\"",
  "\"hostname-char-set\"", "\"hostname-char-replacement\"",
  "\"early-global-reservations-lookup\"", "\"ip-reservations-unique\"",
  "\"reservations-lookup-first\"", "\"loggers\"", "\"output_options\"",
  "\"output\"", "\"debuglevel\"", "\"severity\"", "\"flush\"",
  "\"maxsize\"", "\"maxver\"", "\"pattern\"", "\"compatibility\"",
  "\"lenient-option-parsing\"", "\"ignore-dhcp-server-identifier\"",
  "\"ignore-rai-link-selection\"", "\"exclude-first-last-24\"",
  "TOPLEVEL_JSON", "TOPLEVEL_DHCP4", "SUB_DHCP4", "SUB_INTERFACES4",
  "SUB_SUBNET4", "SUB_POOL4", "SUB_RESERVATION", "SUB_OPTION_DEFS",
  "SUB_OPTION_DEF", "SUB_OPTION_DATA", "SUB_HOOKS_LIBRARY",
  "SUB_DHCP_DDNS", "SUB_CONFIG_CONTROL", "\"constant string\"",
  "\"integer\"", "\"floating point\"", "\"boolean\"", "$accept", "start",
  "$@1", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9", "$@10",
  "$@11", "$@12", "$@13", "value", "sub_json", "map2", "$@14", "map_value",
  "map_content", "not_empty_map", "list_generic", "$@15", "list_content",
  "not_empty_list", "list_strings", "$@16", "list_strings_content",
  "not_empty_list_strings", "unknown_map_entry", "syntax_map", "$@17",
  "global_object", "$@18", "global_object_comma", "sub_dhcp4", "$@19",
  "global_params", "global_param", "valid_lifetime", "min_valid_lifetime",
  "max_valid_lifetime", "renew_timer", "rebind_timer",
  "calculate_tee_times", "t1_percent", "t2_percent", "cache_threshold",
  "cache_max_age", "decline_probation_period", "server_tag", "$@20",
  "parked_packet_limit", "allocator", "$@21", "echo_client_id",
  "match_client_id", "authoritative", "ddns_send_updates",
  "ddns_override_no_update", "ddns_override_client_update",
  "ddns_replace_client_name", "$@22", "ddns_replace_client_name_value",
  "ddns_generated_prefix", "$@23", "ddns_qualifying_suffix", "$@24",
  "ddns_update_on_renew", "ddns_use_conflict_resolution",
  "ddns_conflict_resolution_mode", "$@25",
  "ddns_conflict_resolution_mode_value", "ddns_ttl_percent",
  "hostname_char_set", "$@26", "hostname_char_replacement", "$@27",
  "store_extended_info", "statistic_default_sample_count",
  "statistic_default_sample_age", "early_global_reservations_lookup",
  "ip_reservations_unique", "reservations_lookup_first", "offer_lifetime",
  "interfaces_config", "$@28", "interfaces_config_params",
  "interfaces_config_param", "sub_interfaces4", "$@29", "interfaces_list",
  "$@30", "dhcp_socket_type", "$@31", "socket_type", "outbound_interface",
  "$@32", "outbound_interface_value", "re_detect",
  "service_sockets_require_all", "service_sockets_retry_wait_time",
  "service_sockets_max_retries", "lease_database", "$@33", "sanity_checks",
  "$@34", "sanity_checks_params", "sanity_checks_param", "lease_checks",
  "$@35", "extended_info_checks", "$@36", "hosts_database", "$@37",
  "hosts_databases", "$@38", "database_list", "not_empty_database_list",
  "database", "$@39", "database_map_params", "database_map_param",
  "database_type", "$@40", "db_type", "user", "$@41", "password", "$@42",
  "host", "$@43", "port", "name", "$@44", "persist", "lfc_interval",
  "readonly", "connect_timeout", "read_timeout", "write_timeout",
  "tcp_user_timeout", "max_reconnect_tries", "reconnect_wait_time",
  "on_fail", "$@45", "on_fail_mode", "max_row_errors", "trust_anchor",
  "$@46", "cert_file", "$@47", "key_file", "$@48", "cipher_list", "$@49",
  "host_reservation_identifiers", "$@50",
  "host_reservation_identifiers_list", "host_reservation_identifier",
  "duid_id", "hw_address_id", "circuit_id", "client_id", "flex_id",
  "dhcp_multi_threading", "$@51", "multi_threading_params",
  "multi_threading_param", "enable_multi_threading", "thread_pool_size",
  "packet_queue_size", "hooks_libraries", "$@52", "hooks_libraries_list",
  "not_empty_hooks_libraries_list", "hooks_library", "$@53",
  "sub_hooks_library", "$@54", "hooks_params", "hooks_param", "library",
  "$@55", "parameters", "$@56", "expired_leases_processing", "$@57",
  "expired_leases_params", "expired_leases_param",
  "reclaim_timer_wait_time", "flush_reclaimed_timer_wait_time",
  "hold_reclaimed_time", "max_reclaim_leases", "max_reclaim_time",
  "unwarned_reclaim_cycles", "subnet4_list", "$@58",
  "subnet4_list_content", "not_empty_subnet4_list", "subnet4", "$@59",
  "sub_subnet4", "$@60", "subnet4_params", "subnet4_param", "subnet",
  "$@61", "subnet_4o6_interface", "$@62", "subnet_4o6_interface_id",
  "$@63", "subnet_4o6_subnet", "$@64", "interface", "$@65", "client_class",
  "$@66", "require_client_classes", "$@67", "reservations_global",
  "reservations_in_subnet", "reservations_out_of_pool", "reservation_mode",
  "$@68", "hr_mode", "id", "shared_networks", "$@69",
  "shared_networks_content", "shared_networks_list", "shared_network",
  "$@70", "shared_network_params", "shared_network_param",
  "option_def_list", "$@71", "sub_option_def_list", "$@72",
  "option_def_list_content", "not_empty_option_def_list",
  "option_def_entry", "$@73", "sub_option_def", "$@74",
  "option_def_params", "not_empty_option_def_params", "option_def_param",
  "option_def_name", "code", "option_def_code", "option_def_type", "$@75",
  "option_def_record_types", "$@76", "space", "$@77", "option_def_space",
  "option_def_encapsulate", "$@78", "option_def_array", "option_data_list",
  "$@79", "option_data_list_content", "not_empty_option_data_list",
  "option_data_entry", "$@80", "sub_option_data", "$@81",
  "option_data_params", "not_empty_option_data_params",
  "option_data_param", "option_data_name", "option_data_data", "$@82",
  "option_data_code", "option_data_space", "option_data_csv_format",
  "option_data_always_send", "option_data_never_send", "pools_list",
  "$@83", "pools_list_content", "not_empty_pools_list", "pool_list_entry",
  "$@84", "sub_pool4", "$@85", "pool_params", "pool_param", "pool_entry",
  "$@86", "user_context", "$@87", "comment", "$@88", "reservations",
  "$@89", "reservations_list", "not_empty_reservations_list",
  "reservation", "$@90", "sub_reservation", "$@91", "reservation_params",
  "not_empty_reservation_params", "reservation_param", "next_server",
  "$@92", "server_hostname", "$@93", "boot_file_name", "$@94",
  "ip_address", "$@95", "ip_addresses", "$@96", "duid", "$@97",
  "hw_address", "$@98", "client_id_value", "$@99", "circuit_id_value",
  "$@100", "flex_id_value", "$@101", "hostname", "$@102",
  "reservation_client_classes", "$@103", "relay", "$@104", "relay_map",
  "client_classes", "$@105", "client_classes_list", "client_class_entry",
  "$@106", "client_class_params", "not_empty_client_class_params",
  "client_class_param", "client_class_name", "client_class_test", "$@107",
  "client_class_template_test", "$@108", "only_if_required",
  "dhcp4o6_port", "control_socket", "$@109", "control_socket_params",
  "control_socket_param", "control_socket_type", "$@110",
  "control_socket_name", "$@111", "dhcp_queue_control", "$@112",
  "queue_control_params", "queue_control_param", "enable_queue",
  "queue_type", "$@113", "capacity", "arbitrary_map_entry", "$@114",
  "dhcp_ddns", "$@115", "sub_dhcp_ddns", "$@116", "dhcp_ddns_params",
  "dhcp_ddns_param", "enable_updates", "server_ip", "$@117", "server_port",
  "sender_ip", "$@118", "sender_port", "max_queue_size", "ncr_protocol",
  "$@119", "ncr_protocol_value", "ncr_format", "$@120",
  "dep_qualifying_suffix", "$@121", "dep_override_no_update",
  "dep_override_client_update", "dep_replace_client_name", "$@122",
  "dep_generated_prefix", "$@123", "dep_hostname_char_set", "$@124",
  "dep_hostname_char_replacement", "$@125", "config_control", "$@126",
  "sub_config_control", "$@127", "config_control_params",
  "config_control_param", "config_databases", "$@128",
  "config_fetch_wait_time", "loggers", "$@129", "loggers_entries",
  "logger_entry", "$@130", "logger_params", "logger_param", "debuglevel",
  "severity", "$@131", "output_options_list", "$@132",
  "output_options_list_content", "output_entry", "$@133",
  "output_params_list", "output_params", "output", "$@134", "flush",
  "maxsize", "maxver", "pattern", "$@135", "compatibility", "$@136",
  "compatibility_params", "compatibility_param", "lenient_option_parsing",
  "ignore_dhcp_server_identifier", "ignore_rai_link_selection",
  "exclude_first_last_24", YY_NULLPTR
  };
#endif


#if PARSER4_DEBUG
  const short
  Dhcp4Parser::yyrline_[] =
  {
       0,   318,   318,   318,   319,   319,   320,   320,   321,   321,
     322,   322,   323,   323,   324,   324,   325,   325,   326,   326,
     327,   327,   328,   328,   329,   329,   330,   330,   338,   339,
     340,   341,   342,   343,   344,   347,   352,   352,   363,   366,
     367,   370,   375,   381,   386,   386,   393,   394,   397,   401,
     405,   411,   411,   418,   419,   422,   426,   430,   440,   449,
     449,   464,   464,   478,   481,   487,   487,   496,   497,   498,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   575,   581,
     587,   593,   599,   605,   611,   617,   623,   629,   635,   641,
     641,   650,   656,   656,   665,   671,   677,   683,   689,   695,
     701,   701,   710,   713,   716,   719,   722,   728,   728,   737,
     737,   746,   752,   758,   758,   767,   770,   773,   776,   781,
     787,   787,   796,   796,   805,   811,   817,   823,   829,   835,
     841,   847,   847,   859,   860,   861,   866,   867,   868,   869,
     870,   871,   872,   873,   874,   875,   878,   878,   887,   887,
     898,   898,   906,   907,   910,   910,   918,   920,   924,   930,
     936,   942,   948,   948,   961,   961,   972,   973,   974,   979,
     980,   983,   983,  1002,  1002,  1020,  1020,  1033,  1033,  1044,
    1045,  1048,  1049,  1050,  1055,  1055,  1065,  1066,  1067,  1072,
    1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,
    1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,
    1093,  1096,  1096,  1104,  1105,  1106,  1109,  1109,  1118,  1118,
    1127,  1127,  1136,  1142,  1142,  1151,  1157,  1163,  1169,  1175,
    1181,  1187,  1193,  1199,  1205,  1205,  1213,  1214,  1215,  1218,
    1224,  1224,  1233,  1233,  1242,  1242,  1251,  1251,  1260,  1260,
    1271,  1272,  1273,  1278,  1279,  1280,  1281,  1282,  1285,  1290,
    1295,  1300,  1305,  1312,  1312,  1325,  1326,  1327,  1332,  1333,
    1334,  1335,  1336,  1337,  1340,  1346,  1352,  1358,  1358,  1369,
    1370,  1373,  1374,  1375,  1380,  1380,  1390,  1390,  1400,  1401,
    1402,  1405,  1408,  1409,  1412,  1412,  1421,  1421,  1430,  1430,
    1442,  1443,  1444,  1449,  1450,  1451,  1452,  1453,  1454,  1457,
    1463,  1469,  1475,  1481,  1487,  1496,  1496,  1510,  1511,  1514,
    1515,  1516,  1525,  1525,  1551,  1551,  1562,  1563,  1564,  1570,
    1571,  1572,  1573,  1574,  1575,  1576,  1577,  1578,  1579,  1580,
    1581,  1582,  1583,  1584,  1585,  1586,  1587,  1588,  1589,  1590,
    1591,  1592,  1593,  1594,  1595,  1596,  1597,  1598,  1599,  1600,
    1601,  1602,  1603,  1604,  1605,  1606,  1607,  1608,  1609,  1610,
    1611,  1612,  1613,  1614,  1615,  1616,  1617,  1618,  1621,  1621,
    1630,  1630,  1639,  1639,  1648,  1648,  1657,  1657,  1666,  1666,
    1675,  1675,  1686,  1692,  1698,  1704,  1704,  1712,  1713,  1714,
    1715,  1718,  1726,  1726,  1738,  1739,  1743,  1744,  1745,  1750,
    1750,  1758,  1759,  1760,  1765,  1766,  1767,  1768,  1769,  1770,
    1771,  1772,  1773,  1774,  1775,  1776,  1777,  1778,  1779,  1780,
    1781,  1782,  1783,  1784,  1785,  1786,  1787,  1788,  1789,  1790,
    1791,  1792,  1793,  1794,  1795,  1796,  1797,  1798,  1799,  1800,
    1801,  1802,  1803,  1804,  1805,  1806,  1807,  1808,  1815,  1815,
    1829,  1829,  1838,  1839,  1842,  1843,  1844,  1851,  1851,  1866,
    1866,  1880,  1881,  1884,  1885,  1886,  1891,  1892,  1893,  1894,
    1895,  1896,  1897,  1898,  1899,  1900,  1903,  1905,  1911,  1913,
    1913,  1922,  1922,  1931,  1931,  1940,  1942,  1942,  1951,  1961,
    1961,  1974,  1975,  1980,  1981,  1982,  1989,  1989,  2001,  2001,
    2013,  2014,  2019,  2020,  2021,  2028,  2029,  2030,  2031,  2032,
    2033,  2034,  2035,  2036,  2037,  2040,  2042,  2042,  2051,  2053,
    2055,  2061,  2067,  2076,  2076,  2089,  2090,  2093,  2094,  2095,
    2100,  2100,  2110,  2110,  2120,  2121,  2122,  2127,  2128,  2129,
    2130,  2131,  2132,  2133,  2136,  2136,  2145,  2145,  2170,  2170,
    2200,  2200,  2211,  2212,  2215,  2216,  2217,  2222,  2222,  2231,
    2231,  2240,  2241,  2244,  2245,  2246,  2252,  2253,  2254,  2255,
    2256,  2257,  2258,  2259,  2260,  2261,  2262,  2263,  2264,  2265,
    2266,  2269,  2269,  2278,  2278,  2287,  2287,  2296,  2296,  2305,
    2305,  2316,  2316,  2325,  2325,  2334,  2334,  2343,  2343,  2352,
    2352,  2361,  2361,  2370,  2370,  2384,  2384,  2395,  2396,  2402,
    2402,  2413,  2414,  2415,  2420,  2420,  2430,  2431,  2434,  2435,
    2436,  2441,  2442,  2443,  2444,  2445,  2446,  2447,  2448,  2449,
    2450,  2451,  2452,  2453,  2454,  2455,  2456,  2459,  2461,  2461,
    2470,  2470,  2479,  2487,  2495,  2495,  2506,  2507,  2508,  2513,
    2514,  2515,  2516,  2517,  2520,  2520,  2529,  2529,  2541,  2541,
    2554,  2555,  2556,  2561,  2562,  2563,  2564,  2565,  2566,  2569,
    2575,  2575,  2584,  2590,  2590,  2600,  2600,  2613,  2613,  2623,
    2624,  2625,  2630,  2631,  2632,  2633,  2634,  2635,  2636,  2637,
    2638,  2639,  2640,  2641,  2642,  2643,  2644,  2645,  2646,  2647,
    2650,  2656,  2656,  2665,  2671,  2671,  2680,  2686,  2692,  2692,
    2701,  2702,  2705,  2705,  2715,  2715,  2725,  2732,  2739,  2739,
    2748,  2748,  2758,  2758,  2768,  2768,  2780,  2780,  2792,  2792,
    2802,  2803,  2804,  2810,  2811,  2814,  2814,  2825,  2833,  2833,
    2846,  2847,  2848,  2854,  2854,  2862,  2863,  2864,  2869,  2870,
    2871,  2872,  2873,  2874,  2875,  2878,  2884,  2884,  2893,  2893,
    2904,  2905,  2906,  2911,  2911,  2919,  2920,  2921,  2926,  2927,
    2928,  2929,  2930,  2933,  2933,  2942,  2948,  2954,  2960,  2960,
    2969,  2969,  2980,  2981,  2982,  2987,  2988,  2989,  2990,  2991,
    2994,  3000,  3006,  3012
  };

  void
  Dhcp4Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Dhcp4Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // PARSER4_DEBUG


#line 14 "dhcp4_parser.yy"
} } // isc::dhcp
#line 6464 "dhcp4_parser.cc"

#line 3018 "dhcp4_parser.yy"


void
isc::dhcp::Dhcp4Parser::error(const location_type& loc,
                              const std::string& what)
{
    ctx.error(loc, what);
}
