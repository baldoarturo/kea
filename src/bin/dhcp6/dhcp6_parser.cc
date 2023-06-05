// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

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
#define yylex   parser6_lex



#include "dhcp6_parser.h"


// Unqualified %code blocks.
#line 34 "dhcp6_parser.yy"

#include <dhcp6/parser_context.h>

// Avoid warnings with the error counter.
#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#line 57 "dhcp6_parser.cc"


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
#if PARSER6_DEBUG

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

#else // !PARSER6_DEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !PARSER6_DEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 14 "dhcp6_parser.yy"
namespace isc { namespace dhcp {
#line 150 "dhcp6_parser.cc"

  /// Build a parser object.
  Dhcp6Parser::Dhcp6Parser (isc::dhcp::Parser6Context& ctx_yyarg)
#if PARSER6_DEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      ctx (ctx_yyarg)
  {}

  Dhcp6Parser::~Dhcp6Parser ()
  {}

  Dhcp6Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  Dhcp6Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Dhcp6Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Dhcp6Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Dhcp6Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Dhcp6Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Dhcp6Parser::symbol_kind_type
  Dhcp6Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Dhcp6Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Dhcp6Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_value: // value
      case symbol_kind::S_map_value: // map_value
      case symbol_kind::S_ddns_replace_client_name_value: // ddns_replace_client_name_value
      case symbol_kind::S_ddns_conflict_resolution_mode_value: // ddns_conflict_resolution_mode_value
      case symbol_kind::S_db_type: // db_type
      case symbol_kind::S_on_fail_mode: // on_fail_mode
      case symbol_kind::S_hr_mode: // hr_mode
      case symbol_kind::S_duid_type: // duid_type
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

  Dhcp6Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_value: // value
      case symbol_kind::S_map_value: // map_value
      case symbol_kind::S_ddns_replace_client_name_value: // ddns_replace_client_name_value
      case symbol_kind::S_ddns_conflict_resolution_mode_value: // ddns_conflict_resolution_mode_value
      case symbol_kind::S_db_type: // db_type
      case symbol_kind::S_on_fail_mode: // on_fail_mode
      case symbol_kind::S_hr_mode: // hr_mode
      case symbol_kind::S_duid_type: // duid_type
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
  Dhcp6Parser::stack_symbol_type&
  Dhcp6Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_value: // value
      case symbol_kind::S_map_value: // map_value
      case symbol_kind::S_ddns_replace_client_name_value: // ddns_replace_client_name_value
      case symbol_kind::S_ddns_conflict_resolution_mode_value: // ddns_conflict_resolution_mode_value
      case symbol_kind::S_db_type: // db_type
      case symbol_kind::S_on_fail_mode: // on_fail_mode
      case symbol_kind::S_hr_mode: // hr_mode
      case symbol_kind::S_duid_type: // duid_type
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

  Dhcp6Parser::stack_symbol_type&
  Dhcp6Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_value: // value
      case symbol_kind::S_map_value: // map_value
      case symbol_kind::S_ddns_replace_client_name_value: // ddns_replace_client_name_value
      case symbol_kind::S_ddns_conflict_resolution_mode_value: // ddns_conflict_resolution_mode_value
      case symbol_kind::S_db_type: // db_type
      case symbol_kind::S_on_fail_mode: // on_fail_mode
      case symbol_kind::S_hr_mode: // hr_mode
      case symbol_kind::S_duid_type: // duid_type
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
  Dhcp6Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if PARSER6_DEBUG
  template <typename Base>
  void
  Dhcp6Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
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
#line 313 "dhcp6_parser.yy"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 413 "dhcp6_parser.cc"
        break;

      case symbol_kind::S_INTEGER: // "integer"
#line 313 "dhcp6_parser.yy"
                 { yyoutput << yysym.value.template as < int64_t > (); }
#line 419 "dhcp6_parser.cc"
        break;

      case symbol_kind::S_FLOAT: // "floating point"
#line 313 "dhcp6_parser.yy"
                 { yyoutput << yysym.value.template as < double > (); }
#line 425 "dhcp6_parser.cc"
        break;

      case symbol_kind::S_BOOLEAN: // "boolean"
#line 313 "dhcp6_parser.yy"
                 { yyoutput << yysym.value.template as < bool > (); }
#line 431 "dhcp6_parser.cc"
        break;

      case symbol_kind::S_value: // value
#line 313 "dhcp6_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 437 "dhcp6_parser.cc"
        break;

      case symbol_kind::S_map_value: // map_value
#line 313 "dhcp6_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 443 "dhcp6_parser.cc"
        break;

      case symbol_kind::S_ddns_replace_client_name_value: // ddns_replace_client_name_value
#line 313 "dhcp6_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 449 "dhcp6_parser.cc"
        break;

      case symbol_kind::S_ddns_conflict_resolution_mode_value: // ddns_conflict_resolution_mode_value
#line 313 "dhcp6_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 455 "dhcp6_parser.cc"
        break;

      case symbol_kind::S_db_type: // db_type
#line 313 "dhcp6_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 461 "dhcp6_parser.cc"
        break;

      case symbol_kind::S_on_fail_mode: // on_fail_mode
#line 313 "dhcp6_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 467 "dhcp6_parser.cc"
        break;

      case symbol_kind::S_hr_mode: // hr_mode
#line 313 "dhcp6_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 473 "dhcp6_parser.cc"
        break;

      case symbol_kind::S_duid_type: // duid_type
#line 313 "dhcp6_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 479 "dhcp6_parser.cc"
        break;

      case symbol_kind::S_ncr_protocol_value: // ncr_protocol_value
#line 313 "dhcp6_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 485 "dhcp6_parser.cc"
        break;

      default:
        break;
    }
        yyo << ')';
      }
  }
#endif

  void
  Dhcp6Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Dhcp6Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Dhcp6Parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if PARSER6_DEBUG
  std::ostream&
  Dhcp6Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Dhcp6Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Dhcp6Parser::debug_level_type
  Dhcp6Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Dhcp6Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // PARSER6_DEBUG

  Dhcp6Parser::state_type
  Dhcp6Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Dhcp6Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Dhcp6Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Dhcp6Parser::operator() ()
  {
    return parse ();
  }

  int
  Dhcp6Parser::parse ()
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
      case symbol_kind::S_db_type: // db_type
      case symbol_kind::S_on_fail_mode: // on_fail_mode
      case symbol_kind::S_hr_mode: // hr_mode
      case symbol_kind::S_duid_type: // duid_type
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
#line 322 "dhcp6_parser.yy"
                     { ctx.ctx_ = ctx.NO_KEYWORD; }
#line 766 "dhcp6_parser.cc"
    break;

  case 4: // $@2: %empty
#line 323 "dhcp6_parser.yy"
                      { ctx.ctx_ = ctx.CONFIG; }
#line 772 "dhcp6_parser.cc"
    break;

  case 6: // $@3: %empty
#line 324 "dhcp6_parser.yy"
                 { ctx.ctx_ = ctx.DHCP6; }
#line 778 "dhcp6_parser.cc"
    break;

  case 8: // $@4: %empty
#line 325 "dhcp6_parser.yy"
                       { ctx.ctx_ = ctx.INTERFACES_CONFIG; }
#line 784 "dhcp6_parser.cc"
    break;

  case 10: // $@5: %empty
#line 326 "dhcp6_parser.yy"
                   { ctx.ctx_ = ctx.SUBNET6; }
#line 790 "dhcp6_parser.cc"
    break;

  case 12: // $@6: %empty
#line 327 "dhcp6_parser.yy"
                 { ctx.ctx_ = ctx.POOLS; }
#line 796 "dhcp6_parser.cc"
    break;

  case 14: // $@7: %empty
#line 328 "dhcp6_parser.yy"
                   { ctx.ctx_ = ctx.PD_POOLS; }
#line 802 "dhcp6_parser.cc"
    break;

  case 16: // $@8: %empty
#line 329 "dhcp6_parser.yy"
                       { ctx.ctx_ = ctx.RESERVATIONS; }
#line 808 "dhcp6_parser.cc"
    break;

  case 18: // $@9: %empty
#line 330 "dhcp6_parser.yy"
                       { ctx.ctx_ = ctx.DHCP6; }
#line 814 "dhcp6_parser.cc"
    break;

  case 20: // $@10: %empty
#line 331 "dhcp6_parser.yy"
                      { ctx.ctx_ = ctx.OPTION_DEF; }
#line 820 "dhcp6_parser.cc"
    break;

  case 22: // $@11: %empty
#line 332 "dhcp6_parser.yy"
                       { ctx.ctx_ = ctx.OPTION_DATA; }
#line 826 "dhcp6_parser.cc"
    break;

  case 24: // $@12: %empty
#line 333 "dhcp6_parser.yy"
                         { ctx.ctx_ = ctx.HOOKS_LIBRARIES; }
#line 832 "dhcp6_parser.cc"
    break;

  case 26: // $@13: %empty
#line 334 "dhcp6_parser.yy"
                     { ctx.ctx_ = ctx.DHCP_DDNS; }
#line 838 "dhcp6_parser.cc"
    break;

  case 28: // $@14: %empty
#line 335 "dhcp6_parser.yy"
                          { ctx.ctx_ = ctx.CONFIG_CONTROL; }
#line 844 "dhcp6_parser.cc"
    break;

  case 30: // value: "integer"
#line 343 "dhcp6_parser.yy"
               { yylhs.value.as < ElementPtr > () = ElementPtr(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location))); }
#line 850 "dhcp6_parser.cc"
    break;

  case 31: // value: "floating point"
#line 344 "dhcp6_parser.yy"
             { yylhs.value.as < ElementPtr > () = ElementPtr(new DoubleElement(yystack_[0].value.as < double > (), ctx.loc2pos(yystack_[0].location))); }
#line 856 "dhcp6_parser.cc"
    break;

  case 32: // value: "boolean"
#line 345 "dhcp6_parser.yy"
               { yylhs.value.as < ElementPtr > () = ElementPtr(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location))); }
#line 862 "dhcp6_parser.cc"
    break;

  case 33: // value: "constant string"
#line 346 "dhcp6_parser.yy"
              { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location))); }
#line 868 "dhcp6_parser.cc"
    break;

  case 34: // value: "null"
#line 347 "dhcp6_parser.yy"
                 { yylhs.value.as < ElementPtr > () = ElementPtr(new NullElement(ctx.loc2pos(yystack_[0].location))); }
#line 874 "dhcp6_parser.cc"
    break;

  case 35: // value: map2
#line 348 "dhcp6_parser.yy"
            { yylhs.value.as < ElementPtr > () = ctx.stack_.back(); ctx.stack_.pop_back(); }
#line 880 "dhcp6_parser.cc"
    break;

  case 36: // value: list_generic
#line 349 "dhcp6_parser.yy"
                    { yylhs.value.as < ElementPtr > () = ctx.stack_.back(); ctx.stack_.pop_back(); }
#line 886 "dhcp6_parser.cc"
    break;

  case 37: // sub_json: value
#line 352 "dhcp6_parser.yy"
                {
    // Push back the JSON value on the stack
    ctx.stack_.push_back(yystack_[0].value.as < ElementPtr > ());
}
#line 895 "dhcp6_parser.cc"
    break;

  case 38: // $@15: %empty
#line 357 "dhcp6_parser.yy"
                     {
    // This code is executed when we're about to start parsing
    // the content of the map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 906 "dhcp6_parser.cc"
    break;

  case 39: // map2: "{" $@15 map_content "}"
#line 362 "dhcp6_parser.yy"
                             {
    // map parsing completed. If we ever want to do any wrap up
    // (maybe some sanity checking), this would be the best place
    // for it.
}
#line 916 "dhcp6_parser.cc"
    break;

  case 40: // map_value: map2
#line 368 "dhcp6_parser.yy"
                { yylhs.value.as < ElementPtr > () = ctx.stack_.back(); ctx.stack_.pop_back(); }
#line 922 "dhcp6_parser.cc"
    break;

  case 43: // not_empty_map: "constant string" ":" value
#line 375 "dhcp6_parser.yy"
                                  {
                  // map containing a single entry
                  ctx.unique(yystack_[2].value.as < std::string > (), ctx.loc2pos(yystack_[2].location));
                  ctx.stack_.back()->set(yystack_[2].value.as < std::string > (), yystack_[0].value.as < ElementPtr > ());
                  }
#line 932 "dhcp6_parser.cc"
    break;

  case 44: // not_empty_map: not_empty_map "," "constant string" ":" value
#line 380 "dhcp6_parser.yy"
                                                      {
                  // map consisting of a shorter map followed by
                  // comma and string:value
                  ctx.unique(yystack_[2].value.as < std::string > (), ctx.loc2pos(yystack_[2].location));
                  ctx.stack_.back()->set(yystack_[2].value.as < std::string > (), yystack_[0].value.as < ElementPtr > ());
                  }
#line 943 "dhcp6_parser.cc"
    break;

  case 45: // not_empty_map: not_empty_map ","
#line 386 "dhcp6_parser.yy"
                                   {
                 ctx.warnAboutExtraCommas(yystack_[0].location);
                 }
#line 951 "dhcp6_parser.cc"
    break;

  case 46: // $@16: %empty
#line 391 "dhcp6_parser.yy"
                              {
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(l);
}
#line 960 "dhcp6_parser.cc"
    break;

  case 47: // list_generic: "[" $@16 list_content "]"
#line 394 "dhcp6_parser.yy"
                               {
    // list parsing complete. Put any sanity checking here
}
#line 968 "dhcp6_parser.cc"
    break;

  case 50: // not_empty_list: value
#line 402 "dhcp6_parser.yy"
                      {
                  // List consisting of a single element.
                  ctx.stack_.back()->add(yystack_[0].value.as < ElementPtr > ());
                  }
#line 977 "dhcp6_parser.cc"
    break;

  case 51: // not_empty_list: not_empty_list "," value
#line 406 "dhcp6_parser.yy"
                                           {
                  // List ending with , and a value.
                  ctx.stack_.back()->add(yystack_[0].value.as < ElementPtr > ());
                  }
#line 986 "dhcp6_parser.cc"
    break;

  case 52: // not_empty_list: not_empty_list ","
#line 410 "dhcp6_parser.yy"
                                     {
                  ctx.warnAboutExtraCommas(yystack_[0].location);
                  }
#line 994 "dhcp6_parser.cc"
    break;

  case 53: // $@17: %empty
#line 416 "dhcp6_parser.yy"
                              {
    // List parsing about to start
}
#line 1002 "dhcp6_parser.cc"
    break;

  case 54: // list_strings: "[" $@17 list_strings_content "]"
#line 418 "dhcp6_parser.yy"
                                       {
    // list parsing complete. Put any sanity checking here
    //ctx.stack_.pop_back();
}
#line 1011 "dhcp6_parser.cc"
    break;

  case 57: // not_empty_list_strings: "constant string"
#line 427 "dhcp6_parser.yy"
                               {
                          ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
                          ctx.stack_.back()->add(s);
                          }
#line 1020 "dhcp6_parser.cc"
    break;

  case 58: // not_empty_list_strings: not_empty_list_strings "," "constant string"
#line 431 "dhcp6_parser.yy"
                                                            {
                          ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
                          ctx.stack_.back()->add(s);
                          }
#line 1029 "dhcp6_parser.cc"
    break;

  case 59: // not_empty_list_strings: not_empty_list_strings ","
#line 435 "dhcp6_parser.yy"
                                                     {
                          ctx.warnAboutExtraCommas(yystack_[0].location);
                          }
#line 1037 "dhcp6_parser.cc"
    break;

  case 60: // unknown_map_entry: "constant string" ":"
#line 445 "dhcp6_parser.yy"
                                {
    const std::string& where = ctx.contextName();
    const std::string& keyword = yystack_[1].value.as < std::string > ();
    error(yystack_[1].location,
          "got unexpected keyword \"" + keyword + "\" in " + where + " map.");
}
#line 1048 "dhcp6_parser.cc"
    break;

  case 61: // $@18: %empty
#line 454 "dhcp6_parser.yy"
                           {
    // This code is executed when we're about to start parsing
    // the content of the map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 1059 "dhcp6_parser.cc"
    break;

  case 62: // syntax_map: "{" $@18 global_object "}"
#line 459 "dhcp6_parser.yy"
                               {
    // map parsing completed. If we ever want to do any wrap up
    // (maybe some sanity checking), this would be the best place
    // for it.

    // Dhcp6 is required
    ctx.require("Dhcp6", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
}
#line 1072 "dhcp6_parser.cc"
    break;

  case 63: // $@19: %empty
#line 469 "dhcp6_parser.yy"
                     {
    // This code is executed when we're about to start parsing
    // the content of the map
    // Prevent against duplicate.
    ctx.unique("Dhcp6", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("Dhcp6", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.DHCP6);
}
#line 1087 "dhcp6_parser.cc"
    break;

  case 64: // global_object: "Dhcp6" $@19 ":" "{" global_params "}"
#line 478 "dhcp6_parser.yy"
                                                    {
    // No global parameter is required
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1097 "dhcp6_parser.cc"
    break;

  case 66: // global_object_comma: global_object ","
#line 486 "dhcp6_parser.yy"
                                         {
    ctx.warnAboutExtraCommas(yystack_[0].location);
}
#line 1105 "dhcp6_parser.cc"
    break;

  case 67: // $@20: %empty
#line 492 "dhcp6_parser.yy"
                          {
    // Parse the Dhcp6 map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 1115 "dhcp6_parser.cc"
    break;

  case 68: // sub_dhcp6: "{" $@20 global_params "}"
#line 496 "dhcp6_parser.yy"
                               {
    // No global parameter is required
    // parsing completed
}
#line 1124 "dhcp6_parser.cc"
    break;

  case 71: // global_params: global_params ","
#line 503 "dhcp6_parser.yy"
                                   {
                 ctx.warnAboutExtraCommas(yystack_[0].location);
                 }
#line 1132 "dhcp6_parser.cc"
    break;

  case 141: // $@21: %empty
#line 581 "dhcp6_parser.yy"
                               {
    ctx.unique("data-directory", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1141 "dhcp6_parser.cc"
    break;

  case 142: // data_directory: "data-directory" $@21 ":" "constant string"
#line 584 "dhcp6_parser.yy"
               {
    ElementPtr datadir(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("data-directory", datadir);
    ctx.leave();
}
#line 1151 "dhcp6_parser.cc"
    break;

  case 143: // preferred_lifetime: "preferred-lifetime" ":" "integer"
#line 590 "dhcp6_parser.yy"
                                                     {
    ctx.unique("preferred-lifetime", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("preferred-lifetime", prf);
}
#line 1161 "dhcp6_parser.cc"
    break;

  case 144: // min_preferred_lifetime: "min-preferred-lifetime" ":" "integer"
#line 596 "dhcp6_parser.yy"
                                                             {
    ctx.unique("min-preferred-lifetime", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("min-preferred-lifetime", prf);
}
#line 1171 "dhcp6_parser.cc"
    break;

  case 145: // max_preferred_lifetime: "max-preferred-lifetime" ":" "integer"
#line 602 "dhcp6_parser.yy"
                                                             {
    ctx.unique("max-preferred-lifetime", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-preferred-lifetime", prf);
}
#line 1181 "dhcp6_parser.cc"
    break;

  case 146: // valid_lifetime: "valid-lifetime" ":" "integer"
#line 608 "dhcp6_parser.yy"
                                             {
    ctx.unique("valid-lifetime", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("valid-lifetime", prf);
}
#line 1191 "dhcp6_parser.cc"
    break;

  case 147: // min_valid_lifetime: "min-valid-lifetime" ":" "integer"
#line 614 "dhcp6_parser.yy"
                                                     {
    ctx.unique("min-valid-lifetime", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("min-valid-lifetime", prf);
}
#line 1201 "dhcp6_parser.cc"
    break;

  case 148: // max_valid_lifetime: "max-valid-lifetime" ":" "integer"
#line 620 "dhcp6_parser.yy"
                                                     {
    ctx.unique("max-valid-lifetime", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-valid-lifetime", prf);
}
#line 1211 "dhcp6_parser.cc"
    break;

  case 149: // renew_timer: "renew-timer" ":" "integer"
#line 626 "dhcp6_parser.yy"
                                       {
    ctx.unique("renew-timer", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("renew-timer", prf);
}
#line 1221 "dhcp6_parser.cc"
    break;

  case 150: // rebind_timer: "rebind-timer" ":" "integer"
#line 632 "dhcp6_parser.yy"
                                         {
    ctx.unique("rebind-timer", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("rebind-timer", prf);
}
#line 1231 "dhcp6_parser.cc"
    break;

  case 151: // calculate_tee_times: "calculate-tee-times" ":" "boolean"
#line 638 "dhcp6_parser.yy"
                                                       {
    ctx.unique("calculate-tee-times", ctx.loc2pos(yystack_[2].location));
    ElementPtr ctt(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("calculate-tee-times", ctt);
}
#line 1241 "dhcp6_parser.cc"
    break;

  case 152: // t1_percent: "t1-percent" ":" "floating point"
#line 644 "dhcp6_parser.yy"
                                   {
    ctx.unique("t1-percent", ctx.loc2pos(yystack_[2].location));
    ElementPtr t1(new DoubleElement(yystack_[0].value.as < double > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("t1-percent", t1);
}
#line 1251 "dhcp6_parser.cc"
    break;

  case 153: // t2_percent: "t2-percent" ":" "floating point"
#line 650 "dhcp6_parser.yy"
                                   {
    ctx.unique("t2-percent", ctx.loc2pos(yystack_[2].location));
    ElementPtr t2(new DoubleElement(yystack_[0].value.as < double > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("t2-percent", t2);
}
#line 1261 "dhcp6_parser.cc"
    break;

  case 154: // cache_threshold: "cache-threshold" ":" "floating point"
#line 656 "dhcp6_parser.yy"
                                             {
    ctx.unique("cache-threshold", ctx.loc2pos(yystack_[2].location));
    ElementPtr ct(new DoubleElement(yystack_[0].value.as < double > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("cache-threshold", ct);
}
#line 1271 "dhcp6_parser.cc"
    break;

  case 155: // cache_max_age: "cache-max-age" ":" "integer"
#line 662 "dhcp6_parser.yy"
                                           {
    ctx.unique("cache-max-age", ctx.loc2pos(yystack_[2].location));
    ElementPtr cm(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("cache-max-age", cm);
}
#line 1281 "dhcp6_parser.cc"
    break;

  case 156: // decline_probation_period: "decline-probation-period" ":" "integer"
#line 668 "dhcp6_parser.yy"
                                                                 {
    ctx.unique("decline-probation-period", ctx.loc2pos(yystack_[2].location));
    ElementPtr dpp(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("decline-probation-period", dpp);
}
#line 1291 "dhcp6_parser.cc"
    break;

  case 157: // ddns_send_updates: "ddns-send-updates" ":" "boolean"
#line 674 "dhcp6_parser.yy"
                                                   {
    ctx.unique("ddns-send-updates", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-send-updates", b);
}
#line 1301 "dhcp6_parser.cc"
    break;

  case 158: // ddns_override_no_update: "ddns-override-no-update" ":" "boolean"
#line 680 "dhcp6_parser.yy"
                                                               {
    ctx.unique("ddns-override-no-update", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-override-no-update", b);
}
#line 1311 "dhcp6_parser.cc"
    break;

  case 159: // ddns_override_client_update: "ddns-override-client-update" ":" "boolean"
#line 686 "dhcp6_parser.yy"
                                                                       {
    ctx.unique("ddns-override-client-update", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-override-client-update", b);
}
#line 1321 "dhcp6_parser.cc"
    break;

  case 160: // $@22: %empty
#line 692 "dhcp6_parser.yy"
                                                   {
    ctx.unique("ddns-replace-client-name", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.REPLACE_CLIENT_NAME);
}
#line 1330 "dhcp6_parser.cc"
    break;

  case 161: // ddns_replace_client_name: "ddns-replace-client-name" $@22 ":" ddns_replace_client_name_value
#line 695 "dhcp6_parser.yy"
                                       {
    ctx.stack_.back()->set("ddns-replace-client-name", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 1339 "dhcp6_parser.cc"
    break;

  case 162: // ddns_replace_client_name_value: "when-present"
#line 701 "dhcp6_parser.yy"
                 {
      yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("when-present", ctx.loc2pos(yystack_[0].location)));
      }
#line 1347 "dhcp6_parser.cc"
    break;

  case 163: // ddns_replace_client_name_value: "never"
#line 704 "dhcp6_parser.yy"
          {
      yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("never", ctx.loc2pos(yystack_[0].location)));
      }
#line 1355 "dhcp6_parser.cc"
    break;

  case 164: // ddns_replace_client_name_value: "always"
#line 707 "dhcp6_parser.yy"
           {
      yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("always", ctx.loc2pos(yystack_[0].location)));
      }
#line 1363 "dhcp6_parser.cc"
    break;

  case 165: // ddns_replace_client_name_value: "when-not-present"
#line 710 "dhcp6_parser.yy"
                     {
      yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("when-not-present", ctx.loc2pos(yystack_[0].location)));
      }
#line 1371 "dhcp6_parser.cc"
    break;

  case 166: // ddns_replace_client_name_value: "boolean"
#line 713 "dhcp6_parser.yy"
            {
      error(yystack_[0].location, "boolean values for the replace-client-name are "
                "no longer supported");
      }
#line 1380 "dhcp6_parser.cc"
    break;

  case 167: // $@23: %empty
#line 719 "dhcp6_parser.yy"
                                             {
    ctx.unique("ddns-generated-prefix", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1389 "dhcp6_parser.cc"
    break;

  case 168: // ddns_generated_prefix: "ddns-generated-prefix" $@23 ":" "constant string"
#line 722 "dhcp6_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-generated-prefix", s);
    ctx.leave();
}
#line 1399 "dhcp6_parser.cc"
    break;

  case 169: // $@24: %empty
#line 728 "dhcp6_parser.yy"
                                               {
    ctx.unique("ddns-qualifying-suffix", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1408 "dhcp6_parser.cc"
    break;

  case 170: // ddns_qualifying_suffix: "ddns-qualifying-suffix" $@24 ":" "constant string"
#line 731 "dhcp6_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-qualifying-suffix", s);
    ctx.leave();
}
#line 1418 "dhcp6_parser.cc"
    break;

  case 171: // ddns_update_on_renew: "ddns-update-on-renew" ":" "boolean"
#line 737 "dhcp6_parser.yy"
                                                         {
    ctx.unique("ddns-update-on-renew", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-update-on-renew", b);
}
#line 1428 "dhcp6_parser.cc"
    break;

  case 172: // ddns_use_conflict_resolution: "ddns-use-conflict-resolution" ":" "boolean"
#line 746 "dhcp6_parser.yy"
                                                                         {
    ctx.unique("ddns-use-conflict-resolution", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.warning(yystack_[1].location, "ddns-use-conflict-resolution is deprecated. "
             "Substituting ddns-conflict-resolution-mode");
    ElementPtr mode(new StringElement(b->boolValue() ? "check-with-dhcid"
                                      : "no-check-with-dhcid"));
    ctx.stack_.back()->set("ddns-conflict-resolution-mode", mode);
}
#line 1442 "dhcp6_parser.cc"
    break;

  case 173: // $@25: %empty
#line 756 "dhcp6_parser.yy"
                                                             {
    ctx.unique("ddns-conflict-resolution-mode", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.DDNS_CONFLICT_RESOLUTION_MODE);
}
#line 1451 "dhcp6_parser.cc"
    break;

  case 174: // ddns_conflict_resolution_mode: "ddns-conflict-resolution-mode" $@25 ":" ddns_conflict_resolution_mode_value
#line 759 "dhcp6_parser.yy"
                                            {
    ctx.stack_.back()->set("ddns-conflict-resolution-mode", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 1460 "dhcp6_parser.cc"
    break;

  case 175: // ddns_conflict_resolution_mode_value: "check-with-dhcid"
#line 765 "dhcp6_parser.yy"
                     {
      yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("check-with-dhcid", ctx.loc2pos(yystack_[0].location)));
      }
#line 1468 "dhcp6_parser.cc"
    break;

  case 176: // ddns_conflict_resolution_mode_value: "no-check-with-dhcid"
#line 768 "dhcp6_parser.yy"
                        {
      yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("no-check-with-dhcid", ctx.loc2pos(yystack_[0].location)));
      }
#line 1476 "dhcp6_parser.cc"
    break;

  case 177: // ddns_conflict_resolution_mode_value: "check-exists-with-dhcid"
#line 771 "dhcp6_parser.yy"
                            {
      yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("check-exists-with-dhcid", ctx.loc2pos(yystack_[0].location)));
      }
#line 1484 "dhcp6_parser.cc"
    break;

  case 178: // ddns_conflict_resolution_mode_value: "no-check-without-dhcid"
#line 774 "dhcp6_parser.yy"
                           {
      yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("no-check-without-dhcid", ctx.loc2pos(yystack_[0].location)));
      }
#line 1492 "dhcp6_parser.cc"
    break;

  case 179: // ddns_ttl_percent: "ddns-ttl-percent" ":" "floating point"
#line 779 "dhcp6_parser.yy"
                                               {
    ctx.unique("ddns-ttl-percent", ctx.loc2pos(yystack_[2].location));
    ElementPtr ttl(new DoubleElement(yystack_[0].value.as < double > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-ttl-percent", ttl);
}
#line 1502 "dhcp6_parser.cc"
    break;

  case 180: // $@26: %empty
#line 785 "dhcp6_parser.yy"
                                     {
    ctx.unique("hostname-char-set", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1511 "dhcp6_parser.cc"
    break;

  case 181: // hostname_char_set: "hostname-char-set" $@26 ":" "constant string"
#line 788 "dhcp6_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hostname-char-set", s);
    ctx.leave();
}
#line 1521 "dhcp6_parser.cc"
    break;

  case 182: // $@27: %empty
#line 794 "dhcp6_parser.yy"
                                                     {
    ctx.unique("hostname-char-replacement", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1530 "dhcp6_parser.cc"
    break;

  case 183: // hostname_char_replacement: "hostname-char-replacement" $@27 ":" "constant string"
#line 797 "dhcp6_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hostname-char-replacement", s);
    ctx.leave();
}
#line 1540 "dhcp6_parser.cc"
    break;

  case 184: // store_extended_info: "store-extended-info" ":" "boolean"
#line 803 "dhcp6_parser.yy"
                                                       {
    ctx.unique("store-extended-info", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("store-extended-info", b);
}
#line 1550 "dhcp6_parser.cc"
    break;

  case 185: // statistic_default_sample_count: "statistic-default-sample-count" ":" "integer"
#line 809 "dhcp6_parser.yy"
                                                                             {
    ctx.unique("statistic-default-sample-count", ctx.loc2pos(yystack_[2].location));
    ElementPtr count(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("statistic-default-sample-count", count);
}
#line 1560 "dhcp6_parser.cc"
    break;

  case 186: // statistic_default_sample_age: "statistic-default-sample-age" ":" "integer"
#line 815 "dhcp6_parser.yy"
                                                                         {
    ctx.unique("statistic-default-sample-age", ctx.loc2pos(yystack_[2].location));
    ElementPtr age(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("statistic-default-sample-age", age);
}
#line 1570 "dhcp6_parser.cc"
    break;

  case 187: // $@28: %empty
#line 821 "dhcp6_parser.yy"
                       {
    ctx.unique("server-tag", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1579 "dhcp6_parser.cc"
    break;

  case 188: // server_tag: "server-tag" $@28 ":" "constant string"
#line 824 "dhcp6_parser.yy"
               {
    ElementPtr stag(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("server-tag", stag);
    ctx.leave();
}
#line 1589 "dhcp6_parser.cc"
    break;

  case 189: // parked_packet_limit: "parked-packet-limit" ":" "integer"
#line 830 "dhcp6_parser.yy"
                                                       {
    ctx.unique("parked-packet-limit", ctx.loc2pos(yystack_[2].location));
    ElementPtr ppl(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("parked-packet-limit", ppl);
}
#line 1599 "dhcp6_parser.cc"
    break;

  case 190: // $@29: %empty
#line 836 "dhcp6_parser.yy"
                     {
    ctx.unique("allocator", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1608 "dhcp6_parser.cc"
    break;

  case 191: // allocator: "allocator" $@29 ":" "constant string"
#line 839 "dhcp6_parser.yy"
               {
    ElementPtr al(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("allocator", al);
    ctx.leave();
}
#line 1618 "dhcp6_parser.cc"
    break;

  case 192: // $@30: %empty
#line 845 "dhcp6_parser.yy"
                           {
    ctx.unique("pd-allocator", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1627 "dhcp6_parser.cc"
    break;

  case 193: // pd_allocator: "pd-allocator" $@30 ":" "constant string"
#line 848 "dhcp6_parser.yy"
               {
    ElementPtr al(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("pd-allocator", al);
    ctx.leave();
}
#line 1637 "dhcp6_parser.cc"
    break;

  case 194: // early_global_reservations_lookup: "early-global-reservations-lookup" ":" "boolean"
#line 854 "dhcp6_parser.yy"
                                                                                 {
    ctx.unique("early-global-reservations-lookup", ctx.loc2pos(yystack_[2].location));
    ElementPtr early(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("early-global-reservations-lookup", early);
}
#line 1647 "dhcp6_parser.cc"
    break;

  case 195: // ip_reservations_unique: "ip-reservations-unique" ":" "boolean"
#line 860 "dhcp6_parser.yy"
                                                             {
    ctx.unique("ip-reservations-unique", ctx.loc2pos(yystack_[2].location));
    ElementPtr unique(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ip-reservations-unique", unique);
}
#line 1657 "dhcp6_parser.cc"
    break;

  case 196: // reservations_lookup_first: "reservations-lookup-first" ":" "boolean"
#line 866 "dhcp6_parser.yy"
                                                                   {
    ctx.unique("reservations-lookup-first", ctx.loc2pos(yystack_[2].location));
    ElementPtr first(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reservations-lookup-first", first);
}
#line 1667 "dhcp6_parser.cc"
    break;

  case 197: // $@31: %empty
#line 872 "dhcp6_parser.yy"
                                     {
    ctx.unique("interfaces-config", ctx.loc2pos(yystack_[0].location));
    ElementPtr i(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("interfaces-config", i);
    ctx.stack_.push_back(i);
    ctx.enter(ctx.INTERFACES_CONFIG);
}
#line 1679 "dhcp6_parser.cc"
    break;

  case 198: // interfaces_config: "interfaces-config" $@31 ":" "{" interfaces_config_params "}"
#line 878 "dhcp6_parser.yy"
                                                               {
    // No interfaces config param is required
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1689 "dhcp6_parser.cc"
    break;

  case 199: // $@32: %empty
#line 884 "dhcp6_parser.yy"
                                {
    // Parse the interfaces-config map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 1699 "dhcp6_parser.cc"
    break;

  case 200: // sub_interfaces6: "{" $@32 interfaces_config_params "}"
#line 888 "dhcp6_parser.yy"
                                          {
    // No interfaces config param is required
    // parsing completed
}
#line 1708 "dhcp6_parser.cc"
    break;

  case 203: // interfaces_config_params: interfaces_config_params ","
#line 895 "dhcp6_parser.yy"
                                                         {
                            ctx.warnAboutExtraCommas(yystack_[0].location);
                            }
#line 1716 "dhcp6_parser.cc"
    break;

  case 212: // $@33: %empty
#line 910 "dhcp6_parser.yy"
                            {
    ctx.unique("interfaces", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("interfaces", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1728 "dhcp6_parser.cc"
    break;

  case 213: // interfaces_list: "interfaces" $@33 ":" list_strings
#line 916 "dhcp6_parser.yy"
                     {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1737 "dhcp6_parser.cc"
    break;

  case 214: // re_detect: "re-detect" ":" "boolean"
#line 921 "dhcp6_parser.yy"
                                   {
    ctx.unique("re-detect", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("re-detect", b);
}
#line 1747 "dhcp6_parser.cc"
    break;

  case 215: // service_sockets_require_all: "service-sockets-require-all" ":" "boolean"
#line 927 "dhcp6_parser.yy"
                                                                       {
    ctx.unique("service-sockets-require-all", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("service-sockets-require-all", b);
}
#line 1757 "dhcp6_parser.cc"
    break;

  case 216: // service_sockets_retry_wait_time: "service-sockets-retry-wait-time" ":" "integer"
#line 933 "dhcp6_parser.yy"
                                                                               {
    ctx.unique("service-sockets-retry-wait-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("service-sockets-retry-wait-time", n);
}
#line 1767 "dhcp6_parser.cc"
    break;

  case 217: // service_sockets_max_retries: "service-sockets-max-retries" ":" "integer"
#line 939 "dhcp6_parser.yy"
                                                                       {
    ctx.unique("service-sockets-max-retries", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("service-sockets-max-retries", n);
}
#line 1777 "dhcp6_parser.cc"
    break;

  case 218: // $@34: %empty
#line 945 "dhcp6_parser.yy"
                               {
    ctx.unique("lease-database", ctx.loc2pos(yystack_[0].location));
    ElementPtr i(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("lease-database", i);
    ctx.stack_.push_back(i);
    ctx.enter(ctx.LEASE_DATABASE);
}
#line 1789 "dhcp6_parser.cc"
    break;

  case 219: // lease_database: "lease-database" $@34 ":" "{" database_map_params "}"
#line 951 "dhcp6_parser.yy"
                                                          {
    // The type parameter is required
    ctx.require("type", ctx.loc2pos(yystack_[2].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1800 "dhcp6_parser.cc"
    break;

  case 220: // $@35: %empty
#line 958 "dhcp6_parser.yy"
                               {
    ctx.unique("hosts-database", ctx.loc2pos(yystack_[0].location));
    ElementPtr i(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hosts-database", i);
    ctx.stack_.push_back(i);
    ctx.enter(ctx.HOSTS_DATABASE);
}
#line 1812 "dhcp6_parser.cc"
    break;

  case 221: // hosts_database: "hosts-database" $@35 ":" "{" database_map_params "}"
#line 964 "dhcp6_parser.yy"
                                                          {
    // The type parameter is required
    ctx.require("type", ctx.loc2pos(yystack_[2].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1823 "dhcp6_parser.cc"
    break;

  case 222: // $@36: %empty
#line 971 "dhcp6_parser.yy"
                                 {
    ctx.unique("hosts-databases", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hosts-databases", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.HOSTS_DATABASE);
}
#line 1835 "dhcp6_parser.cc"
    break;

  case 223: // hosts_databases: "hosts-databases" $@36 ":" "[" database_list "]"
#line 977 "dhcp6_parser.yy"
                                                      {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1844 "dhcp6_parser.cc"
    break;

  case 228: // not_empty_database_list: not_empty_database_list ","
#line 988 "dhcp6_parser.yy"
                                                       {
                           ctx.warnAboutExtraCommas(yystack_[0].location);
                           }
#line 1852 "dhcp6_parser.cc"
    break;

  case 229: // $@37: %empty
#line 993 "dhcp6_parser.yy"
                         {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 1862 "dhcp6_parser.cc"
    break;

  case 230: // database: "{" $@37 database_map_params "}"
#line 997 "dhcp6_parser.yy"
                                     {
    // The type parameter is required
    ctx.require("type", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 1872 "dhcp6_parser.cc"
    break;

  case 233: // database_map_params: database_map_params ","
#line 1005 "dhcp6_parser.yy"
                                               {
                       ctx.warnAboutExtraCommas(yystack_[0].location);
                       }
#line 1880 "dhcp6_parser.cc"
    break;

  case 256: // $@38: %empty
#line 1034 "dhcp6_parser.yy"
                    {
    ctx.unique("type", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.DATABASE_TYPE);
}
#line 1889 "dhcp6_parser.cc"
    break;

  case 257: // database_type: "type" $@38 ":" db_type
#line 1037 "dhcp6_parser.yy"
                {
    ctx.stack_.back()->set("type", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 1898 "dhcp6_parser.cc"
    break;

  case 258: // db_type: "memfile"
#line 1042 "dhcp6_parser.yy"
                 { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("memfile", ctx.loc2pos(yystack_[0].location))); }
#line 1904 "dhcp6_parser.cc"
    break;

  case 259: // db_type: "mysql"
#line 1043 "dhcp6_parser.yy"
               { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("mysql", ctx.loc2pos(yystack_[0].location))); }
#line 1910 "dhcp6_parser.cc"
    break;

  case 260: // db_type: "postgresql"
#line 1044 "dhcp6_parser.yy"
                    { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("postgresql", ctx.loc2pos(yystack_[0].location))); }
#line 1916 "dhcp6_parser.cc"
    break;

  case 261: // $@39: %empty
#line 1047 "dhcp6_parser.yy"
           {
    ctx.unique("user", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1925 "dhcp6_parser.cc"
    break;

  case 262: // user: "user" $@39 ":" "constant string"
#line 1050 "dhcp6_parser.yy"
               {
    ElementPtr user(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("user", user);
    ctx.leave();
}
#line 1935 "dhcp6_parser.cc"
    break;

  case 263: // $@40: %empty
#line 1056 "dhcp6_parser.yy"
                   {
    ctx.unique("password", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1944 "dhcp6_parser.cc"
    break;

  case 264: // password: "password" $@40 ":" "constant string"
#line 1059 "dhcp6_parser.yy"
               {
    ElementPtr pwd(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("password", pwd);
    ctx.leave();
}
#line 1954 "dhcp6_parser.cc"
    break;

  case 265: // $@41: %empty
#line 1065 "dhcp6_parser.yy"
           {
    ctx.unique("host", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1963 "dhcp6_parser.cc"
    break;

  case 266: // host: "host" $@41 ":" "constant string"
#line 1068 "dhcp6_parser.yy"
               {
    ElementPtr h(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("host", h);
    ctx.leave();
}
#line 1973 "dhcp6_parser.cc"
    break;

  case 267: // port: "port" ":" "integer"
#line 1074 "dhcp6_parser.yy"
                         {
    ctx.unique("port", ctx.loc2pos(yystack_[2].location));
    ElementPtr p(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("port", p);
}
#line 1983 "dhcp6_parser.cc"
    break;

  case 268: // $@42: %empty
#line 1080 "dhcp6_parser.yy"
           {
    ctx.unique("name", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1992 "dhcp6_parser.cc"
    break;

  case 269: // name: "name" $@42 ":" "constant string"
#line 1083 "dhcp6_parser.yy"
               {
    ElementPtr name(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("name", name);
    ctx.leave();
}
#line 2002 "dhcp6_parser.cc"
    break;

  case 270: // persist: "persist" ":" "boolean"
#line 1089 "dhcp6_parser.yy"
                               {
    ctx.unique("persist", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("persist", n);
}
#line 2012 "dhcp6_parser.cc"
    break;

  case 271: // lfc_interval: "lfc-interval" ":" "integer"
#line 1095 "dhcp6_parser.yy"
                                         {
    ctx.unique("lfc-interval", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("lfc-interval", n);
}
#line 2022 "dhcp6_parser.cc"
    break;

  case 272: // readonly: "readonly" ":" "boolean"
#line 1101 "dhcp6_parser.yy"
                                 {
    ctx.unique("readonly", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("readonly", n);
}
#line 2032 "dhcp6_parser.cc"
    break;

  case 273: // connect_timeout: "connect-timeout" ":" "integer"
#line 1107 "dhcp6_parser.yy"
                                               {
    ctx.unique("connect-timeout", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("connect-timeout", n);
}
#line 2042 "dhcp6_parser.cc"
    break;

  case 274: // read_timeout: "read-timeout" ":" "integer"
#line 1113 "dhcp6_parser.yy"
                                         {
    ctx.unique("read-timeout", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("read-timeout", n);
}
#line 2052 "dhcp6_parser.cc"
    break;

  case 275: // write_timeout: "write-timeout" ":" "integer"
#line 1119 "dhcp6_parser.yy"
                                           {
    ctx.unique("write-timeout", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("write-timeout", n);
}
#line 2062 "dhcp6_parser.cc"
    break;

  case 276: // tcp_user_timeout: "tcp-user-timeout" ":" "integer"
#line 1125 "dhcp6_parser.yy"
                                                 {
    ctx.unique("tcp-user-timeout", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("tcp-user-timeout", n);
}
#line 2072 "dhcp6_parser.cc"
    break;

  case 277: // reconnect_wait_time: "reconnect-wait-time" ":" "integer"
#line 1132 "dhcp6_parser.yy"
                                                       {
    ctx.unique("reconnect-wait-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reconnect-wait-time", n);
}
#line 2082 "dhcp6_parser.cc"
    break;

  case 278: // $@43: %empty
#line 1138 "dhcp6_parser.yy"
                 {
    ctx.unique("on-fail", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.DATABASE_ON_FAIL);
}
#line 2091 "dhcp6_parser.cc"
    break;

  case 279: // on_fail: "on-fail" $@43 ":" on_fail_mode
#line 1141 "dhcp6_parser.yy"
                     {
    ctx.stack_.back()->set("on-fail", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 2100 "dhcp6_parser.cc"
    break;

  case 280: // on_fail_mode: "stop-retry-exit"
#line 1146 "dhcp6_parser.yy"
                              { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("stop-retry-exit", ctx.loc2pos(yystack_[0].location))); }
#line 2106 "dhcp6_parser.cc"
    break;

  case 281: // on_fail_mode: "serve-retry-exit"
#line 1147 "dhcp6_parser.yy"
                               { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("serve-retry-exit", ctx.loc2pos(yystack_[0].location))); }
#line 2112 "dhcp6_parser.cc"
    break;

  case 282: // on_fail_mode: "serve-retry-continue"
#line 1148 "dhcp6_parser.yy"
                                   { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("serve-retry-continue", ctx.loc2pos(yystack_[0].location))); }
#line 2118 "dhcp6_parser.cc"
    break;

  case 283: // max_row_errors: "max-row-errors" ":" "integer"
#line 1151 "dhcp6_parser.yy"
                                             {
    ctx.unique("max-row-errors", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-row-errors", n);
}
#line 2128 "dhcp6_parser.cc"
    break;

  case 284: // max_reconnect_tries: "max-reconnect-tries" ":" "integer"
#line 1157 "dhcp6_parser.yy"
                                                       {
    ctx.unique("max-reconnect-tries", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-reconnect-tries", n);
}
#line 2138 "dhcp6_parser.cc"
    break;

  case 285: // $@44: %empty
#line 1163 "dhcp6_parser.yy"
                           {
    ctx.unique("trust-anchor", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2147 "dhcp6_parser.cc"
    break;

  case 286: // trust_anchor: "trust-anchor" $@44 ":" "constant string"
#line 1166 "dhcp6_parser.yy"
               {
    ElementPtr ca(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("trust-anchor", ca);
    ctx.leave();
}
#line 2157 "dhcp6_parser.cc"
    break;

  case 287: // $@45: %empty
#line 1172 "dhcp6_parser.yy"
                     {
    ctx.unique("cert-file", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2166 "dhcp6_parser.cc"
    break;

  case 288: // cert_file: "cert-file" $@45 ":" "constant string"
#line 1175 "dhcp6_parser.yy"
               {
    ElementPtr cert(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("cert-file", cert);
    ctx.leave();
}
#line 2176 "dhcp6_parser.cc"
    break;

  case 289: // $@46: %empty
#line 1181 "dhcp6_parser.yy"
                   {
    ctx.unique("key-file", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2185 "dhcp6_parser.cc"
    break;

  case 290: // key_file: "key-file" $@46 ":" "constant string"
#line 1184 "dhcp6_parser.yy"
               {
    ElementPtr key(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("key-file", key);
    ctx.leave();
}
#line 2195 "dhcp6_parser.cc"
    break;

  case 291: // $@47: %empty
#line 1190 "dhcp6_parser.yy"
                         {
    ctx.unique("cipher-list", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2204 "dhcp6_parser.cc"
    break;

  case 292: // cipher_list: "cipher-list" $@47 ":" "constant string"
#line 1193 "dhcp6_parser.yy"
               {
    ElementPtr cl(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("cipher-list", cl);
    ctx.leave();
}
#line 2214 "dhcp6_parser.cc"
    break;

  case 293: // $@48: %empty
#line 1199 "dhcp6_parser.yy"
                             {
    ctx.unique("sanity-checks", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("sanity-checks", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.SANITY_CHECKS);
}
#line 2226 "dhcp6_parser.cc"
    break;

  case 294: // sanity_checks: "sanity-checks" $@48 ":" "{" sanity_checks_params "}"
#line 1205 "dhcp6_parser.yy"
                                                           {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2235 "dhcp6_parser.cc"
    break;

  case 297: // sanity_checks_params: sanity_checks_params ","
#line 1212 "dhcp6_parser.yy"
                                                 {
                        ctx.warnAboutExtraCommas(yystack_[0].location);
                        }
#line 2243 "dhcp6_parser.cc"
    break;

  case 300: // $@49: %empty
#line 1221 "dhcp6_parser.yy"
                           {
    ctx.unique("lease-checks", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2252 "dhcp6_parser.cc"
    break;

  case 301: // lease_checks: "lease-checks" $@49 ":" "constant string"
#line 1224 "dhcp6_parser.yy"
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
#line 2272 "dhcp6_parser.cc"
    break;

  case 302: // $@50: %empty
#line 1240 "dhcp6_parser.yy"
                                           {
    ctx.unique("extended-info-checks", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2281 "dhcp6_parser.cc"
    break;

  case 303: // extended_info_checks: "extended-info-checks" $@50 ":" "constant string"
#line 1243 "dhcp6_parser.yy"
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
#line 2300 "dhcp6_parser.cc"
    break;

  case 304: // $@51: %empty
#line 1258 "dhcp6_parser.yy"
                         {
    ctx.unique("mac-sources", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("mac-sources", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.MAC_SOURCES);
}
#line 2312 "dhcp6_parser.cc"
    break;

  case 305: // mac_sources: "mac-sources" $@51 ":" "[" mac_sources_list "]"
#line 1264 "dhcp6_parser.yy"
                                                         {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2321 "dhcp6_parser.cc"
    break;

  case 308: // mac_sources_list: mac_sources_list ","
#line 1271 "dhcp6_parser.yy"
                                         {
                    ctx.warnAboutExtraCommas(yystack_[0].location);
                    }
#line 2329 "dhcp6_parser.cc"
    break;

  case 311: // duid_id: "duid"
#line 1280 "dhcp6_parser.yy"
              {
    ElementPtr duid(new StringElement("duid", ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(duid);
}
#line 2338 "dhcp6_parser.cc"
    break;

  case 312: // string_id: "constant string"
#line 1285 "dhcp6_parser.yy"
                  {
    ElementPtr duid(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(duid);
}
#line 2347 "dhcp6_parser.cc"
    break;

  case 313: // $@52: %empty
#line 1290 "dhcp6_parser.yy"
                                                           {
    ctx.unique("host-reservation-identifiers", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("host-reservation-identifiers", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.HOST_RESERVATION_IDENTIFIERS);
}
#line 2359 "dhcp6_parser.cc"
    break;

  case 314: // host_reservation_identifiers: "host-reservation-identifiers" $@52 ":" "[" host_reservation_identifiers_list "]"
#line 1296 "dhcp6_parser.yy"
                                                                          {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2368 "dhcp6_parser.cc"
    break;

  case 317: // host_reservation_identifiers_list: host_reservation_identifiers_list ","
#line 1303 "dhcp6_parser.yy"
                                              {
        ctx.warnAboutExtraCommas(yystack_[0].location);
        }
#line 2376 "dhcp6_parser.cc"
    break;

  case 321: // hw_address_id: "hw-address"
#line 1313 "dhcp6_parser.yy"
                          {
    ElementPtr hwaddr(new StringElement("hw-address", ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(hwaddr);
}
#line 2385 "dhcp6_parser.cc"
    break;

  case 322: // flex_id: "flex-id"
#line 1318 "dhcp6_parser.yy"
                 {
    ElementPtr flex_id(new StringElement("flex-id", ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(flex_id);
}
#line 2394 "dhcp6_parser.cc"
    break;

  case 323: // $@53: %empty
#line 1325 "dhcp6_parser.yy"
                                               {
    ctx.unique("relay-supplied-options", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("relay-supplied-options", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2406 "dhcp6_parser.cc"
    break;

  case 324: // relay_supplied_options: "relay-supplied-options" $@53 ":" "[" list_content "]"
#line 1331 "dhcp6_parser.yy"
                                                     {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2415 "dhcp6_parser.cc"
    break;

  case 325: // $@54: %empty
#line 1338 "dhcp6_parser.yy"
                                           {
    ctx.unique("multi-threading", ctx.loc2pos(yystack_[0].location));
    ElementPtr mt(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("multi-threading", mt);
    ctx.stack_.push_back(mt);
    ctx.enter(ctx.DHCP_MULTI_THREADING);
}
#line 2427 "dhcp6_parser.cc"
    break;

  case 326: // dhcp_multi_threading: "multi-threading" $@54 ":" "{" multi_threading_params "}"
#line 1344 "dhcp6_parser.yy"
                                                             {
    // The enable parameter is required.
    ctx.require("enable-multi-threading", ctx.loc2pos(yystack_[2].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2438 "dhcp6_parser.cc"
    break;

  case 329: // multi_threading_params: multi_threading_params ","
#line 1353 "dhcp6_parser.yy"
                                                     {
                          ctx.warnAboutExtraCommas(yystack_[0].location);
                          }
#line 2446 "dhcp6_parser.cc"
    break;

  case 336: // enable_multi_threading: "enable-multi-threading" ":" "boolean"
#line 1366 "dhcp6_parser.yy"
                                                             {
    ctx.unique("enable-multi-threading", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("enable-multi-threading", b);
}
#line 2456 "dhcp6_parser.cc"
    break;

  case 337: // thread_pool_size: "thread-pool-size" ":" "integer"
#line 1372 "dhcp6_parser.yy"
                                                 {
    ctx.unique("thread-pool-size", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("thread-pool-size", prf);
}
#line 2466 "dhcp6_parser.cc"
    break;

  case 338: // packet_queue_size: "packet-queue-size" ":" "integer"
#line 1378 "dhcp6_parser.yy"
                                                   {
    ctx.unique("packet-queue-size", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("packet-queue-size", prf);
}
#line 2476 "dhcp6_parser.cc"
    break;

  case 339: // $@55: %empty
#line 1384 "dhcp6_parser.yy"
                                 {
    ctx.unique("hooks-libraries", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hooks-libraries", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.HOOKS_LIBRARIES);
}
#line 2488 "dhcp6_parser.cc"
    break;

  case 340: // hooks_libraries: "hooks-libraries" $@55 ":" "[" hooks_libraries_list "]"
#line 1390 "dhcp6_parser.yy"
                                                             {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2497 "dhcp6_parser.cc"
    break;

  case 345: // not_empty_hooks_libraries_list: not_empty_hooks_libraries_list ","
#line 1401 "dhcp6_parser.yy"
                                           {
        ctx.warnAboutExtraCommas(yystack_[0].location);
        }
#line 2505 "dhcp6_parser.cc"
    break;

  case 346: // $@56: %empty
#line 1406 "dhcp6_parser.yy"
                              {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 2515 "dhcp6_parser.cc"
    break;

  case 347: // hooks_library: "{" $@56 hooks_params "}"
#line 1410 "dhcp6_parser.yy"
                              {
    // The library hooks parameter is required
    ctx.require("library", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 2525 "dhcp6_parser.cc"
    break;

  case 348: // $@57: %empty
#line 1416 "dhcp6_parser.yy"
                                  {
    // Parse the hooks-libraries list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 2535 "dhcp6_parser.cc"
    break;

  case 349: // sub_hooks_library: "{" $@57 hooks_params "}"
#line 1420 "dhcp6_parser.yy"
                              {
    // The library hooks parameter is required
    ctx.require("library", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    // parsing completed
}
#line 2545 "dhcp6_parser.cc"
    break;

  case 352: // hooks_params: hooks_params ","
#line 1428 "dhcp6_parser.yy"
                                 {
                ctx.warnAboutExtraCommas(yystack_[0].location);
                }
#line 2553 "dhcp6_parser.cc"
    break;

  case 356: // $@58: %empty
#line 1438 "dhcp6_parser.yy"
                 {
    ctx.unique("library", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2562 "dhcp6_parser.cc"
    break;

  case 357: // library: "library" $@58 ":" "constant string"
#line 1441 "dhcp6_parser.yy"
               {
    ElementPtr lib(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("library", lib);
    ctx.leave();
}
#line 2572 "dhcp6_parser.cc"
    break;

  case 358: // $@59: %empty
#line 1447 "dhcp6_parser.yy"
                       {
    ctx.unique("parameters", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2581 "dhcp6_parser.cc"
    break;

  case 359: // parameters: "parameters" $@59 ":" map_value
#line 1450 "dhcp6_parser.yy"
                  {
    ctx.stack_.back()->set("parameters", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 2590 "dhcp6_parser.cc"
    break;

  case 360: // $@60: %empty
#line 1456 "dhcp6_parser.yy"
                                                     {
    ctx.unique("expired-leases-processing", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("expired-leases-processing", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.EXPIRED_LEASES_PROCESSING);
}
#line 2602 "dhcp6_parser.cc"
    break;

  case 361: // expired_leases_processing: "expired-leases-processing" $@60 ":" "{" expired_leases_params "}"
#line 1462 "dhcp6_parser.yy"
                                                            {
    // No expired lease parameter is required
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2612 "dhcp6_parser.cc"
    break;

  case 364: // expired_leases_params: expired_leases_params ","
#line 1470 "dhcp6_parser.yy"
                                                   {
                         ctx.warnAboutExtraCommas(yystack_[0].location);
                         }
#line 2620 "dhcp6_parser.cc"
    break;

  case 371: // reclaim_timer_wait_time: "reclaim-timer-wait-time" ":" "integer"
#line 1483 "dhcp6_parser.yy"
                                                               {
    ctx.unique("reclaim-timer-wait-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reclaim-timer-wait-time", value);
}
#line 2630 "dhcp6_parser.cc"
    break;

  case 372: // flush_reclaimed_timer_wait_time: "flush-reclaimed-timer-wait-time" ":" "integer"
#line 1489 "dhcp6_parser.yy"
                                                                               {
    ctx.unique("flush-reclaimed-timer-wait-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("flush-reclaimed-timer-wait-time", value);
}
#line 2640 "dhcp6_parser.cc"
    break;

  case 373: // hold_reclaimed_time: "hold-reclaimed-time" ":" "integer"
#line 1495 "dhcp6_parser.yy"
                                                       {
    ctx.unique("hold-reclaimed-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hold-reclaimed-time", value);
}
#line 2650 "dhcp6_parser.cc"
    break;

  case 374: // max_reclaim_leases: "max-reclaim-leases" ":" "integer"
#line 1501 "dhcp6_parser.yy"
                                                     {
    ctx.unique("max-reclaim-leases", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-reclaim-leases", value);
}
#line 2660 "dhcp6_parser.cc"
    break;

  case 375: // max_reclaim_time: "max-reclaim-time" ":" "integer"
#line 1507 "dhcp6_parser.yy"
                                                 {
    ctx.unique("max-reclaim-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-reclaim-time", value);
}
#line 2670 "dhcp6_parser.cc"
    break;

  case 376: // unwarned_reclaim_cycles: "unwarned-reclaim-cycles" ":" "integer"
#line 1513 "dhcp6_parser.yy"
                                                               {
    ctx.unique("unwarned-reclaim-cycles", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("unwarned-reclaim-cycles", value);
}
#line 2680 "dhcp6_parser.cc"
    break;

  case 377: // $@61: %empty
#line 1522 "dhcp6_parser.yy"
                      {
    ctx.unique("subnet6", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("subnet6", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.SUBNET6);
}
#line 2692 "dhcp6_parser.cc"
    break;

  case 378: // subnet6_list: "subnet6" $@61 ":" "[" subnet6_list_content "]"
#line 1528 "dhcp6_parser.yy"
                                                             {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2701 "dhcp6_parser.cc"
    break;

  case 383: // not_empty_subnet6_list: not_empty_subnet6_list ","
#line 1542 "dhcp6_parser.yy"
                                                     {
                          ctx.warnAboutExtraCommas(yystack_[0].location);
                          }
#line 2709 "dhcp6_parser.cc"
    break;

  case 384: // $@62: %empty
#line 1551 "dhcp6_parser.yy"
                        {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 2719 "dhcp6_parser.cc"
    break;

  case 385: // subnet6: "{" $@62 subnet6_params "}"
#line 1555 "dhcp6_parser.yy"
                                {
    // Once we reached this place, the subnet parsing is now complete.
    // If we want to, we can implement default values here.
    // In particular we can do things like this:
    // if (!ctx.stack_.back()->get("interface")) {
    //     ctx.stack_.back()->set("interface", StringElement("loopback"));
    // }
    //
    // We can also stack up one level (Dhcp6) and copy over whatever
    // global parameters we want to:
    // if (!ctx.stack_.back()->get("renew-timer")) {
    //     ElementPtr renew = ctx_stack_[...].get("renew-timer");
    //     if (renew) {
    //         ctx.stack_.back()->set("renew-timer", renew);
    //     }
    // }

    // The subnet subnet6 parameter is required
    ctx.require("subnet", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 2745 "dhcp6_parser.cc"
    break;

  case 386: // $@63: %empty
#line 1577 "dhcp6_parser.yy"
                            {
    // Parse the subnet6 list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 2755 "dhcp6_parser.cc"
    break;

  case 387: // sub_subnet6: "{" $@63 subnet6_params "}"
#line 1581 "dhcp6_parser.yy"
                                {
    // The subnet subnet6 parameter is required
    ctx.require("subnet", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    // parsing completed
}
#line 2765 "dhcp6_parser.cc"
    break;

  case 390: // subnet6_params: subnet6_params ","
#line 1590 "dhcp6_parser.yy"
                                     {
                  ctx.warnAboutExtraCommas(yystack_[0].location);
                  }
#line 2773 "dhcp6_parser.cc"
    break;

  case 438: // $@64: %empty
#line 1645 "dhcp6_parser.yy"
               {
    ctx.unique("subnet", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2782 "dhcp6_parser.cc"
    break;

  case 439: // subnet: "subnet" $@64 ":" "constant string"
#line 1648 "dhcp6_parser.yy"
               {
    ElementPtr subnet(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("subnet", subnet);
    ctx.leave();
}
#line 2792 "dhcp6_parser.cc"
    break;

  case 440: // $@65: %empty
#line 1654 "dhcp6_parser.yy"
                     {
    ctx.unique("interface", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2801 "dhcp6_parser.cc"
    break;

  case 441: // interface: "interface" $@65 ":" "constant string"
#line 1657 "dhcp6_parser.yy"
               {
    ElementPtr iface(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("interface", iface);
    ctx.leave();
}
#line 2811 "dhcp6_parser.cc"
    break;

  case 442: // $@66: %empty
#line 1663 "dhcp6_parser.yy"
                           {
    ctx.unique("interface-id", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2820 "dhcp6_parser.cc"
    break;

  case 443: // interface_id: "interface-id" $@66 ":" "constant string"
#line 1666 "dhcp6_parser.yy"
               {
    ElementPtr iface(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("interface-id", iface);
    ctx.leave();
}
#line 2830 "dhcp6_parser.cc"
    break;

  case 444: // $@67: %empty
#line 1672 "dhcp6_parser.yy"
                           {
    ctx.unique("client-class", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2839 "dhcp6_parser.cc"
    break;

  case 445: // client_class: "client-class" $@67 ":" "constant string"
#line 1675 "dhcp6_parser.yy"
               {
    ElementPtr cls(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("client-class", cls);
    ctx.leave();
}
#line 2849 "dhcp6_parser.cc"
    break;

  case 446: // $@68: %empty
#line 1681 "dhcp6_parser.yy"
                                               {
    ctx.unique("require-client-classes", ctx.loc2pos(yystack_[0].location));
    ElementPtr c(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("require-client-classes", c);
    ctx.stack_.push_back(c);
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2861 "dhcp6_parser.cc"
    break;

  case 447: // require_client_classes: "require-client-classes" $@68 ":" list_strings
#line 1687 "dhcp6_parser.yy"
                     {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2870 "dhcp6_parser.cc"
    break;

  case 448: // reservations_global: "reservations-global" ":" "boolean"
#line 1692 "dhcp6_parser.yy"
                                                       {
    ctx.unique("reservations-global", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reservations-global", b);
}
#line 2880 "dhcp6_parser.cc"
    break;

  case 449: // reservations_in_subnet: "reservations-in-subnet" ":" "boolean"
#line 1698 "dhcp6_parser.yy"
                                                             {
    ctx.unique("reservations-in-subnet", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reservations-in-subnet", b);
}
#line 2890 "dhcp6_parser.cc"
    break;

  case 450: // reservations_out_of_pool: "reservations-out-of-pool" ":" "boolean"
#line 1704 "dhcp6_parser.yy"
                                                                 {
    ctx.unique("reservations-out-of-pool", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reservations-out-of-pool", b);
}
#line 2900 "dhcp6_parser.cc"
    break;

  case 451: // $@69: %empty
#line 1710 "dhcp6_parser.yy"
                                   {
    ctx.unique("reservation-mode", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.RESERVATION_MODE);
}
#line 2909 "dhcp6_parser.cc"
    break;

  case 452: // reservation_mode: "reservation-mode" $@69 ":" hr_mode
#line 1713 "dhcp6_parser.yy"
                {
    ctx.stack_.back()->set("reservation-mode", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 2918 "dhcp6_parser.cc"
    break;

  case 453: // hr_mode: "disabled"
#line 1718 "dhcp6_parser.yy"
                  { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("disabled", ctx.loc2pos(yystack_[0].location))); }
#line 2924 "dhcp6_parser.cc"
    break;

  case 454: // hr_mode: "out-of-pool"
#line 1719 "dhcp6_parser.yy"
                     { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("out-of-pool", ctx.loc2pos(yystack_[0].location))); }
#line 2930 "dhcp6_parser.cc"
    break;

  case 455: // hr_mode: "global"
#line 1720 "dhcp6_parser.yy"
                { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("global", ctx.loc2pos(yystack_[0].location))); }
#line 2936 "dhcp6_parser.cc"
    break;

  case 456: // hr_mode: "all"
#line 1721 "dhcp6_parser.yy"
             { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("all", ctx.loc2pos(yystack_[0].location))); }
#line 2942 "dhcp6_parser.cc"
    break;

  case 457: // id: "id" ":" "integer"
#line 1724 "dhcp6_parser.yy"
                     {
    ctx.unique("id", ctx.loc2pos(yystack_[2].location));
    ElementPtr id(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("id", id);
}
#line 2952 "dhcp6_parser.cc"
    break;

  case 458: // rapid_commit: "rapid-commit" ":" "boolean"
#line 1730 "dhcp6_parser.yy"
                                         {
    ctx.unique("rapid-commit", ctx.loc2pos(yystack_[2].location));
    ElementPtr rc(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("rapid-commit", rc);
}
#line 2962 "dhcp6_parser.cc"
    break;

  case 459: // $@70: %empty
#line 1738 "dhcp6_parser.yy"
                                 {
    ctx.unique("shared-networks", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("shared-networks", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.SHARED_NETWORK);
}
#line 2974 "dhcp6_parser.cc"
    break;

  case 460: // shared_networks: "shared-networks" $@70 ":" "[" shared_networks_content "]"
#line 1744 "dhcp6_parser.yy"
                                                                {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2983 "dhcp6_parser.cc"
    break;

  case 465: // shared_networks_list: shared_networks_list ","
#line 1757 "dhcp6_parser.yy"
                                                 {
                        ctx.warnAboutExtraCommas(yystack_[0].location);
                        }
#line 2991 "dhcp6_parser.cc"
    break;

  case 466: // $@71: %empty
#line 1762 "dhcp6_parser.yy"
                               {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 3001 "dhcp6_parser.cc"
    break;

  case 467: // shared_network: "{" $@71 shared_network_params "}"
#line 1766 "dhcp6_parser.yy"
                                       {
    ctx.stack_.pop_back();
}
#line 3009 "dhcp6_parser.cc"
    break;

  case 470: // shared_network_params: shared_network_params ","
#line 1772 "dhcp6_parser.yy"
                                                   {
                         ctx.warnAboutExtraCommas(yystack_[0].location);
                         }
#line 3017 "dhcp6_parser.cc"
    break;

  case 515: // $@72: %empty
#line 1827 "dhcp6_parser.yy"
                            {
    ctx.unique("option-def", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("option-def", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.OPTION_DEF);
}
#line 3029 "dhcp6_parser.cc"
    break;

  case 516: // option_def_list: "option-def" $@72 ":" "[" option_def_list_content "]"
#line 1833 "dhcp6_parser.yy"
                                                                {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3038 "dhcp6_parser.cc"
    break;

  case 517: // $@73: %empty
#line 1841 "dhcp6_parser.yy"
                                    {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 3047 "dhcp6_parser.cc"
    break;

  case 518: // sub_option_def_list: "{" $@73 option_def_list "}"
#line 1844 "dhcp6_parser.yy"
                                 {
    // parsing completed
}
#line 3055 "dhcp6_parser.cc"
    break;

  case 523: // not_empty_option_def_list: not_empty_option_def_list ","
#line 1856 "dhcp6_parser.yy"
                                                           {
                             ctx.warnAboutExtraCommas(yystack_[0].location);
                             }
#line 3063 "dhcp6_parser.cc"
    break;

  case 524: // $@74: %empty
#line 1863 "dhcp6_parser.yy"
                                 {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 3073 "dhcp6_parser.cc"
    break;

  case 525: // option_def_entry: "{" $@74 option_def_params "}"
#line 1867 "dhcp6_parser.yy"
                                   {
    // The name, code and type option def parameters are required.
    ctx.require("name", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.require("code", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.require("type", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 3085 "dhcp6_parser.cc"
    break;

  case 526: // $@75: %empty
#line 1878 "dhcp6_parser.yy"
                               {
    // Parse the option-def list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 3095 "dhcp6_parser.cc"
    break;

  case 527: // sub_option_def: "{" $@75 option_def_params "}"
#line 1882 "dhcp6_parser.yy"
                                   {
    // The name, code and type option def parameters are required.
    ctx.require("name", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.require("code", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.require("type", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    // parsing completed
}
#line 3107 "dhcp6_parser.cc"
    break;

  case 532: // not_empty_option_def_params: not_empty_option_def_params ","
#line 1898 "dhcp6_parser.yy"
                                                               {
                               ctx.warnAboutExtraCommas(yystack_[0].location);
                               }
#line 3115 "dhcp6_parser.cc"
    break;

  case 544: // code: "code" ":" "integer"
#line 1917 "dhcp6_parser.yy"
                         {
    ctx.unique("code", ctx.loc2pos(yystack_[2].location));
    ElementPtr code(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("code", code);
}
#line 3125 "dhcp6_parser.cc"
    break;

  case 546: // $@76: %empty
#line 1925 "dhcp6_parser.yy"
                      {
    ctx.unique("type", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3134 "dhcp6_parser.cc"
    break;

  case 547: // option_def_type: "type" $@76 ":" "constant string"
#line 1928 "dhcp6_parser.yy"
               {
    ElementPtr prf(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("type", prf);
    ctx.leave();
}
#line 3144 "dhcp6_parser.cc"
    break;

  case 548: // $@77: %empty
#line 1934 "dhcp6_parser.yy"
                                      {
    ctx.unique("record-types", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3153 "dhcp6_parser.cc"
    break;

  case 549: // option_def_record_types: "record-types" $@77 ":" "constant string"
#line 1937 "dhcp6_parser.yy"
               {
    ElementPtr rtypes(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("record-types", rtypes);
    ctx.leave();
}
#line 3163 "dhcp6_parser.cc"
    break;

  case 550: // $@78: %empty
#line 1943 "dhcp6_parser.yy"
             {
    ctx.unique("space", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3172 "dhcp6_parser.cc"
    break;

  case 551: // space: "space" $@78 ":" "constant string"
#line 1946 "dhcp6_parser.yy"
               {
    ElementPtr space(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("space", space);
    ctx.leave();
}
#line 3182 "dhcp6_parser.cc"
    break;

  case 553: // $@79: %empty
#line 1954 "dhcp6_parser.yy"
                                    {
    ctx.unique("encapsulate", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3191 "dhcp6_parser.cc"
    break;

  case 554: // option_def_encapsulate: "encapsulate" $@79 ":" "constant string"
#line 1957 "dhcp6_parser.yy"
               {
    ElementPtr encap(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("encapsulate", encap);
    ctx.leave();
}
#line 3201 "dhcp6_parser.cc"
    break;

  case 555: // option_def_array: "array" ":" "boolean"
#line 1963 "dhcp6_parser.yy"
                                      {
    ctx.unique("array", ctx.loc2pos(yystack_[2].location));
    ElementPtr array(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("array", array);
}
#line 3211 "dhcp6_parser.cc"
    break;

  case 556: // $@80: %empty
#line 1973 "dhcp6_parser.yy"
                              {
    ctx.unique("option-data", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("option-data", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.OPTION_DATA);
}
#line 3223 "dhcp6_parser.cc"
    break;

  case 557: // option_data_list: "option-data" $@80 ":" "[" option_data_list_content "]"
#line 1979 "dhcp6_parser.yy"
                                                                 {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3232 "dhcp6_parser.cc"
    break;

  case 562: // not_empty_option_data_list: not_empty_option_data_list ","
#line 1994 "dhcp6_parser.yy"
                                                             {
                              ctx.warnAboutExtraCommas(yystack_[0].location);
                              }
#line 3240 "dhcp6_parser.cc"
    break;

  case 563: // $@81: %empty
#line 2001 "dhcp6_parser.yy"
                                  {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 3250 "dhcp6_parser.cc"
    break;

  case 564: // option_data_entry: "{" $@81 option_data_params "}"
#line 2005 "dhcp6_parser.yy"
                                    {
    /// @todo: the code or name parameters are required.
    ctx.stack_.pop_back();
}
#line 3259 "dhcp6_parser.cc"
    break;

  case 565: // $@82: %empty
#line 2013 "dhcp6_parser.yy"
                                {
    // Parse the option-data list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 3269 "dhcp6_parser.cc"
    break;

  case 566: // sub_option_data: "{" $@82 option_data_params "}"
#line 2017 "dhcp6_parser.yy"
                                    {
    /// @todo: the code or name parameters are required.
    // parsing completed
}
#line 3278 "dhcp6_parser.cc"
    break;

  case 571: // not_empty_option_data_params: not_empty_option_data_params ","
#line 2033 "dhcp6_parser.yy"
                                         {
        ctx.warnAboutExtraCommas(yystack_[0].location);
        }
#line 3286 "dhcp6_parser.cc"
    break;

  case 583: // $@83: %empty
#line 2054 "dhcp6_parser.yy"
                       {
    ctx.unique("data", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3295 "dhcp6_parser.cc"
    break;

  case 584: // option_data_data: "data" $@83 ":" "constant string"
#line 2057 "dhcp6_parser.yy"
               {
    ElementPtr data(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("data", data);
    ctx.leave();
}
#line 3305 "dhcp6_parser.cc"
    break;

  case 587: // option_data_csv_format: "csv-format" ":" "boolean"
#line 2067 "dhcp6_parser.yy"
                                                 {
    ctx.unique("csv-format", ctx.loc2pos(yystack_[2].location));
    ElementPtr csv(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("csv-format", csv);
}
#line 3315 "dhcp6_parser.cc"
    break;

  case 588: // option_data_always_send: "always-send" ":" "boolean"
#line 2073 "dhcp6_parser.yy"
                                                   {
    ctx.unique("always-send", ctx.loc2pos(yystack_[2].location));
    ElementPtr persist(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("always-send", persist);
}
#line 3325 "dhcp6_parser.cc"
    break;

  case 589: // option_data_never_send: "never-send" ":" "boolean"
#line 2079 "dhcp6_parser.yy"
                                                 {
    ctx.unique("never-send", ctx.loc2pos(yystack_[2].location));
    ElementPtr cancel(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("never-send", cancel);
}
#line 3335 "dhcp6_parser.cc"
    break;

  case 590: // $@84: %empty
#line 2088 "dhcp6_parser.yy"
                  {
    ctx.unique("pools", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("pools", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.POOLS);
}
#line 3347 "dhcp6_parser.cc"
    break;

  case 591: // pools_list: "pools" $@84 ":" "[" pools_list_content "]"
#line 2094 "dhcp6_parser.yy"
                                                           {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3356 "dhcp6_parser.cc"
    break;

  case 596: // not_empty_pools_list: not_empty_pools_list ","
#line 2107 "dhcp6_parser.yy"
                                                 {
                        ctx.warnAboutExtraCommas(yystack_[0].location);
                        }
#line 3364 "dhcp6_parser.cc"
    break;

  case 597: // $@85: %empty
#line 2112 "dhcp6_parser.yy"
                                {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 3374 "dhcp6_parser.cc"
    break;

  case 598: // pool_list_entry: "{" $@85 pool_params "}"
#line 2116 "dhcp6_parser.yy"
                             {
    // The pool parameter is required.
    ctx.require("pool", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 3384 "dhcp6_parser.cc"
    break;

  case 599: // $@86: %empty
#line 2122 "dhcp6_parser.yy"
                          {
    // Parse the pool list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 3394 "dhcp6_parser.cc"
    break;

  case 600: // sub_pool6: "{" $@86 pool_params "}"
#line 2126 "dhcp6_parser.yy"
                             {
    // The pool parameter is required.
    ctx.require("pool", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    // parsing completed
}
#line 3404 "dhcp6_parser.cc"
    break;

  case 603: // pool_params: pool_params ","
#line 2134 "dhcp6_parser.yy"
                               {
               ctx.warnAboutExtraCommas(yystack_[0].location);
               }
#line 3412 "dhcp6_parser.cc"
    break;

  case 611: // $@87: %empty
#line 2148 "dhcp6_parser.yy"
                 {
    ctx.unique("pool", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3421 "dhcp6_parser.cc"
    break;

  case 612: // pool_entry: "pool" $@87 ":" "constant string"
#line 2151 "dhcp6_parser.yy"
               {
    ElementPtr pool(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("pool", pool);
    ctx.leave();
}
#line 3431 "dhcp6_parser.cc"
    break;

  case 613: // $@88: %empty
#line 2157 "dhcp6_parser.yy"
                           {
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3439 "dhcp6_parser.cc"
    break;

  case 614: // user_context: "user-context" $@88 ":" map_value
#line 2159 "dhcp6_parser.yy"
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
#line 3466 "dhcp6_parser.cc"
    break;

  case 615: // $@89: %empty
#line 2182 "dhcp6_parser.yy"
                 {
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3474 "dhcp6_parser.cc"
    break;

  case 616: // comment: "comment" $@89 ":" "constant string"
#line 2184 "dhcp6_parser.yy"
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
#line 3503 "dhcp6_parser.cc"
    break;

  case 617: // $@90: %empty
#line 2212 "dhcp6_parser.yy"
                        {
    ctx.unique("pd-pools", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("pd-pools", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.PD_POOLS);
}
#line 3515 "dhcp6_parser.cc"
    break;

  case 618: // pd_pools_list: "pd-pools" $@90 ":" "[" pd_pools_list_content "]"
#line 2218 "dhcp6_parser.yy"
                                                              {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3524 "dhcp6_parser.cc"
    break;

  case 623: // not_empty_pd_pools_list: not_empty_pd_pools_list ","
#line 2231 "dhcp6_parser.yy"
                                                       {
                           ctx.warnAboutExtraCommas(yystack_[0].location);
                           }
#line 3532 "dhcp6_parser.cc"
    break;

  case 624: // $@91: %empty
#line 2236 "dhcp6_parser.yy"
                              {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 3542 "dhcp6_parser.cc"
    break;

  case 625: // pd_pool_entry: "{" $@91 pd_pool_params "}"
#line 2240 "dhcp6_parser.yy"
                                {
    // The prefix, prefix len and delegated len parameters are required.
    ctx.require("prefix", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.require("prefix-len", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.require("delegated-len", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 3554 "dhcp6_parser.cc"
    break;

  case 626: // $@92: %empty
#line 2248 "dhcp6_parser.yy"
                            {
    // Parse the pd-pool list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 3564 "dhcp6_parser.cc"
    break;

  case 627: // sub_pd_pool: "{" $@92 pd_pool_params "}"
#line 2252 "dhcp6_parser.yy"
                                {
    // The prefix, prefix len and delegated len parameters are required.
    ctx.require("prefix", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.require("prefix-len", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.require("delegated-len", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    // parsing completed
}
#line 3576 "dhcp6_parser.cc"
    break;

  case 630: // pd_pool_params: pd_pool_params ","
#line 2262 "dhcp6_parser.yy"
                                     {
                  ctx.warnAboutExtraCommas(yystack_[0].location);
                  }
#line 3584 "dhcp6_parser.cc"
    break;

  case 642: // $@93: %empty
#line 2280 "dhcp6_parser.yy"
                  {
    ctx.unique("prefix", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3593 "dhcp6_parser.cc"
    break;

  case 643: // pd_prefix: "prefix" $@93 ":" "constant string"
#line 2283 "dhcp6_parser.yy"
               {
    ElementPtr prf(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("prefix", prf);
    ctx.leave();
}
#line 3603 "dhcp6_parser.cc"
    break;

  case 644: // pd_prefix_len: "prefix-len" ":" "integer"
#line 2289 "dhcp6_parser.yy"
                                        {
    ctx.unique("prefix-len", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("prefix-len", prf);
}
#line 3613 "dhcp6_parser.cc"
    break;

  case 645: // $@94: %empty
#line 2295 "dhcp6_parser.yy"
                                 {
    ctx.unique("excluded-prefix", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3622 "dhcp6_parser.cc"
    break;

  case 646: // excluded_prefix: "excluded-prefix" $@94 ":" "constant string"
#line 2298 "dhcp6_parser.yy"
               {
    ElementPtr prf(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("excluded-prefix", prf);
    ctx.leave();
}
#line 3632 "dhcp6_parser.cc"
    break;

  case 647: // excluded_prefix_len: "excluded-prefix-len" ":" "integer"
#line 2304 "dhcp6_parser.yy"
                                                       {
    ctx.unique("excluded-prefix-len", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("excluded-prefix-len", prf);
}
#line 3642 "dhcp6_parser.cc"
    break;

  case 648: // pd_delegated_len: "delegated-len" ":" "integer"
#line 2310 "dhcp6_parser.yy"
                                              {
    ctx.unique("delegated-len", ctx.loc2pos(yystack_[2].location));
    ElementPtr deleg(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("delegated-len", deleg);
}
#line 3652 "dhcp6_parser.cc"
    break;

  case 649: // $@95: %empty
#line 2319 "dhcp6_parser.yy"
                           {
    ctx.unique("reservations", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reservations", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.RESERVATIONS);
}
#line 3664 "dhcp6_parser.cc"
    break;

  case 650: // reservations: "reservations" $@95 ":" "[" reservations_list "]"
#line 2325 "dhcp6_parser.yy"
                                                          {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3673 "dhcp6_parser.cc"
    break;

  case 655: // not_empty_reservations_list: not_empty_reservations_list ","
#line 2336 "dhcp6_parser.yy"
                                                               {
                               ctx.warnAboutExtraCommas(yystack_[0].location);
                               }
#line 3681 "dhcp6_parser.cc"
    break;

  case 656: // $@96: %empty
#line 2341 "dhcp6_parser.yy"
                            {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 3691 "dhcp6_parser.cc"
    break;

  case 657: // reservation: "{" $@96 reservation_params "}"
#line 2345 "dhcp6_parser.yy"
                                    {
    /// @todo: an identifier parameter is required.
    ctx.stack_.pop_back();
}
#line 3700 "dhcp6_parser.cc"
    break;

  case 658: // $@97: %empty
#line 2350 "dhcp6_parser.yy"
                                {
    // Parse the reservations list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 3710 "dhcp6_parser.cc"
    break;

  case 659: // sub_reservation: "{" $@97 reservation_params "}"
#line 2354 "dhcp6_parser.yy"
                                    {
    /// @todo: an identifier parameter is required.
    // parsing completed
}
#line 3719 "dhcp6_parser.cc"
    break;

  case 664: // not_empty_reservation_params: not_empty_reservation_params ","
#line 2365 "dhcp6_parser.yy"
                                         {
        ctx.warnAboutExtraCommas(yystack_[0].location);
        }
#line 3727 "dhcp6_parser.cc"
    break;

  case 676: // $@98: %empty
#line 2384 "dhcp6_parser.yy"
                           {
    ctx.unique("ip-addresses", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ip-addresses", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3739 "dhcp6_parser.cc"
    break;

  case 677: // ip_addresses: "ip-addresses" $@98 ":" list_strings
#line 2390 "dhcp6_parser.yy"
                     {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3748 "dhcp6_parser.cc"
    break;

  case 678: // $@99: %empty
#line 2395 "dhcp6_parser.yy"
                   {
    ctx.unique("prefixes", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("prefixes", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3760 "dhcp6_parser.cc"
    break;

  case 679: // prefixes: "prefixes" $@99 ":" list_strings
#line 2401 "dhcp6_parser.yy"
                     {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3769 "dhcp6_parser.cc"
    break;

  case 680: // $@100: %empty
#line 2406 "dhcp6_parser.yy"
           {
    ctx.unique("duid", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3778 "dhcp6_parser.cc"
    break;

  case 681: // duid: "duid" $@100 ":" "constant string"
#line 2409 "dhcp6_parser.yy"
               {
    ElementPtr d(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("duid", d);
    ctx.leave();
}
#line 3788 "dhcp6_parser.cc"
    break;

  case 682: // $@101: %empty
#line 2415 "dhcp6_parser.yy"
                       {
    ctx.unique("hw-address", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3797 "dhcp6_parser.cc"
    break;

  case 683: // hw_address: "hw-address" $@101 ":" "constant string"
#line 2418 "dhcp6_parser.yy"
               {
    ElementPtr hw(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hw-address", hw);
    ctx.leave();
}
#line 3807 "dhcp6_parser.cc"
    break;

  case 684: // $@102: %empty
#line 2424 "dhcp6_parser.yy"
                   {
    ctx.unique("hostname", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3816 "dhcp6_parser.cc"
    break;

  case 685: // hostname: "hostname" $@102 ":" "constant string"
#line 2427 "dhcp6_parser.yy"
               {
    ElementPtr host(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hostname", host);
    ctx.leave();
}
#line 3826 "dhcp6_parser.cc"
    break;

  case 686: // $@103: %empty
#line 2433 "dhcp6_parser.yy"
                       {
    ctx.unique("flex-id", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3835 "dhcp6_parser.cc"
    break;

  case 687: // flex_id_value: "flex-id" $@103 ":" "constant string"
#line 2436 "dhcp6_parser.yy"
               {
    ElementPtr hw(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("flex-id", hw);
    ctx.leave();
}
#line 3845 "dhcp6_parser.cc"
    break;

  case 688: // $@104: %empty
#line 2442 "dhcp6_parser.yy"
                                           {
    ctx.unique("client-classes", ctx.loc2pos(yystack_[0].location));
    ElementPtr c(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("client-classes", c);
    ctx.stack_.push_back(c);
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3857 "dhcp6_parser.cc"
    break;

  case 689: // reservation_client_classes: "client-classes" $@104 ":" list_strings
#line 2448 "dhcp6_parser.yy"
                     {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3866 "dhcp6_parser.cc"
    break;

  case 690: // $@105: %empty
#line 2456 "dhcp6_parser.yy"
             {
    ctx.unique("relay", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("relay", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.RELAY);
}
#line 3878 "dhcp6_parser.cc"
    break;

  case 691: // relay: "relay" $@105 ":" "{" relay_map "}"
#line 2462 "dhcp6_parser.yy"
                                                {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3887 "dhcp6_parser.cc"
    break;

  case 694: // $@106: %empty
#line 2471 "dhcp6_parser.yy"
                       {
    ctx.unique("ip-address", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3896 "dhcp6_parser.cc"
    break;

  case 695: // ip_address: "ip-address" $@106 ":" "constant string"
#line 2474 "dhcp6_parser.yy"
               {
    ElementPtr addr(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ip-address", addr);
    ctx.leave();
}
#line 3906 "dhcp6_parser.cc"
    break;

  case 696: // $@107: %empty
#line 2483 "dhcp6_parser.yy"
                               {
    ctx.unique("client-classes", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("client-classes", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.CLIENT_CLASSES);
}
#line 3918 "dhcp6_parser.cc"
    break;

  case 697: // client_classes: "client-classes" $@107 ":" "[" client_classes_list "]"
#line 2489 "dhcp6_parser.yy"
                                                            {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3927 "dhcp6_parser.cc"
    break;

  case 700: // client_classes_list: client_classes_list ","
#line 2496 "dhcp6_parser.yy"
                                               {
                       ctx.warnAboutExtraCommas(yystack_[0].location);
                       }
#line 3935 "dhcp6_parser.cc"
    break;

  case 701: // $@108: %empty
#line 2501 "dhcp6_parser.yy"
                                   {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 3945 "dhcp6_parser.cc"
    break;

  case 702: // client_class_entry: "{" $@108 client_class_params "}"
#line 2505 "dhcp6_parser.yy"
                                     {
    // The name client class parameter is required.
    ctx.require("name", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 3955 "dhcp6_parser.cc"
    break;

  case 707: // not_empty_client_class_params: not_empty_client_class_params ","
#line 2517 "dhcp6_parser.yy"
                                          {
        ctx.warnAboutExtraCommas(yystack_[0].location);
        }
#line 3963 "dhcp6_parser.cc"
    break;

  case 723: // $@109: %empty
#line 2540 "dhcp6_parser.yy"
                        {
    ctx.unique("test", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3972 "dhcp6_parser.cc"
    break;

  case 724: // client_class_test: "test" $@109 ":" "constant string"
#line 2543 "dhcp6_parser.yy"
               {
    ElementPtr test(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("test", test);
    ctx.leave();
}
#line 3982 "dhcp6_parser.cc"
    break;

  case 725: // $@110: %empty
#line 2549 "dhcp6_parser.yy"
                                          {
    ctx.unique("template-test", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3991 "dhcp6_parser.cc"
    break;

  case 726: // client_class_template_test: "template-test" $@110 ":" "constant string"
#line 2552 "dhcp6_parser.yy"
               {
    ElementPtr template_test(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("template-test", template_test);
    ctx.leave();
}
#line 4001 "dhcp6_parser.cc"
    break;

  case 727: // only_if_required: "only-if-required" ":" "boolean"
#line 2558 "dhcp6_parser.yy"
                                                 {
    ctx.unique("only-if-required", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("only-if-required", b);
}
#line 4011 "dhcp6_parser.cc"
    break;

  case 728: // $@111: %empty
#line 2567 "dhcp6_parser.yy"
                     {
    ctx.unique("server-id", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("server-id", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.SERVER_ID);
}
#line 4023 "dhcp6_parser.cc"
    break;

  case 729: // server_id: "server-id" $@111 ":" "{" server_id_params "}"
#line 2573 "dhcp6_parser.yy"
                                                       {
    // The type parameter is required.
    ctx.require("type", ctx.loc2pos(yystack_[2].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4034 "dhcp6_parser.cc"
    break;

  case 732: // server_id_params: server_id_params ","
#line 2582 "dhcp6_parser.yy"
                                         {
                    ctx.warnAboutExtraCommas(yystack_[0].location);
                    }
#line 4042 "dhcp6_parser.cc"
    break;

  case 742: // $@112: %empty
#line 2598 "dhcp6_parser.yy"
                     {
    ctx.unique("type", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.DUID_TYPE);
}
#line 4051 "dhcp6_parser.cc"
    break;

  case 743: // server_id_type: "type" $@112 ":" duid_type
#line 2601 "dhcp6_parser.yy"
                  {
    ctx.stack_.back()->set("type", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 4060 "dhcp6_parser.cc"
    break;

  case 744: // duid_type: "LLT"
#line 2606 "dhcp6_parser.yy"
               { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("LLT", ctx.loc2pos(yystack_[0].location))); }
#line 4066 "dhcp6_parser.cc"
    break;

  case 745: // duid_type: "EN"
#line 2607 "dhcp6_parser.yy"
              { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("EN", ctx.loc2pos(yystack_[0].location))); }
#line 4072 "dhcp6_parser.cc"
    break;

  case 746: // duid_type: "LL"
#line 2608 "dhcp6_parser.yy"
              { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("LL", ctx.loc2pos(yystack_[0].location))); }
#line 4078 "dhcp6_parser.cc"
    break;

  case 747: // htype: "htype" ":" "integer"
#line 2611 "dhcp6_parser.yy"
                           {
    ctx.unique("htype", ctx.loc2pos(yystack_[2].location));
    ElementPtr htype(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("htype", htype);
}
#line 4088 "dhcp6_parser.cc"
    break;

  case 748: // $@113: %empty
#line 2617 "dhcp6_parser.yy"
                       {
    ctx.unique("identifier", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4097 "dhcp6_parser.cc"
    break;

  case 749: // identifier: "identifier" $@113 ":" "constant string"
#line 2620 "dhcp6_parser.yy"
               {
    ElementPtr id(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("identifier", id);
    ctx.leave();
}
#line 4107 "dhcp6_parser.cc"
    break;

  case 750: // time: "time" ":" "integer"
#line 2626 "dhcp6_parser.yy"
                         {
    ctx.unique("time", ctx.loc2pos(yystack_[2].location));
    ElementPtr time(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("time", time);
}
#line 4117 "dhcp6_parser.cc"
    break;

  case 751: // enterprise_id: "enterprise-id" ":" "integer"
#line 2632 "dhcp6_parser.yy"
                                           {
    ctx.unique("enterprise-id", ctx.loc2pos(yystack_[2].location));
    ElementPtr time(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("enterprise-id", time);
}
#line 4127 "dhcp6_parser.cc"
    break;

  case 752: // dhcp4o6_port: "dhcp4o6-port" ":" "integer"
#line 2640 "dhcp6_parser.yy"
                                         {
    ctx.unique("dhcp4o6-port", ctx.loc2pos(yystack_[2].location));
    ElementPtr time(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("dhcp4o6-port", time);
}
#line 4137 "dhcp6_parser.cc"
    break;

  case 753: // $@114: %empty
#line 2648 "dhcp6_parser.yy"
                               {
    ctx.unique("control-socket", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("control-socket", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.CONTROL_SOCKET);
}
#line 4149 "dhcp6_parser.cc"
    break;

  case 754: // control_socket: "control-socket" $@114 ":" "{" control_socket_params "}"
#line 2654 "dhcp6_parser.yy"
                                                            {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4158 "dhcp6_parser.cc"
    break;

  case 757: // control_socket_params: control_socket_params ","
#line 2661 "dhcp6_parser.yy"
                                                   {
                         ctx.warnAboutExtraCommas(yystack_[0].location);
                         }
#line 4166 "dhcp6_parser.cc"
    break;

  case 763: // $@115: %empty
#line 2673 "dhcp6_parser.yy"
                         {
    ctx.unique("socket-type", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4175 "dhcp6_parser.cc"
    break;

  case 764: // socket_type: "socket-type" $@115 ":" "constant string"
#line 2676 "dhcp6_parser.yy"
               {
    ElementPtr stype(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("socket-type", stype);
    ctx.leave();
}
#line 4185 "dhcp6_parser.cc"
    break;

  case 765: // $@116: %empty
#line 2682 "dhcp6_parser.yy"
                         {
    ctx.unique("socket-name", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4194 "dhcp6_parser.cc"
    break;

  case 766: // socket_name: "socket-name" $@116 ":" "constant string"
#line 2685 "dhcp6_parser.yy"
               {
    ElementPtr name(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("socket-name", name);
    ctx.leave();
}
#line 4204 "dhcp6_parser.cc"
    break;

  case 767: // $@117: %empty
#line 2694 "dhcp6_parser.yy"
                                       {
    ctx.unique("dhcp-queue-control", ctx.loc2pos(yystack_[0].location));
    ElementPtr qc(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("dhcp-queue-control", qc);
    ctx.stack_.push_back(qc);
    ctx.enter(ctx.DHCP_QUEUE_CONTROL);
}
#line 4216 "dhcp6_parser.cc"
    break;

  case 768: // dhcp_queue_control: "dhcp-queue-control" $@117 ":" "{" queue_control_params "}"
#line 2700 "dhcp6_parser.yy"
                                                           {
    // The enable queue parameter is required.
    ctx.require("enable-queue", ctx.loc2pos(yystack_[2].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4227 "dhcp6_parser.cc"
    break;

  case 771: // queue_control_params: queue_control_params ","
#line 2709 "dhcp6_parser.yy"
                                                 {
                        ctx.warnAboutExtraCommas(yystack_[0].location);
                        }
#line 4235 "dhcp6_parser.cc"
    break;

  case 778: // enable_queue: "enable-queue" ":" "boolean"
#line 2722 "dhcp6_parser.yy"
                                         {
    ctx.unique("enable-queue", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("enable-queue", b);
}
#line 4245 "dhcp6_parser.cc"
    break;

  case 779: // $@118: %empty
#line 2728 "dhcp6_parser.yy"
                       {
    ctx.unique("queue-type", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4254 "dhcp6_parser.cc"
    break;

  case 780: // queue_type: "queue-type" $@118 ":" "constant string"
#line 2731 "dhcp6_parser.yy"
               {
    ElementPtr qt(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("queue-type", qt);
    ctx.leave();
}
#line 4264 "dhcp6_parser.cc"
    break;

  case 781: // capacity: "capacity" ":" "integer"
#line 2737 "dhcp6_parser.yy"
                                 {
    ctx.unique("capacity", ctx.loc2pos(yystack_[2].location));
    ElementPtr c(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("capacity", c);
}
#line 4274 "dhcp6_parser.cc"
    break;

  case 782: // $@119: %empty
#line 2743 "dhcp6_parser.yy"
                            {
    ctx.unique(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4283 "dhcp6_parser.cc"
    break;

  case 783: // arbitrary_map_entry: "constant string" $@119 ":" value
#line 2746 "dhcp6_parser.yy"
              {
    ctx.stack_.back()->set(yystack_[3].value.as < std::string > (), yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 4292 "dhcp6_parser.cc"
    break;

  case 784: // $@120: %empty
#line 2753 "dhcp6_parser.yy"
                     {
    ctx.unique("dhcp-ddns", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("dhcp-ddns", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.DHCP_DDNS);
}
#line 4304 "dhcp6_parser.cc"
    break;

  case 785: // dhcp_ddns: "dhcp-ddns" $@120 ":" "{" dhcp_ddns_params "}"
#line 2759 "dhcp6_parser.yy"
                                                       {
    // The enable updates DHCP DDNS parameter is required.
    ctx.require("enable-updates", ctx.loc2pos(yystack_[2].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4315 "dhcp6_parser.cc"
    break;

  case 786: // $@121: %empty
#line 2766 "dhcp6_parser.yy"
                              {
    // Parse the dhcp-ddns map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 4325 "dhcp6_parser.cc"
    break;

  case 787: // sub_dhcp_ddns: "{" $@121 dhcp_ddns_params "}"
#line 2770 "dhcp6_parser.yy"
                                  {
    // The enable updates DHCP DDNS parameter is required.
    ctx.require("enable-updates", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    // parsing completed
}
#line 4335 "dhcp6_parser.cc"
    break;

  case 790: // dhcp_ddns_params: dhcp_ddns_params ","
#line 2778 "dhcp6_parser.yy"
                                         {
                    ctx.warnAboutExtraCommas(yystack_[0].location);
                    }
#line 4343 "dhcp6_parser.cc"
    break;

  case 809: // enable_updates: "enable-updates" ":" "boolean"
#line 2803 "dhcp6_parser.yy"
                                             {
    ctx.unique("enable-updates", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("enable-updates", b);
}
#line 4353 "dhcp6_parser.cc"
    break;

  case 810: // $@122: %empty
#line 2810 "dhcp6_parser.yy"
                                         {
    ctx.unique("qualifying-suffix", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4362 "dhcp6_parser.cc"
    break;

  case 811: // dep_qualifying_suffix: "qualifying-suffix" $@122 ":" "constant string"
#line 2813 "dhcp6_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("qualifying-suffix", s);
    ctx.leave();
}
#line 4372 "dhcp6_parser.cc"
    break;

  case 812: // $@123: %empty
#line 2819 "dhcp6_parser.yy"
                     {
    ctx.unique("server-ip", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4381 "dhcp6_parser.cc"
    break;

  case 813: // server_ip: "server-ip" $@123 ":" "constant string"
#line 2822 "dhcp6_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("server-ip", s);
    ctx.leave();
}
#line 4391 "dhcp6_parser.cc"
    break;

  case 814: // server_port: "server-port" ":" "integer"
#line 2828 "dhcp6_parser.yy"
                                       {
    ctx.unique("server-port", ctx.loc2pos(yystack_[2].location));
    ElementPtr i(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("server-port", i);
}
#line 4401 "dhcp6_parser.cc"
    break;

  case 815: // $@124: %empty
#line 2834 "dhcp6_parser.yy"
                     {
    ctx.unique("sender-ip", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4410 "dhcp6_parser.cc"
    break;

  case 816: // sender_ip: "sender-ip" $@124 ":" "constant string"
#line 2837 "dhcp6_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("sender-ip", s);
    ctx.leave();
}
#line 4420 "dhcp6_parser.cc"
    break;

  case 817: // sender_port: "sender-port" ":" "integer"
#line 2843 "dhcp6_parser.yy"
                                       {
    ctx.unique("sender-port", ctx.loc2pos(yystack_[2].location));
    ElementPtr i(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("sender-port", i);
}
#line 4430 "dhcp6_parser.cc"
    break;

  case 818: // max_queue_size: "max-queue-size" ":" "integer"
#line 2849 "dhcp6_parser.yy"
                                             {
    ctx.unique("max-queue-size", ctx.loc2pos(yystack_[2].location));
    ElementPtr i(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-queue-size", i);
}
#line 4440 "dhcp6_parser.cc"
    break;

  case 819: // $@125: %empty
#line 2855 "dhcp6_parser.yy"
                           {
    ctx.unique("ncr-protocol", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NCR_PROTOCOL);
}
#line 4449 "dhcp6_parser.cc"
    break;

  case 820: // ncr_protocol: "ncr-protocol" $@125 ":" ncr_protocol_value
#line 2858 "dhcp6_parser.yy"
                           {
    ctx.stack_.back()->set("ncr-protocol", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 4458 "dhcp6_parser.cc"
    break;

  case 821: // ncr_protocol_value: "UDP"
#line 2864 "dhcp6_parser.yy"
        { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("UDP", ctx.loc2pos(yystack_[0].location))); }
#line 4464 "dhcp6_parser.cc"
    break;

  case 822: // ncr_protocol_value: "TCP"
#line 2865 "dhcp6_parser.yy"
        { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("TCP", ctx.loc2pos(yystack_[0].location))); }
#line 4470 "dhcp6_parser.cc"
    break;

  case 823: // $@126: %empty
#line 2868 "dhcp6_parser.yy"
                       {
    ctx.unique("ncr-format", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NCR_FORMAT);
}
#line 4479 "dhcp6_parser.cc"
    break;

  case 824: // ncr_format: "ncr-format" $@126 ":" "JSON"
#line 2871 "dhcp6_parser.yy"
             {
    ElementPtr json(new StringElement("JSON", ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ncr-format", json);
    ctx.leave();
}
#line 4489 "dhcp6_parser.cc"
    break;

  case 825: // dep_override_no_update: "override-no-update" ":" "boolean"
#line 2878 "dhcp6_parser.yy"
                                                         {
    ctx.unique("override-no-update", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("override-no-update", b);
}
#line 4499 "dhcp6_parser.cc"
    break;

  case 826: // dep_override_client_update: "override-client-update" ":" "boolean"
#line 2885 "dhcp6_parser.yy"
                                                                 {
    ctx.unique("override-client-update", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("override-client-update", b);
}
#line 4509 "dhcp6_parser.cc"
    break;

  case 827: // $@127: %empty
#line 2892 "dhcp6_parser.yy"
                                             {
    ctx.unique("replace-client-name", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.REPLACE_CLIENT_NAME);
}
#line 4518 "dhcp6_parser.cc"
    break;

  case 828: // dep_replace_client_name: "replace-client-name" $@127 ":" ddns_replace_client_name_value
#line 2895 "dhcp6_parser.yy"
                                       {
    ctx.stack_.back()->set("replace-client-name", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 4527 "dhcp6_parser.cc"
    break;

  case 829: // $@128: %empty
#line 2901 "dhcp6_parser.yy"
                                       {
    ctx.unique("generated-prefix", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4536 "dhcp6_parser.cc"
    break;

  case 830: // dep_generated_prefix: "generated-prefix" $@128 ":" "constant string"
#line 2904 "dhcp6_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("generated-prefix", s);
    ctx.leave();
}
#line 4546 "dhcp6_parser.cc"
    break;

  case 831: // $@129: %empty
#line 2911 "dhcp6_parser.yy"
                                         {
    ctx.unique("hostname-char-set", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4555 "dhcp6_parser.cc"
    break;

  case 832: // dep_hostname_char_set: "hostname-char-set" $@129 ":" "constant string"
#line 2914 "dhcp6_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hostname-char-set", s);
    ctx.leave();
}
#line 4565 "dhcp6_parser.cc"
    break;

  case 833: // $@130: %empty
#line 2921 "dhcp6_parser.yy"
                                                         {
    ctx.unique("hostname-char-replacement", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4574 "dhcp6_parser.cc"
    break;

  case 834: // dep_hostname_char_replacement: "hostname-char-replacement" $@130 ":" "constant string"
#line 2924 "dhcp6_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hostname-char-replacement", s);
    ctx.leave();
}
#line 4584 "dhcp6_parser.cc"
    break;

  case 835: // $@131: %empty
#line 2933 "dhcp6_parser.yy"
                               {
    ctx.unique("config-control", ctx.loc2pos(yystack_[0].location));
    ElementPtr i(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("config-control", i);
    ctx.stack_.push_back(i);
    ctx.enter(ctx.CONFIG_CONTROL);
}
#line 4596 "dhcp6_parser.cc"
    break;

  case 836: // config_control: "config-control" $@131 ":" "{" config_control_params "}"
#line 2939 "dhcp6_parser.yy"
                                                            {
    // No config control params are required
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4606 "dhcp6_parser.cc"
    break;

  case 837: // $@132: %empty
#line 2945 "dhcp6_parser.yy"
                                   {
    // Parse the config-control map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 4616 "dhcp6_parser.cc"
    break;

  case 838: // sub_config_control: "{" $@132 config_control_params "}"
#line 2949 "dhcp6_parser.yy"
                                       {
    // No config_control params are required
    // parsing completed
}
#line 4625 "dhcp6_parser.cc"
    break;

  case 841: // config_control_params: config_control_params ","
#line 2957 "dhcp6_parser.yy"
                                                   {
                         ctx.warnAboutExtraCommas(yystack_[0].location);
                         }
#line 4633 "dhcp6_parser.cc"
    break;

  case 844: // $@133: %empty
#line 2967 "dhcp6_parser.yy"
                                   {
    ctx.unique("config-databases", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("config-databases", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.CONFIG_DATABASE);
}
#line 4645 "dhcp6_parser.cc"
    break;

  case 845: // config_databases: "config-databases" $@133 ":" "[" database_list "]"
#line 2973 "dhcp6_parser.yy"
                                                      {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4654 "dhcp6_parser.cc"
    break;

  case 846: // config_fetch_wait_time: "config-fetch-wait-time" ":" "integer"
#line 2978 "dhcp6_parser.yy"
                                                             {
    ctx.unique("config-fetch-wait-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("config-fetch-wait-time", value);
}
#line 4664 "dhcp6_parser.cc"
    break;

  case 847: // $@134: %empty
#line 2986 "dhcp6_parser.yy"
                 {
    ctx.unique("loggers", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("loggers", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.LOGGERS);
}
#line 4676 "dhcp6_parser.cc"
    break;

  case 848: // loggers: "loggers" $@134 ":" "[" loggers_entries "]"
#line 2992 "dhcp6_parser.yy"
                                                         {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4685 "dhcp6_parser.cc"
    break;

  case 851: // loggers_entries: loggers_entries ","
#line 3001 "dhcp6_parser.yy"
                                       {
                   ctx.warnAboutExtraCommas(yystack_[0].location);
                   }
#line 4693 "dhcp6_parser.cc"
    break;

  case 852: // $@135: %empty
#line 3007 "dhcp6_parser.yy"
                             {
    ElementPtr l(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(l);
    ctx.stack_.push_back(l);
}
#line 4703 "dhcp6_parser.cc"
    break;

  case 853: // logger_entry: "{" $@135 logger_params "}"
#line 3011 "dhcp6_parser.yy"
                               {
    ctx.stack_.pop_back();
}
#line 4711 "dhcp6_parser.cc"
    break;

  case 856: // logger_params: logger_params ","
#line 3017 "dhcp6_parser.yy"
                                   {
                 ctx.warnAboutExtraCommas(yystack_[0].location);
                 }
#line 4719 "dhcp6_parser.cc"
    break;

  case 864: // debuglevel: "debuglevel" ":" "integer"
#line 3031 "dhcp6_parser.yy"
                                     {
    ctx.unique("debuglevel", ctx.loc2pos(yystack_[2].location));
    ElementPtr dl(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("debuglevel", dl);
}
#line 4729 "dhcp6_parser.cc"
    break;

  case 865: // $@136: %empty
#line 3037 "dhcp6_parser.yy"
                   {
    ctx.unique("severity", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4738 "dhcp6_parser.cc"
    break;

  case 866: // severity: "severity" $@136 ":" "constant string"
#line 3040 "dhcp6_parser.yy"
               {
    ElementPtr sev(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("severity", sev);
    ctx.leave();
}
#line 4748 "dhcp6_parser.cc"
    break;

  case 867: // $@137: %empty
#line 3046 "dhcp6_parser.yy"
                                    {
    ctx.unique("output_options", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("output_options", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.OUTPUT_OPTIONS);
}
#line 4760 "dhcp6_parser.cc"
    break;

  case 868: // output_options_list: "output_options" $@137 ":" "[" output_options_list_content "]"
#line 3052 "dhcp6_parser.yy"
                                                                    {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4769 "dhcp6_parser.cc"
    break;

  case 871: // output_options_list_content: output_options_list_content ","
#line 3059 "dhcp6_parser.yy"
                                                               {
                               ctx.warnAboutExtraCommas(yystack_[0].location);
                               }
#line 4777 "dhcp6_parser.cc"
    break;

  case 872: // $@138: %empty
#line 3064 "dhcp6_parser.yy"
                             {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 4787 "dhcp6_parser.cc"
    break;

  case 873: // output_entry: "{" $@138 output_params_list "}"
#line 3068 "dhcp6_parser.yy"
                                    {
    ctx.stack_.pop_back();
}
#line 4795 "dhcp6_parser.cc"
    break;

  case 876: // output_params_list: output_params_list ","
#line 3074 "dhcp6_parser.yy"
                                             {
                      ctx.warnAboutExtraCommas(yystack_[0].location);
                      }
#line 4803 "dhcp6_parser.cc"
    break;

  case 882: // $@139: %empty
#line 3086 "dhcp6_parser.yy"
               {
    ctx.unique("output", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4812 "dhcp6_parser.cc"
    break;

  case 883: // output: "output" $@139 ":" "constant string"
#line 3089 "dhcp6_parser.yy"
               {
    ElementPtr sev(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("output", sev);
    ctx.leave();
}
#line 4822 "dhcp6_parser.cc"
    break;

  case 884: // flush: "flush" ":" "boolean"
#line 3095 "dhcp6_parser.yy"
                           {
    ctx.unique("flush", ctx.loc2pos(yystack_[2].location));
    ElementPtr flush(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("flush", flush);
}
#line 4832 "dhcp6_parser.cc"
    break;

  case 885: // maxsize: "maxsize" ":" "integer"
#line 3101 "dhcp6_parser.yy"
                               {
    ctx.unique("maxsize", ctx.loc2pos(yystack_[2].location));
    ElementPtr maxsize(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("maxsize", maxsize);
}
#line 4842 "dhcp6_parser.cc"
    break;

  case 886: // maxver: "maxver" ":" "integer"
#line 3107 "dhcp6_parser.yy"
                             {
    ctx.unique("maxver", ctx.loc2pos(yystack_[2].location));
    ElementPtr maxver(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("maxver", maxver);
}
#line 4852 "dhcp6_parser.cc"
    break;

  case 887: // $@140: %empty
#line 3113 "dhcp6_parser.yy"
                 {
    ctx.unique("pattern", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4861 "dhcp6_parser.cc"
    break;

  case 888: // pattern: "pattern" $@140 ":" "constant string"
#line 3116 "dhcp6_parser.yy"
               {
    ElementPtr sev(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("pattern", sev);
    ctx.leave();
}
#line 4871 "dhcp6_parser.cc"
    break;

  case 889: // $@141: %empty
#line 3122 "dhcp6_parser.yy"
                             {
    ctx.unique("compatibility", ctx.loc2pos(yystack_[0].location));
    ElementPtr i(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("compatibility", i);
    ctx.stack_.push_back(i);
    ctx.enter(ctx.COMPATIBILITY);
}
#line 4883 "dhcp6_parser.cc"
    break;

  case 890: // compatibility: "compatibility" $@141 ":" "{" compatibility_params "}"
#line 3128 "dhcp6_parser.yy"
                                                           {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4892 "dhcp6_parser.cc"
    break;

  case 893: // compatibility_params: compatibility_params ","
#line 3135 "dhcp6_parser.yy"
                                                 {
                        ctx.warnAboutExtraCommas(yystack_[0].location);
                        }
#line 4900 "dhcp6_parser.cc"
    break;

  case 896: // lenient_option_parsing: "lenient-option-parsing" ":" "boolean"
#line 3144 "dhcp6_parser.yy"
                                                             {
    ctx.unique("lenient-option-parsing", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("lenient-option-parsing", b);
}
#line 4910 "dhcp6_parser.cc"
    break;


#line 4914 "dhcp6_parser.cc"

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
  Dhcp6Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Dhcp6Parser::yytnamerr_ (const char *yystr)
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
  Dhcp6Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // Dhcp6Parser::context.
  Dhcp6Parser::context::context (const Dhcp6Parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  Dhcp6Parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
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
  Dhcp6Parser::yy_syntax_error_arguments_ (const context& yyctx,
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
  Dhcp6Parser::yysyntax_error_ (const context& yyctx) const
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


  const short Dhcp6Parser::yypact_ninf_ = -1038;

  const signed char Dhcp6Parser::yytable_ninf_ = -1;

  const short
  Dhcp6Parser::yypact_[] =
  {
     485, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038,    39,    29,    30,    34,    36,
      52,    73,    76,    78,    92,   124,   134,   144,   152,   154,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,    29,  -171,
      83,   168,    38,   704,    49,   240,   341,    65,    86,   -19,
     -97,   470,   157, -1038,   119,   181,   200,   208,   214, -1038,
      37, -1038, -1038, -1038, -1038, -1038, -1038, -1038,   261,   263,
     270,   279,   280,   301,   308,   312,   314,   318,   322,   328,
     366,   374, -1038,   382,   383,   407,   439,   442, -1038, -1038,
   -1038,   446,   447,   448,   454, -1038, -1038, -1038,   455, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038,   457,   458,   459, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,   461, -1038,
   -1038, -1038, -1038, -1038, -1038,   462,   463,   464, -1038, -1038,
     466, -1038,    94, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038,   469,   480,   481,   483, -1038,    95, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038,   484,   486, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038,   105, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038,   108, -1038, -1038, -1038, -1038, -1038,   487, -1038,   491,
     492, -1038, -1038, -1038, -1038, -1038, -1038,   118, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038,   433,   372, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038,   489, -1038, -1038,   494, -1038,
   -1038, -1038,   495, -1038, -1038,   496,   387, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
     501,   502,   503, -1038, -1038, -1038, -1038,   507,   471, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038,   126, -1038, -1038, -1038,   505, -1038, -1038,   506,
   -1038,   514,   517, -1038, -1038,   518,   519, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038,   129, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038,   520,   130, -1038, -1038, -1038, -1038,    29,    29,
   -1038,   265,   521, -1038, -1038,   525,   528,   530,   531,   532,
     533,   275,   286,   315,   317,   319,   320,   325,   326,   329,
     321,   323,   336,   327,   334,   551,   342,   343,   337,   345,
     348,   562,   565,   566,   353,   354,   356,   358,   579,   582,
     588,   368,   591,   592,   593,   594,   597,   598,   599,   377,
     380,   381,   605,   607,   609,   610,   611,   612,   615,   617,
     622,   402,   625,   627,   628,   629,   631,   633,   411,   412,
     413,   638,   653, -1038,   168, -1038,   654,   432,   435,   436,
     438,    38, -1038,   656,   662,   663,   664,   665,   445,   444,
     668,   669,   670,   704, -1038,   671,    49, -1038,   673,   453,
     676,   456,   460,   240, -1038,   678,   679,   680,   682,   683,
     684,   685, -1038,   341, -1038,   687,   688,   468,   705,   706,
     707,   488, -1038,    86,   708,   490,   497,   498, -1038,   -19,
     709,   710,    32, -1038,   499,   712,   714,   504,   718,   510,
     512,   724,   734,   513,   515,   735,   737,   739,   740,   470,
   -1038,   741,   522,   157, -1038, -1038, -1038,   742,   744,   524,
     745,   746,   760,   761,   764, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,   546,
   -1038, -1038, -1038, -1038, -1038,  -141,   557,   558, -1038, -1038,
   -1038, -1038,   779,   780,   781, -1038,   563,   564,   264,   784,
     791,   575,   339, -1038, -1038, -1038,   795,   796,   797,   799,
     802,   803,   804,   812,   814, -1038,   815,   819,   820,   821,
     580,   586, -1038, -1038, -1038,   824,   823, -1038,   826, -1038,
   -1038, -1038, -1038, -1038,   827,   829,   596,   616,   618, -1038,
   -1038,   826,   619,   828, -1038,   620, -1038,   623, -1038,   624,
   -1038, -1038, -1038,   826,   826,   826,   626,   630,   632,   634,
   -1038,   635,   636, -1038,   637,   652,   655, -1038, -1038,   667,
   -1038, -1038, -1038, -1038,   672,   791, -1038, -1038,   677,   686,
   -1038,   689, -1038, -1038,     8,   560, -1038, -1038,  -141,   690,
     691,   692, -1038,   831, -1038, -1038,    29,   168, -1038,   157,
      38,   367,   367,   832, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038,   834,   839,   842, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038,   844, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038,  -102,    29,    48,   171,   845,   846,   848,   274,
      91,   220,   156,   107,   470, -1038, -1038,   850,  -132, -1038,
   -1038,   855,   870, -1038, -1038, -1038, -1038, -1038,   -35, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,   832, -1038,
     136,   164,   184, -1038, -1038, -1038, -1038,   874,   890,   891,
     893,   896,   898,   899,   903,   904,   905, -1038,   907, -1038,
   -1038, -1038, -1038, -1038,   203, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038,   204, -1038,   906,
     914, -1038, -1038,   912,   916, -1038, -1038,   919,   926, -1038,
   -1038,   924,   928, -1038, -1038,   929,   933, -1038, -1038, -1038,
     106, -1038, -1038, -1038,   931, -1038, -1038, -1038,   207, -1038,
   -1038, -1038, -1038, -1038,   249, -1038, -1038, -1038, -1038,   303,
   -1038, -1038,   932,   936, -1038, -1038,   934,   938, -1038,   918,
     939,   940,   941,   943,   944,   277, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038,   945,   946,   947, -1038, -1038,
   -1038, -1038,   278, -1038, -1038, -1038, -1038, -1038, -1038,   948,
     949,   951, -1038,   291, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038,   292, -1038, -1038, -1038,   952,
   -1038,   953, -1038, -1038, -1038,   305, -1038, -1038, -1038, -1038,
   -1038,   330, -1038,   333, -1038,   954, -1038,   332, -1038, -1038,
     736, -1038,   955,   956, -1038, -1038,   957,   959, -1038, -1038,
   -1038,   958, -1038,   961, -1038, -1038, -1038,   960,   964,   965,
     966,   747,   738,   748,   749,   750,   752,   753,   754,   755,
     756,   967,   758,   970,   980,   982,   983,   367, -1038, -1038,
     367, -1038,   832,   704, -1038,   834,    86, -1038,   839,   -19,
   -1038,   842,   813, -1038,   844,  -102, -1038, -1038,    48, -1038,
     985,   986,   171, -1038,   302,   845, -1038,   341, -1038,   846,
     -97, -1038,   848,   767,   769,   770,   773,   776,   787,   274,
   -1038,  1001,  1011,   793,   794,   798,    91, -1038,   800,   817,
     825,   220, -1038,  1017,  1025,   156, -1038,   811,  1035,   833,
    1040,   107, -1038, -1038,   101,   850, -1038,   838,  -132, -1038,
   -1038,  1054,  1043,    49, -1038,   855,   240, -1038,   870,  1057,
   -1038, -1038,   324,   851,   854,   858, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038,   375, -1038,   859,   863,
     865,   888, -1038,   369, -1038,   371, -1038,  1109, -1038,  1137,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038,   385, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
     922,   927, -1038, -1038, -1038,  1144, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038,  1145,  1151, -1038,
   -1038, -1038, -1038, -1038, -1038,  1147, -1038,   386, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038,   273,   935, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038,   937,   942, -1038, -1038,
     950, -1038,    29, -1038, -1038,  1152, -1038, -1038, -1038, -1038,
   -1038,   427, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
     962,   428, -1038,   434, -1038,   963, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038,   813, -1038, -1038, -1038,  1153,
    1154,   968, -1038,   302, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038,  1156,   969,  1158,   101, -1038,
   -1038, -1038, -1038, -1038, -1038,   972,   973, -1038, -1038,  1159,
   -1038,   974, -1038, -1038, -1038,  1160, -1038, -1038,   365, -1038,
      -4,  1160, -1038, -1038,  1161,  1164,  1165, -1038,   437, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038,  1166,   975,   976,   978,
    1167,    -4, -1038,   981, -1038, -1038, -1038,   984, -1038, -1038,
   -1038
  };

  const short
  Dhcp6Parser::yydefact_[] =
  {
       0,     2,     4,     6,     8,    10,    12,    14,    16,    18,
      20,    22,    24,    26,    28,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,    46,    38,    34,    33,    30,    31,    32,    37,     3,
      35,    36,    61,     5,    67,     7,   199,     9,   386,    11,
     599,    13,   626,    15,   658,    17,   517,    19,   526,    21,
     565,    23,   348,    25,   786,    27,   837,    29,    48,    41,
       0,     0,     0,     0,     0,     0,   660,     0,   528,   567,
       0,     0,     0,    50,     0,    49,     0,     0,    42,    63,
       0,    65,   141,   835,   197,   218,   220,   222,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   187,     0,     0,     0,     0,     0,   160,   167,
     169,     0,     0,     0,     0,   377,   515,   556,     0,   190,
     192,   173,   459,   613,   615,   451,     0,     0,     0,   304,
     323,   313,   293,   696,   649,   339,   360,   728,     0,   325,
     753,   767,   784,   180,   182,     0,     0,     0,   847,   889,
       0,   140,     0,    69,    72,    73,    74,    75,    76,    77,
      78,    79,    80,   111,   112,   113,   114,   115,    81,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   117,
     118,   129,   130,   131,   106,   137,   138,   139,   133,   134,
     135,    84,    85,    86,    87,   103,    88,    90,    89,   132,
      94,    95,    82,   108,   109,   110,   107,    83,    92,    93,
     101,   102,   104,    91,    96,    97,    98,    99,   100,   105,
     116,   136,   212,     0,     0,     0,     0,   211,     0,   201,
     204,   205,   206,   207,   208,   209,   210,   590,   617,   438,
     440,   442,     0,     0,   446,   444,   690,   437,   391,   392,
     393,   394,   395,   396,   397,   398,   417,   418,   419,   420,
     421,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   422,   423,   434,   435,   436,     0,   388,   402,   403,
     404,   407,   408,   411,   412,   413,   410,   405,   406,   399,
     400,   415,   416,   401,   409,   414,   611,   610,   606,   607,
     605,     0,   601,   604,   608,   609,   642,     0,   645,     0,
       0,   641,   635,   636,   634,   639,   640,     0,   628,   631,
     632,   637,   638,   633,   688,   676,   678,   680,   682,   684,
     686,   675,   672,   673,   674,     0,   661,   662,   667,   668,
     665,   669,   670,   671,   666,     0,   546,   268,     0,   550,
     548,   553,     0,   542,   543,     0,   529,   530,   533,   545,
     534,   535,   536,   552,   537,   538,   539,   540,   541,   583,
       0,     0,     0,   581,   582,   585,   586,     0,   568,   569,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   356,
     358,   353,     0,   350,   354,   355,     0,   810,   812,     0,
     815,     0,     0,   819,   823,     0,     0,   827,   829,   831,
     833,   808,   806,   807,     0,   788,   791,   803,   792,   793,
     794,   795,   796,   797,   798,   799,   800,   801,   802,   804,
     805,   844,     0,     0,   839,   842,   843,    47,    52,     0,
      39,    45,     0,    66,    62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    60,    71,    68,     0,     0,     0,     0,
       0,   203,   200,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   390,   387,     0,   603,   600,     0,     0,
       0,     0,     0,   630,   627,     0,     0,     0,     0,     0,
       0,     0,   659,   664,   518,     0,     0,     0,     0,     0,
       0,     0,   527,   532,     0,     0,     0,     0,   566,   571,
       0,     0,   352,   349,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   790,
     787,     0,     0,   841,   838,    51,    43,     0,     0,     0,
       0,     0,     0,     0,     0,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,     0,
     185,   186,   157,   158,   159,     0,     0,     0,   171,   172,
     179,   184,     0,     0,     0,   189,     0,     0,     0,     0,
       0,     0,     0,   448,   449,   450,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   752,     0,     0,     0,     0,
       0,     0,   194,   195,   196,     0,     0,    70,     0,   214,
     215,   216,   217,   202,     0,     0,     0,     0,     0,   457,
     458,     0,     0,     0,   389,     0,   602,     0,   644,     0,
     647,   648,   629,     0,     0,     0,     0,     0,     0,     0,
     663,     0,     0,   544,     0,     0,     0,   555,   531,     0,
     587,   588,   589,   570,     0,     0,   351,   809,     0,     0,
     814,     0,   817,   818,     0,     0,   825,   826,     0,     0,
       0,     0,   789,     0,   846,   840,     0,     0,   142,     0,
       0,     0,     0,   224,   188,   162,   163,   164,   165,   166,
     161,   168,   170,   379,   519,   558,   191,   193,   175,   176,
     177,   178,   174,   461,    40,   614,   616,   453,   454,   455,
     456,   452,     0,    48,     0,     0,     0,   651,   341,     0,
       0,     0,     0,     0,     0,   181,   183,     0,     0,    53,
     213,   592,   619,   439,   441,   443,   447,   445,     0,   612,
     643,   646,   689,   677,   679,   681,   683,   685,   687,   547,
     269,   551,   549,   554,   584,   357,   359,   811,   813,   816,
     821,   822,   820,   824,   828,   830,   832,   834,   224,    44,
       0,     0,     0,   256,   261,   263,   265,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   278,     0,   285,
     287,   289,   291,   255,     0,   231,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   248,
     249,   250,   247,   251,   252,   253,   254,     0,   229,     0,
     225,   226,   384,     0,   380,   381,   524,     0,   520,   521,
     563,     0,   559,   560,   466,     0,   462,   463,   311,   312,
       0,   306,   309,   310,     0,   321,   322,   318,     0,   315,
     319,   320,   300,   302,     0,   295,   298,   299,   701,     0,
     698,   656,     0,   652,   653,   346,     0,   342,   343,     0,
       0,     0,     0,     0,     0,     0,   362,   365,   366,   367,
     368,   369,   370,   742,   748,     0,     0,     0,   741,   738,
     739,   740,     0,   730,   733,   736,   734,   735,   737,     0,
       0,     0,   335,     0,   327,   330,   331,   332,   333,   334,
     763,   765,   762,   760,   761,     0,   755,   758,   759,     0,
     779,     0,   782,   775,   776,     0,   769,   772,   773,   774,
     777,     0,   852,     0,   849,     0,   895,     0,   891,   894,
      55,   597,     0,   593,   594,   624,     0,   620,   621,   694,
     693,     0,   692,     0,    64,   836,   198,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   233,   219,   221,
       0,   223,   228,     0,   378,   383,   528,   516,   523,   567,
     557,   562,     0,   460,   465,   308,   305,   324,   317,   314,
       0,     0,   297,   294,   703,   700,   697,   660,   650,   655,
       0,   340,   345,     0,     0,     0,     0,     0,     0,   364,
     361,     0,     0,     0,     0,     0,   732,   729,     0,     0,
       0,   329,   326,     0,     0,   757,   754,     0,     0,     0,
       0,   771,   768,   785,     0,   851,   848,     0,   893,   890,
      57,     0,    56,     0,   591,   596,     0,   618,   623,     0,
     691,   845,     0,     0,     0,     0,   267,   270,   271,   272,
     273,   274,   275,   276,   284,   277,     0,   283,     0,     0,
       0,     0,   232,     0,   227,     0,   382,     0,   522,     0,
     561,   514,   485,   486,   487,   489,   490,   491,   475,   476,
     494,   495,   496,   497,   498,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   499,   500,   511,   512,   513,
     471,   472,   473,   474,   483,   484,   480,   481,   482,   479,
     488,     0,   468,   477,   492,   493,   478,   464,   307,   316,
       0,     0,   296,   723,   725,     0,   721,   715,   716,   717,
     718,   719,   720,   722,   712,   713,   714,     0,   704,   705,
     708,   709,   710,   711,   699,     0,   654,     0,   344,   371,
     372,   373,   374,   375,   376,   363,     0,     0,   747,   750,
     751,   731,   336,   337,   338,   328,     0,     0,   756,   778,
       0,   781,     0,   770,   867,     0,   865,   863,   857,   861,
     862,     0,   854,   859,   860,   858,   850,   896,   892,    54,
      59,     0,   595,     0,   622,     0,   258,   259,   260,   257,
     262,   264,   266,   280,   281,   282,   279,   286,   288,   290,
     292,   230,   385,   525,   564,   470,   467,   301,   303,     0,
       0,     0,   702,   707,   657,   347,   744,   745,   746,   743,
     749,   764,   766,   780,   783,     0,     0,     0,   856,   853,
      58,   598,   625,   695,   469,     0,     0,   727,   706,     0,
     864,     0,   855,   724,   726,     0,   866,   872,     0,   869,
       0,   871,   868,   882,     0,     0,     0,   887,     0,   874,
     877,   878,   879,   880,   881,   870,     0,     0,     0,     0,
       0,   876,   873,     0,   884,   885,   886,     0,   875,   883,
     888
  };

  const short
  Dhcp6Parser::yypgoto_[] =
  {
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038,   -10, -1038,  -620, -1038,
     450, -1038, -1038, -1038, -1038,   389, -1038,  -609, -1038, -1038,
   -1038,   -71, -1038, -1038, -1038, -1038, -1038, -1038, -1038,   416,
     649, -1038, -1038,   -42,    11,    14,    17,    18,    28,   -31,
     -29,   -27,   -13,    31,    33,    41, -1038,    44,    45,    46,
      47, -1038,   440,    51, -1038,    57, -1038,    62,    63,    67,
   -1038, -1038,    69,    74, -1038,    75, -1038,    77, -1038, -1038,
   -1038, -1038, -1038,    79, -1038,    80, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038,   426,   646, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,   344, -1038,
     127, -1038,  -730,   133, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038,   -46, -1038,  -779, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
     109, -1038, -1038, -1038, -1038, -1038, -1038, -1038,   120,  -761,
   -1038, -1038, -1038, -1038,   115, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038,    89, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
     102, -1038, -1038, -1038,   111,   606, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038,   100, -1038, -1038, -1038, -1038, -1038, -1038,
   -1037, -1038, -1038, -1038,   137, -1038, -1038, -1038,   140,   657,
   -1038, -1038, -1036, -1038, -1035, -1038,    88, -1038,    90, -1038,
      81,    82,    85,    87, -1038, -1038, -1038, -1034, -1038, -1038,
   -1038, -1038,   135, -1038, -1038,  -101,  1129, -1038, -1038, -1038,
   -1038, -1038,   149, -1038, -1038, -1038,   153, -1038,   639, -1038,
     -62, -1038, -1038, -1038, -1038, -1038,   -59, -1038, -1038, -1038,
   -1038, -1038,    -5, -1038, -1038, -1038,   158, -1038, -1038, -1038,
     151, -1038,   641, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038,    93, -1038, -1038, -1038,    98,
     681, -1038, -1038,   -60, -1038,     0, -1038, -1038, -1038, -1038,
   -1038,    96, -1038, -1038, -1038,    97,   675, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038,   -49, -1038, -1038, -1038,   138, -1038,
   -1038, -1038,   145, -1038,   666,   417, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1033,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038,   155, -1038, -1038,
   -1038,   -98, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038,   139, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038,   121, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038,   122, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038,   443,   640, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038,   482,   643, -1038, -1038, -1038, -1038,
   -1038, -1038,   117, -1038, -1038,   -92, -1038, -1038, -1038, -1038,
   -1038, -1038,  -113, -1038, -1038,  -131, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038,   123, -1038
  };

  const short
  Dhcp6Parser::yydefgoto_[] =
  {
       0,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    83,    39,    40,    69,
     775,    87,    88,    41,    68,    84,    85,   800,  1010,  1121,
    1122,   863,    43,    70,    90,   452,    91,    45,    71,   162,
     163,   164,   455,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   481,   760,   183,   482,   184,   483,   185,   186,   187,
     494,   772,   188,   189,   516,   190,   517,   191,   192,   193,
     194,   475,   195,   196,   492,   197,   493,   198,   199,   200,
     201,   457,    47,    72,   238,   239,   240,   526,   241,   242,
     243,   244,   202,   458,   203,   459,   204,   460,   889,   890,
     891,  1050,   864,   865,   866,  1027,  1289,   867,  1028,   868,
    1029,   869,  1030,   870,   871,   566,   872,   873,   874,   875,
     876,   877,   878,   879,   880,  1041,  1296,   881,   882,   883,
    1043,   884,  1044,   885,  1045,   886,  1046,   205,   505,   924,
     925,   926,  1070,   927,  1071,   206,   502,   910,   911,   912,
     913,   207,   504,   918,   919,   920,   921,   208,   503,   209,
     512,   973,   974,   975,   976,   977,   210,   508,   936,   937,
     938,  1080,    63,    80,   402,   403,   404,   580,   405,   581,
     211,   509,   945,   946,   947,   948,   949,   950,   951,   952,
     212,   488,   893,   894,   895,  1053,    49,    73,   286,   287,
     288,   535,   289,   536,   290,   537,   291,   541,   292,   540,
     213,   214,   215,   216,   498,   781,   297,   298,   217,   495,
     905,   906,   907,  1062,  1201,  1202,   218,   489,    57,    77,
     897,   898,   899,  1056,    59,    78,   365,   366,   367,   368,
     369,   370,   371,   565,   372,   569,   373,   568,   374,   375,
     570,   376,   219,   490,   901,   902,   903,  1059,    61,    79,
     387,   388,   389,   390,   391,   574,   392,   393,   394,   395,
     396,   300,   533,  1012,  1013,  1014,  1123,    51,    74,   311,
     312,   313,   545,   220,   496,   221,   497,   303,   534,  1016,
    1017,  1018,  1126,    53,    75,   327,   328,   329,   548,   330,
     331,   550,   332,   333,   222,   507,   932,   933,   934,  1077,
      55,    76,   345,   346,   347,   348,   556,   349,   557,   350,
     558,   351,   559,   352,   560,   353,   561,   354,   555,   305,
     542,  1021,  1022,  1129,   223,   506,   929,   930,  1074,  1227,
    1228,  1229,  1230,  1231,  1309,  1232,  1310,  1233,   224,   510,
     962,   963,   964,  1091,  1319,   965,   966,  1092,   967,   968,
     225,   226,   513,   985,   986,   987,  1103,   988,  1104,   227,
     514,   995,   996,   997,   998,  1108,   999,  1000,  1110,   228,
     515,    65,    81,   424,   425,   426,   427,   585,   428,   586,
     429,   430,   588,   431,   432,   433,   591,   832,   434,   592,
     435,   436,   437,   595,   438,   596,   439,   597,   440,   598,
     229,   456,    67,    82,   443,   444,   445,   601,   446,   230,
     521,  1003,  1004,  1114,  1271,  1272,  1273,  1274,  1327,  1275,
    1325,  1348,  1349,  1350,  1358,  1359,  1360,  1366,  1361,  1362,
    1363,  1364,  1370,   231,   522,  1007,  1008,  1009
  };

  const short
  Dhcp6Parser::yytable_[] =
  {
     161,   237,   257,   307,   321,   341,    38,   363,   383,   401,
     421,   959,   245,   301,   314,   325,   343,   385,   377,   397,
     386,   422,   887,   917,   304,  1191,  1192,  1193,  1200,  1206,
     774,   258,   364,   384,    31,   908,    32,    42,    33,    30,
     453,    44,   264,    46,   265,   454,   266,   399,   400,   755,
     756,   757,   758,    86,   232,   233,   234,   235,   236,    48,
     267,   357,   379,   358,   359,   380,   381,   382,   299,   310,
     324,   342,   246,   302,   315,   326,   344,  1005,   378,   398,
      50,   423,   806,    52,   259,    54,   759,   260,   133,   134,
     261,   262,   160,    89,   812,   813,   814,   524,   531,    56,
     335,   263,   525,   532,   268,   774,   269,  1019,   543,  1065,
     356,   546,  1066,   544,   270,   953,   547,   271,   272,   273,
     274,   553,   909,   848,   275,   447,   554,   160,   127,   582,
     276,    58,   599,   603,   583,   277,   278,   600,   604,   524,
     279,    60,   280,   126,  1024,   133,   134,   281,   282,   306,
     283,    62,   284,   285,   293,   294,   133,   134,   295,    64,
     296,    66,   308,   322,   309,   323,   357,   603,   358,   359,
     441,   442,  1025,   360,   361,   362,   399,   400,   254,    92,
      93,   357,   255,    94,   448,   908,   915,   531,   916,    95,
      96,    97,  1026,   133,   134,   830,   831,  1353,   133,   134,
    1354,  1355,  1356,  1357,   449,   160,  1047,  1047,   133,   134,
    1068,  1048,  1049,  1069,   133,   134,   450,   451,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   954,   955,
     956,   957,  1072,    34,    35,    36,    37,  1073,   128,   129,
     130,   131,   160,   133,   134,   461,   132,   462,  1191,  1192,
    1193,  1200,  1206,   160,   463,   133,   134,   989,   990,   991,
    1089,  1096,   135,   464,   465,  1090,  1097,   136,   137,   138,
     139,   140,   141,   142,  1101,  1105,   143,   922,   923,  1102,
    1106,  1264,   144,  1265,  1266,   466,  1075,   917,  1111,  1076,
     160,   145,   467,  1112,   146,   160,   468,   959,   469,   127,
    1153,   147,   470,   980,   981,   160,   471,   133,   134,   148,
     149,   992,   472,   599,   150,  1118,  1115,   151,  1113,  1116,
    1119,   152,   316,   317,   318,   319,   320,   133,   134,  1286,
    1287,  1288,    98,    99,   100,   101,   102,   103,   768,   769,
     770,   771,   153,   154,   155,   156,   157,   158,  1351,   254,
     473,  1352,  1047,   255,   543,   563,   159,  1301,   474,  1302,
     160,   127,   357,   969,   970,   971,   476,   477,  1305,   582,
     573,   843,   160,  1306,  1315,   844,   845,   846,   847,   848,
     849,   850,   851,   852,   853,   854,   855,   856,   857,   133,
     134,   478,   858,   859,   860,   861,   862,  1293,  1294,  1295,
     127,   939,   940,   941,   942,   943,   944,  1316,  1317,  1318,
    1328,   546,  1213,  1214,  1215,  1329,  1331,   553,   605,   606,
    1371,   562,  1332,   479,   160,  1372,   480,   357,   133,   134,
     484,   485,   486,   161,   777,   778,   779,   780,   487,   491,
     237,   499,   500,   501,   160,   511,   518,   519,   520,   334,
     523,   245,   257,   527,   579,   307,   335,   336,   337,   338,
     339,   340,   321,   301,   528,   529,   314,   530,   538,   607,
     539,   549,   341,   325,   304,   551,   552,   564,   567,   571,
     615,   258,   363,   343,   572,   575,   576,   577,   383,   584,
     587,   616,   264,   377,   265,   578,   266,   385,   589,   397,
     386,   590,   593,   594,   602,   608,   160,   364,   421,   609,
     267,   246,   610,   384,   611,   612,   613,   614,   299,   422,
     617,   310,   618,   302,   619,   620,   315,   624,   324,   625,
     621,   622,   627,   326,   259,   629,   623,   260,   342,   628,
     261,   262,   626,   344,   632,   160,   635,   630,   631,   636,
     637,   263,   633,   378,   268,   634,   269,   133,   134,   398,
     638,   639,   640,   642,   270,   641,   643,   271,   272,   273,
     274,   160,   644,   645,   275,   646,   647,   648,   649,   423,
     276,   650,   651,   652,   653,   277,   278,   654,   655,   656,
     279,   657,   280,   658,   659,   660,   661,   281,   282,   662,
     283,   663,   284,   285,   293,   294,   664,   665,   295,   666,
     296,   667,   668,   669,   308,   670,   309,   671,   672,   673,
     674,   322,   675,   323,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   676,   678,   679,
     684,   681,   680,   682,   419,   420,   685,   686,   687,   688,
     689,   690,   691,   692,   693,   695,   161,   697,   698,   237,
     699,   700,   703,   704,   705,   701,   706,   707,   708,   709,
     245,   711,   712,   713,   160,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,   714,
     715,   716,   719,   724,   725,   717,   728,   720,   729,   958,
     972,   982,   731,   421,   721,   722,   727,  1006,   734,   730,
     960,   978,   983,   993,   422,   732,   839,   733,   735,   738,
     736,   739,   737,   740,   741,   743,   746,   744,   748,   833,
     246,   747,   749,   750,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   751,   752,   753,
     754,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   761,   762,   127,   763,   764,   765,   766,   767,   773,
     961,   979,   984,   994,   423,   129,   130,   131,    32,   776,
     782,   783,   784,   247,   795,   248,   785,   786,   787,   788,
     796,   133,   134,   249,   250,   251,   252,   253,   135,   789,
     803,   790,   791,   136,   137,   138,   792,   793,   794,   797,
     798,   799,   801,   254,   802,   808,   838,   255,   144,   888,
     804,   892,   805,   807,   809,   256,   896,   810,   811,   900,
     815,   904,   928,   931,   816,   935,   817,  1002,   818,   819,
     820,   821,  1011,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   822,  1015,  1031,   823,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   824,   127,   357,  1032,  1033,   825,  1034,   153,   154,
    1035,   827,  1036,  1037,   129,   130,   131,  1038,  1039,  1040,
     828,  1042,  1051,   829,   835,   836,   837,  1052,  1054,  1055,
     133,   134,  1083,   250,   251,  1057,   253,   135,   160,  1058,
    1060,  1061,   136,   137,   138,  1063,  1064,  1067,  1078,  1079,
    1081,  1082,   254,  1084,  1085,  1086,   255,  1087,  1088,  1093,
    1094,  1095,  1098,  1099,   256,  1100,  1107,  1109,  1117,  1125,
    1120,  1124,  1128,  1127,  1132,  1137,  1130,  1131,  1133,  1134,
    1135,  1146,  1136,  1138,  1148,  1140,  1139,  1141,  1142,  1143,
    1144,  1145,   257,  1147,  1149,   363,  1150,  1151,   383,  1210,
    1211,  1161,  1239,   301,  1240,  1241,   377,   385,  1242,   397,
     386,  1243,  1204,  1216,   304,  1246,   341,   153,   154,   401,
     364,   258,  1244,   384,  1225,  1247,  1190,   343,  1248,  1249,
    1162,  1256,   264,  1250,   265,   958,   266,  1252,  1223,  1257,
     972,  1168,  1217,  1169,   982,  1170,   960,   160,  1259,  1260,
     267,   978,  1253,  1267,  1262,   983,  1280,  1006,   299,  1171,
    1254,   993,   307,   302,  1269,   321,   378,  1203,  1261,   398,
    1279,  1285,  1205,   314,   259,  1277,   325,   260,  1268,  1224,
     261,   262,   342,  1163,  1226,  1290,  1164,   344,  1291,  1165,
    1166,   263,  1292,  1297,   268,  1218,   269,  1298,  1219,  1299,
    1167,  1220,  1221,  1172,   270,  1173,   961,   271,   272,   273,
     274,   979,  1222,  1174,   275,   984,  1175,  1176,  1177,  1178,
     276,   994,  1300,  1179,  1270,   277,   278,  1303,   310,  1180,
     279,   324,   280,   315,  1181,  1182,   326,   281,   282,  1183,
     283,  1184,   284,   285,   293,   294,  1185,  1186,   295,  1187,
     296,  1188,  1189,  1196,  1197,  1304,  1307,  1198,  1311,  1199,
    1194,  1308,  1195,  1312,  1313,  1314,  1326,  1335,  1336,  1320,
    1339,  1321,  1341,   840,  1345,  1367,  1322,  1347,  1368,  1369,
    1373,  1377,   914,   677,  1323,   826,   842,   683,   834,  1154,
    1152,  1212,  1023,  1209,  1238,  1208,  1330,  1333,   726,  1245,
    1255,  1237,  1156,  1155,  1340,  1337,  1343,  1344,  1346,  1207,
     694,  1375,  1374,  1376,  1334,  1379,   355,  1158,  1380,  1157,
    1159,   308,   718,   309,   322,  1338,   323,  1236,  1282,  1160,
     723,  1281,  1235,  1283,  1284,  1020,  1258,   696,   702,   710,
    1234,   841,  1276,  1263,  1161,  1251,  1342,  1001,  1365,   742,
    1378,  1278,  1216,     0,     0,  1204,   745,     0,     0,     0,
       0,     0,  1324,  1225,     0,     0,     0,  1267,     0,  1190,
       0,     0,     0,  1162,     0,     0,     0,  1223,  1269,     0,
       0,  1217,     0,     0,  1168,     0,  1169,     0,  1170,     0,
       0,     0,  1268,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1171,     0,     0,     0,     0,     0,     0,     0,
    1203,     0,     0,     0,     0,  1205,     0,     0,  1224,     0,
       0,     0,     0,  1226,     0,     0,  1163,     0,     0,  1164,
       0,     0,  1165,  1166,  1218,     0,     0,  1219,  1270,     0,
    1220,  1221,     0,  1167,     0,     0,  1172,     0,  1173,     0,
       0,  1222,     0,     0,     0,     0,  1174,     0,     0,  1175,
    1176,  1177,  1178,     0,     0,     0,  1179,     0,     0,     0,
       0,     0,  1180,     0,     0,     0,     0,  1181,  1182,     0,
       0,     0,  1183,     0,  1184,     0,     0,     0,     0,  1185,
    1186,     0,  1187,     0,  1188,  1189,  1196,  1197,     0,     0,
    1198,     0,  1199,  1194,     0,  1195
  };

  const short
  Dhcp6Parser::yycheck_[] =
  {
      71,    72,    73,    74,    75,    76,    16,    78,    79,    80,
      81,   790,    72,    73,    74,    75,    76,    79,    78,    79,
      79,    81,   752,   784,    73,  1062,  1062,  1062,  1062,  1062,
     650,    73,    78,    79,     5,   137,     7,     7,     9,     0,
       3,     7,    73,     7,    73,     8,    73,   144,   145,   190,
     191,   192,   193,   224,    16,    17,    18,    19,    20,     7,
      73,    80,    81,    82,    83,    84,    85,    86,    73,    74,
      75,    76,    72,    73,    74,    75,    76,   209,    78,    79,
       7,    81,   691,     7,    73,     7,   227,    73,   107,   108,
      73,    73,   224,    10,   703,   704,   705,     3,     3,     7,
     135,    73,     8,     8,    73,   725,    73,   142,     3,     3,
      24,     3,     6,     8,    73,    24,     8,    73,    73,    73,
      73,     3,   224,    32,    73,     6,     8,   224,    79,     3,
      73,     7,     3,     3,     8,    73,    73,     8,     8,     3,
      73,     7,    73,    78,     8,   107,   108,    73,    73,   100,
      73,     7,    73,    73,    73,    73,   107,   108,    73,     7,
      73,     7,    74,    75,    74,    75,    80,     3,    82,    83,
      13,    14,     8,    87,    88,    89,   144,   145,   129,    11,
      12,    80,   133,    15,     3,   137,   138,     3,   140,    21,
      22,    23,     8,   107,   108,   187,   188,   201,   107,   108,
     204,   205,   206,   207,     4,   224,     3,     3,   107,   108,
       3,     8,     8,     6,   107,   108,     8,     3,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,   157,   158,
     159,   160,     3,   224,   225,   226,   227,     8,    90,    91,
      92,    93,   224,   107,   108,     4,    98,     4,  1305,  1305,
    1305,  1305,  1305,   224,     4,   107,   108,   170,   171,   172,
       3,     3,   114,     4,     4,     8,     8,   119,   120,   121,
     122,   123,   124,   125,     3,     3,   128,   126,   127,     8,
       8,   200,   134,   202,   203,     4,     3,  1068,     3,     6,
     224,   143,     4,     8,   146,   224,     4,  1096,     4,    79,
    1050,   153,     4,   167,   168,   224,     4,   107,   108,   161,
     162,   224,     4,     3,   166,     3,     3,   169,     8,     6,
       8,   173,   102,   103,   104,   105,   106,   107,   108,    25,
      26,    27,    50,    51,    52,    53,    54,    55,    94,    95,
      96,    97,   194,   195,   196,   197,   198,   199,     3,   129,
       4,     6,     3,   133,     3,     3,   208,     8,     4,     8,
     224,    79,    80,   163,   164,   165,     4,     4,     3,     3,
       3,    24,   224,     8,     8,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,   107,
     108,     4,    45,    46,    47,    48,    49,    42,    43,    44,
      79,   147,   148,   149,   150,   151,   152,   154,   155,   156,
       3,     3,   130,   131,   132,     8,     8,     3,   448,   449,
       3,     8,     8,     4,   224,     8,     4,    80,   107,   108,
       4,     4,     4,   524,   115,   116,   117,   118,     4,     4,
     531,     4,     4,     4,   224,     4,     4,     4,     4,   128,
       4,   531,   543,     4,     3,   546,   135,   136,   137,   138,
     139,   140,   553,   543,     4,     4,   546,     4,     4,   224,
       4,     4,   563,   553,   543,     4,     4,     8,     4,     4,
     225,   543,   573,   563,     8,     4,     4,     4,   579,     4,
       4,   225,   543,   573,   543,     8,   543,   579,     4,   579,
     579,     4,     4,     4,     4,     4,   224,   573,   599,     4,
     543,   531,     4,   579,     4,     4,     4,     4,   543,   599,
     225,   546,   225,   543,   225,   225,   546,   226,   553,   226,
     225,   225,   225,   553,   543,     4,   227,   543,   563,   225,
     543,   543,   226,   563,   227,   224,     4,   225,   225,     4,
       4,   543,   227,   573,   543,   227,   543,   107,   108,   579,
     227,   227,   226,     4,   543,   227,     4,   543,   543,   543,
     543,   224,     4,   225,   543,     4,     4,     4,     4,   599,
     543,     4,     4,     4,   227,   543,   543,   227,   227,     4,
     543,     4,   543,     4,     4,     4,     4,   543,   543,     4,
     543,     4,   543,   543,   543,   543,     4,   225,   543,     4,
     543,     4,     4,     4,   546,     4,   546,     4,   227,   227,
     227,   553,     4,   553,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,     4,     4,   227,
       4,   225,   227,   225,   194,   195,     4,     4,     4,     4,
     225,   227,     4,     4,     4,     4,   747,     4,   225,   750,
       4,   225,     4,     4,     4,   225,     4,     4,     4,     4,
     750,     4,     4,   225,   224,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,     4,
       4,     4,     4,     4,     4,   227,     4,   227,     4,   790,
     791,   792,     4,   794,   227,   227,   227,   798,     4,   225,
     790,   791,   792,   793,   794,   225,   746,   225,     4,     4,
     227,     4,   227,     4,     4,     4,     4,   225,   224,   189,
     750,     7,     7,     7,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     7,     7,     5,
     224,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,   224,   224,    79,     5,     5,     5,   224,   224,     5,
     790,   791,   792,   793,   794,    91,    92,    93,     7,   224,
       5,     5,     5,    99,   224,   101,     7,     5,     5,     5,
     224,   107,   108,   109,   110,   111,   112,   113,   114,     7,
     224,     7,     7,   119,   120,   121,     7,     7,     7,     5,
       7,     5,     5,   129,     5,     7,     5,   133,   134,     7,
     224,     7,   224,   224,   224,   141,     7,   224,   224,     7,
     224,     7,     7,     7,   224,     7,   224,     7,   224,   224,
     224,   224,     7,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,   224,     7,     4,   224,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,   224,    79,    80,     4,     4,   224,     4,   194,   195,
       4,   224,     4,     4,    91,    92,    93,     4,     4,     4,
     224,     4,     6,   224,   224,   224,   224,     3,     6,     3,
     107,   108,     4,   110,   111,     6,   113,   114,   224,     3,
       6,     3,   119,   120,   121,     6,     3,     6,     6,     3,
       6,     3,   129,     4,     4,     4,   133,     4,     4,     4,
       4,     4,     4,     4,   141,     4,     4,     4,     4,     3,
     224,     6,     3,     6,     4,   227,     8,     6,     4,     4,
       4,     4,   225,   225,     4,   225,   227,   225,   225,   225,
     225,   225,  1053,   225,     4,  1056,     4,     4,  1059,     4,
       4,  1062,   225,  1053,   225,   225,  1056,  1059,   225,  1059,
    1059,   225,  1062,  1074,  1053,     4,  1077,   194,   195,  1080,
    1056,  1053,   225,  1059,  1074,     4,  1062,  1077,   225,   225,
    1062,     4,  1053,   225,  1053,  1096,  1053,   227,  1074,     4,
    1101,  1062,  1074,  1062,  1105,  1062,  1096,   224,   227,     4,
    1053,  1101,   225,  1114,     4,  1105,     3,  1118,  1053,  1062,
     225,  1111,  1123,  1053,  1114,  1126,  1056,  1062,   225,  1059,
       6,     4,  1062,  1123,  1053,   227,  1126,  1053,  1114,  1074,
    1053,  1053,  1077,  1062,  1074,   224,  1062,  1077,   224,  1062,
    1062,  1053,   224,   224,  1053,  1074,  1053,   224,  1074,   224,
    1062,  1074,  1074,  1062,  1053,  1062,  1096,  1053,  1053,  1053,
    1053,  1101,  1074,  1062,  1053,  1105,  1062,  1062,  1062,  1062,
    1053,  1111,   224,  1062,  1114,  1053,  1053,     8,  1123,  1062,
    1053,  1126,  1053,  1123,  1062,  1062,  1126,  1053,  1053,  1062,
    1053,  1062,  1053,  1053,  1053,  1053,  1062,  1062,  1053,  1062,
    1053,  1062,  1062,  1062,  1062,     8,   224,  1062,     4,  1062,
    1062,   224,  1062,     8,     3,     8,     4,     4,     4,   224,
       4,   224,     4,   747,     5,     4,   224,     7,     4,     4,
       4,     4,   783,   524,   224,   725,   750,   531,   738,  1052,
    1047,  1072,   838,  1068,  1082,  1065,   224,   224,   582,  1089,
    1101,  1080,  1055,  1053,   225,   227,   224,   224,   224,  1064,
     543,   225,   227,   225,  1305,   224,    77,  1058,   224,  1056,
    1059,  1123,   573,  1123,  1126,  1313,  1126,  1079,  1125,  1061,
     579,  1123,  1077,  1126,  1128,   808,  1105,   546,   553,   563,
    1075,   749,  1115,  1111,  1305,  1096,  1328,   794,  1351,   599,
    1371,  1118,  1313,    -1,    -1,  1305,   603,    -1,    -1,    -1,
      -1,    -1,  1262,  1313,    -1,    -1,    -1,  1328,    -1,  1305,
      -1,    -1,    -1,  1305,    -1,    -1,    -1,  1313,  1328,    -1,
      -1,  1313,    -1,    -1,  1305,    -1,  1305,    -1,  1305,    -1,
      -1,    -1,  1328,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1305,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1305,    -1,    -1,    -1,    -1,  1305,    -1,    -1,  1313,    -1,
      -1,    -1,    -1,  1313,    -1,    -1,  1305,    -1,    -1,  1305,
      -1,    -1,  1305,  1305,  1313,    -1,    -1,  1313,  1328,    -1,
    1313,  1313,    -1,  1305,    -1,    -1,  1305,    -1,  1305,    -1,
      -1,  1313,    -1,    -1,    -1,    -1,  1305,    -1,    -1,  1305,
    1305,  1305,  1305,    -1,    -1,    -1,  1305,    -1,    -1,    -1,
      -1,    -1,  1305,    -1,    -1,    -1,    -1,  1305,  1305,    -1,
      -1,    -1,  1305,    -1,  1305,    -1,    -1,    -1,    -1,  1305,
    1305,    -1,  1305,    -1,  1305,  1305,  1305,  1305,    -1,    -1,
    1305,    -1,  1305,  1305,    -1,  1305
  };

  const short
  Dhcp6Parser::yystos_[] =
  {
       0,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
       0,     5,     7,     9,   224,   225,   226,   227,   244,   245,
     246,   251,     7,   260,     7,   265,     7,   320,     7,   434,
       7,   515,     7,   531,     7,   548,     7,   466,     7,   472,
       7,   496,     7,   410,     7,   619,     7,   650,   252,   247,
     261,   266,   321,   435,   516,   532,   549,   467,   473,   497,
     411,   620,   651,   244,   253,   254,   224,   249,   250,    10,
     262,   264,    11,    12,    15,    21,    22,    23,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    90,    91,
      92,    93,    98,   107,   108,   114,   119,   120,   121,   122,
     123,   124,   125,   128,   134,   143,   146,   153,   161,   162,
     166,   169,   173,   194,   195,   196,   197,   198,   199,   208,
     224,   259,   267,   268,   269,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   291,   293,   295,   296,   297,   300,   301,
     303,   305,   306,   307,   308,   310,   311,   313,   315,   316,
     317,   318,   330,   332,   334,   375,   383,   389,   395,   397,
     404,   418,   428,   448,   449,   450,   451,   456,   464,   490,
     521,   523,   542,   572,   586,   598,   599,   607,   617,   648,
     657,   681,    16,    17,    18,    19,    20,   259,   322,   323,
     324,   326,   327,   328,   329,   521,   523,    99,   101,   109,
     110,   111,   112,   113,   129,   133,   141,   259,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   285,   286,   287,   288,   291,   293,   295,   296,   297,
     300,   301,   303,   305,   311,   313,   436,   437,   438,   440,
     442,   444,   446,   448,   449,   450,   451,   454,   455,   490,
     509,   521,   523,   525,   542,   567,   100,   259,   444,   446,
     490,   517,   518,   519,   521,   523,   102,   103,   104,   105,
     106,   259,   444,   446,   490,   521,   523,   533,   534,   535,
     537,   538,   540,   541,   128,   135,   136,   137,   138,   139,
     140,   259,   490,   521,   523,   550,   551,   552,   553,   555,
     557,   559,   561,   563,   565,   464,    24,    80,    82,    83,
      87,    88,    89,   259,   352,   474,   475,   476,   477,   478,
     479,   480,   482,   484,   486,   487,   489,   521,   523,    81,
      84,    85,    86,   259,   352,   478,   484,   498,   499,   500,
     501,   502,   504,   505,   506,   507,   508,   521,   523,   144,
     145,   259,   412,   413,   414,   416,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   194,
     195,   259,   521,   523,   621,   622,   623,   624,   626,   628,
     629,   631,   632,   633,   636,   638,   639,   640,   642,   644,
     646,    13,    14,   652,   653,   654,   656,     6,     3,     4,
       8,     3,   263,     3,     8,   270,   649,   319,   331,   333,
     335,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,   309,     4,     4,     4,     4,
       4,   289,   292,   294,     4,     4,     4,     4,   429,   465,
     491,     4,   312,   314,   298,   457,   522,   524,   452,     4,
       4,     4,   384,   396,   390,   376,   573,   543,   405,   419,
     587,     4,   398,   600,   608,   618,   302,   304,     4,     4,
       4,   658,   682,     4,     3,     8,   325,     4,     4,     4,
       4,     3,     8,   510,   526,   439,   441,   443,     4,     4,
     447,   445,   568,     3,     8,   520,     3,     8,   536,     4,
     539,     4,     4,     3,     8,   566,   554,   556,   558,   560,
     562,   564,     8,     3,     8,   481,   353,     4,   485,   483,
     488,     4,     8,     3,   503,     4,     4,     4,     8,     3,
     415,   417,     3,     8,     4,   625,   627,     4,   630,     4,
       4,   634,   637,     4,     4,   641,   643,   645,   647,     3,
       8,   655,     4,     3,     8,   244,   244,   224,     4,     4,
       4,     4,     4,     4,     4,   225,   225,   225,   225,   225,
     225,   225,   225,   227,   226,   226,   226,   225,   225,     4,
     225,   225,   227,   227,   227,     4,     4,     4,   227,   227,
     226,   227,     4,     4,     4,   225,     4,     4,     4,     4,
       4,     4,     4,   227,   227,   227,     4,     4,     4,     4,
       4,     4,     4,     4,     4,   225,     4,     4,     4,     4,
       4,     4,   227,   227,   227,     4,     4,   268,     4,   227,
     227,   225,   225,   323,     4,     4,     4,     4,     4,   225,
     227,     4,     4,     4,   437,     4,   518,     4,   225,     4,
     225,   225,   534,     4,     4,     4,     4,     4,     4,     4,
     552,     4,     4,   225,     4,     4,     4,   227,   476,     4,
     227,   227,   227,   500,     4,     4,   413,   227,     4,     4,
     225,     4,   225,   225,     4,     4,   227,   227,     4,     4,
       4,     4,   622,     4,   225,   653,     4,     7,   224,     7,
       7,     7,     7,     5,   224,   190,   191,   192,   193,   227,
     290,   224,   224,     5,     5,     5,   224,   224,    94,    95,
      96,    97,   299,     5,   246,   248,   224,   115,   116,   117,
     118,   453,     5,     5,     5,     7,     5,     5,     5,     7,
       7,     7,     7,     7,     7,   224,   224,     5,     7,     5,
     255,     5,     5,   224,   224,   224,   255,   224,     7,   224,
     224,   224,   255,   255,   255,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   248,   224,   224,   224,
     187,   188,   635,   189,   290,   224,   224,   224,     5,   244,
     267,   652,   322,    24,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    45,    46,
      47,    48,    49,   259,   340,   341,   342,   345,   347,   349,
     351,   352,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   365,   366,   367,   369,   371,   373,   340,     7,   336,
     337,   338,     7,   430,   431,   432,     7,   468,   469,   470,
       7,   492,   493,   494,     7,   458,   459,   460,   137,   224,
     385,   386,   387,   388,   253,   138,   140,   387,   391,   392,
     393,   394,   126,   127,   377,   378,   379,   381,     7,   574,
     575,     7,   544,   545,   546,     7,   406,   407,   408,   147,
     148,   149,   150,   151,   152,   420,   421,   422,   423,   424,
     425,   426,   427,    24,   157,   158,   159,   160,   259,   354,
     521,   523,   588,   589,   590,   593,   594,   596,   597,   163,
     164,   165,   259,   399,   400,   401,   402,   403,   521,   523,
     167,   168,   259,   521,   523,   601,   602,   603,   605,   170,
     171,   172,   224,   521,   523,   609,   610,   611,   612,   614,
     615,   621,     7,   659,   660,   209,   259,   683,   684,   685,
     256,     7,   511,   512,   513,     7,   527,   528,   529,   142,
     553,   569,   570,   336,     8,     8,     8,   343,   346,   348,
     350,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,   363,     4,   368,   370,   372,   374,     3,     8,     8,
     339,     6,     3,   433,     6,     3,   471,     6,     3,   495,
       6,     3,   461,     6,     3,     3,     6,     6,     3,     6,
     380,   382,     3,     8,   576,     3,     6,   547,     6,     3,
     409,     6,     3,     4,     4,     4,     4,     4,     4,     3,
       8,   591,   595,     4,     4,     4,     3,     8,     4,     4,
       4,     3,     8,   604,   606,     3,     8,     4,   613,     4,
     616,     3,     8,     8,   661,     3,     6,     4,     3,     8,
     224,   257,   258,   514,     6,     3,   530,     6,     3,   571,
       8,     6,     4,     4,     4,     4,   225,   227,   225,   227,
     225,   225,   225,   225,   225,   225,     4,   225,     4,     4,
       4,     4,   341,   340,   338,   436,   432,   474,   470,   498,
     494,   259,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   285,   286,   287,   288,   291,
     293,   295,   296,   297,   300,   301,   303,   305,   311,   313,
     352,   428,   440,   442,   444,   446,   448,   449,   450,   451,
     455,   462,   463,   490,   521,   523,   567,   460,   386,   392,
       4,     4,   378,   130,   131,   132,   259,   271,   272,   273,
     274,   275,   276,   352,   490,   521,   523,   577,   578,   579,
     580,   581,   583,   585,   575,   550,   546,   412,   408,   225,
     225,   225,   225,   225,   225,   421,     4,     4,   225,   225,
     225,   589,   227,   225,   225,   400,     4,     4,   602,   227,
       4,   225,     4,   610,   200,   202,   203,   259,   352,   521,
     523,   662,   663,   664,   665,   667,   660,   227,   684,     6,
       3,   517,   513,   533,   529,     4,    25,    26,    27,   344,
     224,   224,   224,    42,    43,    44,   364,   224,   224,   224,
     224,     8,     8,     8,     8,     3,     8,   224,   224,   582,
     584,     4,     8,     3,     8,     8,   154,   155,   156,   592,
     224,   224,   224,   224,   244,   668,     4,   666,     3,     8,
     224,     8,     8,   224,   463,     4,     4,   227,   579,     4,
     225,     4,   663,   224,   224,     5,   224,     7,   669,   670,
     671,     3,     6,   201,   204,   205,   206,   207,   672,   673,
     674,   676,   677,   678,   679,   670,   675,     4,     4,     4,
     680,     3,     8,     4,   227,   225,   225,     4,   673,   224,
     224
  };

  const short
  Dhcp6Parser::yyr1_[] =
  {
       0,   228,   230,   229,   231,   229,   232,   229,   233,   229,
     234,   229,   235,   229,   236,   229,   237,   229,   238,   229,
     239,   229,   240,   229,   241,   229,   242,   229,   243,   229,
     244,   244,   244,   244,   244,   244,   244,   245,   247,   246,
     248,   249,   249,   250,   250,   250,   252,   251,   253,   253,
     254,   254,   254,   256,   255,   257,   257,   258,   258,   258,
     259,   261,   260,   263,   262,   262,   264,   266,   265,   267,
     267,   267,   268,   268,   268,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     268,   270,   269,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     289,   288,   290,   290,   290,   290,   290,   292,   291,   294,
     293,   295,   296,   298,   297,   299,   299,   299,   299,   300,
     302,   301,   304,   303,   305,   306,   307,   309,   308,   310,
     312,   311,   314,   313,   315,   316,   317,   319,   318,   321,
     320,   322,   322,   322,   323,   323,   323,   323,   323,   323,
     323,   323,   325,   324,   326,   327,   328,   329,   331,   330,
     333,   332,   335,   334,   336,   336,   337,   337,   337,   339,
     338,   340,   340,   340,   341,   341,   341,   341,   341,   341,
     341,   341,   341,   341,   341,   341,   341,   341,   341,   341,
     341,   341,   341,   341,   341,   341,   343,   342,   344,   344,
     344,   346,   345,   348,   347,   350,   349,   351,   353,   352,
     354,   355,   356,   357,   358,   359,   360,   361,   363,   362,
     364,   364,   364,   365,   366,   368,   367,   370,   369,   372,
     371,   374,   373,   376,   375,   377,   377,   377,   378,   378,
     380,   379,   382,   381,   384,   383,   385,   385,   385,   386,
     386,   387,   388,   390,   389,   391,   391,   391,   392,   392,
     392,   393,   394,   396,   395,   398,   397,   399,   399,   399,
     400,   400,   400,   400,   400,   400,   401,   402,   403,   405,
     404,   406,   406,   407,   407,   407,   409,   408,   411,   410,
     412,   412,   412,   412,   413,   413,   415,   414,   417,   416,
     419,   418,   420,   420,   420,   421,   421,   421,   421,   421,
     421,   422,   423,   424,   425,   426,   427,   429,   428,   430,
     430,   431,   431,   431,   433,   432,   435,   434,   436,   436,
     436,   437,   437,   437,   437,   437,   437,   437,   437,   437,
     437,   437,   437,   437,   437,   437,   437,   437,   437,   437,
     437,   437,   437,   437,   437,   437,   437,   437,   437,   437,
     437,   437,   437,   437,   437,   437,   437,   437,   437,   437,
     437,   437,   437,   437,   437,   437,   437,   437,   439,   438,
     441,   440,   443,   442,   445,   444,   447,   446,   448,   449,
     450,   452,   451,   453,   453,   453,   453,   454,   455,   457,
     456,   458,   458,   459,   459,   459,   461,   460,   462,   462,
     462,   463,   463,   463,   463,   463,   463,   463,   463,   463,
     463,   463,   463,   463,   463,   463,   463,   463,   463,   463,
     463,   463,   463,   463,   463,   463,   463,   463,   463,   463,
     463,   463,   463,   463,   463,   463,   463,   463,   463,   463,
     463,   463,   463,   463,   463,   465,   464,   467,   466,   468,
     468,   469,   469,   469,   471,   470,   473,   472,   474,   474,
     475,   475,   475,   476,   476,   476,   476,   476,   476,   476,
     476,   476,   476,   477,   478,   479,   481,   480,   483,   482,
     485,   484,   486,   488,   487,   489,   491,   490,   492,   492,
     493,   493,   493,   495,   494,   497,   496,   498,   498,   499,
     499,   499,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   501,   503,   502,   504,   505,   506,   507,   508,
     510,   509,   511,   511,   512,   512,   512,   514,   513,   516,
     515,   517,   517,   517,   518,   518,   518,   518,   518,   518,
     518,   520,   519,   522,   521,   524,   523,   526,   525,   527,
     527,   528,   528,   528,   530,   529,   532,   531,   533,   533,
     533,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   536,   535,   537,   539,   538,   540,   541,   543,
     542,   544,   544,   545,   545,   545,   547,   546,   549,   548,
     550,   550,   551,   551,   551,   552,   552,   552,   552,   552,
     552,   552,   552,   552,   552,   552,   554,   553,   556,   555,
     558,   557,   560,   559,   562,   561,   564,   563,   566,   565,
     568,   567,   569,   569,   571,   570,   573,   572,   574,   574,
     574,   576,   575,   577,   577,   578,   578,   578,   579,   579,
     579,   579,   579,   579,   579,   579,   579,   579,   579,   579,
     579,   579,   580,   582,   581,   584,   583,   585,   587,   586,
     588,   588,   588,   589,   589,   589,   589,   589,   589,   589,
     589,   589,   591,   590,   592,   592,   592,   593,   595,   594,
     596,   597,   598,   600,   599,   601,   601,   601,   602,   602,
     602,   602,   602,   604,   603,   606,   605,   608,   607,   609,
     609,   609,   610,   610,   610,   610,   610,   610,   611,   613,
     612,   614,   616,   615,   618,   617,   620,   619,   621,   621,
     621,   622,   622,   622,   622,   622,   622,   622,   622,   622,
     622,   622,   622,   622,   622,   622,   622,   622,   622,   623,
     625,   624,   627,   626,   628,   630,   629,   631,   632,   634,
     633,   635,   635,   637,   636,   638,   639,   641,   640,   643,
     642,   645,   644,   647,   646,   649,   648,   651,   650,   652,
     652,   652,   653,   653,   655,   654,   656,   658,   657,   659,
     659,   659,   661,   660,   662,   662,   662,   663,   663,   663,
     663,   663,   663,   663,   664,   666,   665,   668,   667,   669,
     669,   669,   671,   670,   672,   672,   672,   673,   673,   673,
     673,   673,   675,   674,   676,   677,   678,   680,   679,   682,
     681,   683,   683,   683,   684,   684,   685
  };

  const signed char
  Dhcp6Parser::yyr2_[] =
  {
       0,     2,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     4,
       1,     0,     1,     3,     5,     2,     0,     4,     0,     1,
       1,     3,     2,     0,     4,     0,     1,     1,     3,     2,
       2,     0,     4,     0,     6,     1,     2,     0,     4,     1,
       3,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       0,     4,     1,     1,     1,     1,     1,     0,     4,     0,
       4,     3,     3,     0,     4,     1,     1,     1,     1,     3,
       0,     4,     0,     4,     3,     3,     3,     0,     4,     3,
       0,     4,     0,     4,     3,     3,     3,     0,     6,     0,
       4,     1,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     4,     3,     3,     3,     3,     0,     6,
       0,     6,     0,     6,     0,     1,     1,     3,     2,     0,
       4,     1,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     4,     1,     1,
       1,     0,     4,     0,     4,     0,     4,     3,     0,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     0,     4,
       1,     1,     1,     3,     3,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     6,     1,     3,     2,     1,     1,
       0,     4,     0,     4,     0,     6,     1,     3,     2,     1,
       1,     1,     1,     0,     6,     1,     3,     2,     1,     1,
       1,     1,     1,     0,     6,     0,     6,     1,     3,     2,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     0,
       6,     0,     1,     1,     3,     2,     0,     4,     0,     4,
       1,     3,     2,     1,     1,     1,     0,     4,     0,     4,
       0,     6,     1,     3,     2,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     0,     6,     0,
       1,     1,     3,     2,     0,     4,     0,     4,     1,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     3,     3,
       3,     0,     4,     1,     1,     1,     1,     3,     3,     0,
       6,     0,     1,     1,     3,     2,     0,     4,     1,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     6,     0,     4,     0,
       1,     1,     3,     2,     0,     4,     0,     4,     0,     1,
       1,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     0,     4,     0,     4,
       0,     4,     1,     0,     4,     3,     0,     6,     0,     1,
       1,     3,     2,     0,     4,     0,     4,     0,     1,     1,
       3,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     4,     1,     1,     3,     3,     3,
       0,     6,     0,     1,     1,     3,     2,     0,     4,     0,
       4,     1,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     0,     4,     0,     4,     0,     4,     0,     6,     0,
       1,     1,     3,     2,     0,     4,     0,     4,     1,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     4,     3,     0,     4,     3,     3,     0,
       6,     0,     1,     1,     3,     2,     0,     4,     0,     4,
       0,     1,     1,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     6,     1,     1,     0,     4,     0,     6,     1,     3,
       2,     0,     4,     0,     1,     1,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     4,     0,     4,     3,     0,     6,
       1,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     4,     1,     1,     1,     3,     0,     4,
       3,     3,     3,     0,     6,     1,     3,     2,     1,     1,
       1,     1,     1,     0,     4,     0,     4,     0,     6,     1,
       3,     2,     1,     1,     1,     1,     1,     1,     3,     0,
       4,     3,     0,     4,     0,     6,     0,     4,     1,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       0,     4,     0,     4,     3,     0,     4,     3,     3,     0,
       4,     1,     1,     0,     4,     3,     3,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     6,     0,     4,     1,
       3,     2,     1,     1,     0,     6,     3,     0,     6,     1,
       3,     2,     0,     4,     1,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     3,     0,     4,     0,     6,     1,
       3,     2,     0,     4,     1,     3,     2,     1,     1,     1,
       1,     1,     0,     4,     3,     3,     3,     0,     4,     0,
       6,     1,     3,     2,     1,     1,     3
  };


#if PARSER6_DEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Dhcp6Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "\",\"", "\":\"",
  "\"[\"", "\"]\"", "\"{\"", "\"}\"", "\"null\"", "\"Dhcp6\"",
  "\"data-directory\"", "\"config-control\"", "\"config-databases\"",
  "\"config-fetch-wait-time\"", "\"interfaces-config\"", "\"interfaces\"",
  "\"re-detect\"", "\"service-sockets-require-all\"",
  "\"service-sockets-retry-wait-time\"", "\"service-sockets-max-retries\"",
  "\"lease-database\"", "\"hosts-database\"", "\"hosts-databases\"",
  "\"type\"", "\"memfile\"", "\"mysql\"", "\"postgresql\"", "\"user\"",
  "\"password\"", "\"host\"", "\"port\"", "\"persist\"",
  "\"lfc-interval\"", "\"readonly\"", "\"connect-timeout\"",
  "\"read-timeout\"", "\"write-timeout\"", "\"tcp-user-timeout\"",
  "\"max-reconnect-tries\"", "\"reconnect-wait-time\"", "\"on-fail\"",
  "\"stop-retry-exit\"", "\"serve-retry-exit\"",
  "\"serve-retry-continue\"", "\"max-row-errors\"", "\"trust-anchor\"",
  "\"cert-file\"", "\"key-file\"", "\"cipher-list\"",
  "\"preferred-lifetime\"", "\"min-preferred-lifetime\"",
  "\"max-preferred-lifetime\"", "\"valid-lifetime\"",
  "\"min-valid-lifetime\"", "\"max-valid-lifetime\"", "\"renew-timer\"",
  "\"rebind-timer\"", "\"calculate-tee-times\"", "\"t1-percent\"",
  "\"t2-percent\"", "\"cache-threshold\"", "\"cache-max-age\"",
  "\"decline-probation-period\"", "\"server-tag\"",
  "\"statistic-default-sample-count\"", "\"statistic-default-sample-age\"",
  "\"ddns-send-updates\"", "\"ddns-override-no-update\"",
  "\"ddns-override-client-update\"", "\"ddns-replace-client-name\"",
  "\"ddns-generated-prefix\"", "\"ddns-qualifying-suffix\"",
  "\"ddns-update-on-renew\"", "\"ddns-use-conflict-resolution\"",
  "\"ddns-ttl-percent\"", "\"store-extended-info\"", "\"subnet6\"",
  "\"option-def\"", "\"option-data\"", "\"name\"", "\"data\"", "\"code\"",
  "\"space\"", "\"csv-format\"", "\"always-send\"", "\"never-send\"",
  "\"record-types\"", "\"encapsulate\"", "\"array\"",
  "\"parked-packet-limit\"", "\"allocator\"", "\"pd-allocator\"",
  "\"ddns-conflict-resolution-mode\"", "\"check-with-dhcid\"",
  "\"no-check-with-dhcid\"", "\"check-exists-with-dhcid\"",
  "\"no-check-without-dhcid\"", "\"shared-networks\"", "\"pools\"",
  "\"pool\"", "\"pd-pools\"", "\"prefix\"", "\"prefix-len\"",
  "\"excluded-prefix\"", "\"excluded-prefix-len\"", "\"delegated-len\"",
  "\"user-context\"", "\"comment\"", "\"subnet\"", "\"interface\"",
  "\"interface-id\"", "\"id\"", "\"rapid-commit\"", "\"reservation-mode\"",
  "\"disabled\"", "\"out-of-pool\"", "\"global\"", "\"all\"",
  "\"reservations-global\"", "\"reservations-in-subnet\"",
  "\"reservations-out-of-pool\"", "\"mac-sources\"",
  "\"relay-supplied-options\"", "\"host-reservation-identifiers\"",
  "\"sanity-checks\"", "\"lease-checks\"", "\"extended-info-checks\"",
  "\"client-classes\"", "\"require-client-classes\"", "\"test\"",
  "\"template-test\"", "\"only-if-required\"", "\"client-class\"",
  "\"reservations\"", "\"ip-addresses\"", "\"prefixes\"", "\"duid\"",
  "\"hw-address\"", "\"hostname\"", "\"flex-id\"", "\"relay\"",
  "\"ip-address\"", "\"hooks-libraries\"", "\"library\"", "\"parameters\"",
  "\"expired-leases-processing\"", "\"reclaim-timer-wait-time\"",
  "\"flush-reclaimed-timer-wait-time\"", "\"hold-reclaimed-time\"",
  "\"max-reclaim-leases\"", "\"max-reclaim-time\"",
  "\"unwarned-reclaim-cycles\"", "\"server-id\"", "\"LLT\"", "\"EN\"",
  "\"LL\"", "\"identifier\"", "\"htype\"", "\"time\"", "\"enterprise-id\"",
  "\"dhcp4o6-port\"", "\"multi-threading\"", "\"enable-multi-threading\"",
  "\"thread-pool-size\"", "\"packet-queue-size\"", "\"control-socket\"",
  "\"socket-type\"", "\"socket-name\"", "\"dhcp-queue-control\"",
  "\"enable-queue\"", "\"queue-type\"", "\"capacity\"", "\"dhcp-ddns\"",
  "\"enable-updates\"", "\"qualifying-suffix\"", "\"server-ip\"",
  "\"server-port\"", "\"sender-ip\"", "\"sender-port\"",
  "\"max-queue-size\"", "\"ncr-protocol\"", "\"ncr-format\"",
  "\"override-no-update\"", "\"override-client-update\"",
  "\"replace-client-name\"", "\"generated-prefix\"", "\"UDP\"", "\"TCP\"",
  "\"JSON\"", "\"when-present\"", "\"never\"", "\"always\"",
  "\"when-not-present\"", "\"hostname-char-set\"",
  "\"hostname-char-replacement\"", "\"early-global-reservations-lookup\"",
  "\"ip-reservations-unique\"", "\"reservations-lookup-first\"",
  "\"loggers\"", "\"output_options\"", "\"output\"", "\"debuglevel\"",
  "\"severity\"", "\"flush\"", "\"maxsize\"", "\"maxver\"", "\"pattern\"",
  "\"compatibility\"", "\"lenient-option-parsing\"", "TOPLEVEL_JSON",
  "TOPLEVEL_DHCP6", "SUB_DHCP6", "SUB_INTERFACES6", "SUB_SUBNET6",
  "SUB_POOL6", "SUB_PD_POOL", "SUB_RESERVATION", "SUB_OPTION_DEFS",
  "SUB_OPTION_DEF", "SUB_OPTION_DATA", "SUB_HOOKS_LIBRARY",
  "SUB_DHCP_DDNS", "SUB_CONFIG_CONTROL", "\"constant string\"",
  "\"integer\"", "\"floating point\"", "\"boolean\"", "$accept", "start",
  "$@1", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9", "$@10",
  "$@11", "$@12", "$@13", "$@14", "value", "sub_json", "map2", "$@15",
  "map_value", "map_content", "not_empty_map", "list_generic", "$@16",
  "list_content", "not_empty_list", "list_strings", "$@17",
  "list_strings_content", "not_empty_list_strings", "unknown_map_entry",
  "syntax_map", "$@18", "global_object", "$@19", "global_object_comma",
  "sub_dhcp6", "$@20", "global_params", "global_param", "data_directory",
  "$@21", "preferred_lifetime", "min_preferred_lifetime",
  "max_preferred_lifetime", "valid_lifetime", "min_valid_lifetime",
  "max_valid_lifetime", "renew_timer", "rebind_timer",
  "calculate_tee_times", "t1_percent", "t2_percent", "cache_threshold",
  "cache_max_age", "decline_probation_period", "ddns_send_updates",
  "ddns_override_no_update", "ddns_override_client_update",
  "ddns_replace_client_name", "$@22", "ddns_replace_client_name_value",
  "ddns_generated_prefix", "$@23", "ddns_qualifying_suffix", "$@24",
  "ddns_update_on_renew", "ddns_use_conflict_resolution",
  "ddns_conflict_resolution_mode", "$@25",
  "ddns_conflict_resolution_mode_value", "ddns_ttl_percent",
  "hostname_char_set", "$@26", "hostname_char_replacement", "$@27",
  "store_extended_info", "statistic_default_sample_count",
  "statistic_default_sample_age", "server_tag", "$@28",
  "parked_packet_limit", "allocator", "$@29", "pd_allocator", "$@30",
  "early_global_reservations_lookup", "ip_reservations_unique",
  "reservations_lookup_first", "interfaces_config", "$@31",
  "sub_interfaces6", "$@32", "interfaces_config_params",
  "interfaces_config_param", "interfaces_list", "$@33", "re_detect",
  "service_sockets_require_all", "service_sockets_retry_wait_time",
  "service_sockets_max_retries", "lease_database", "$@34",
  "hosts_database", "$@35", "hosts_databases", "$@36", "database_list",
  "not_empty_database_list", "database", "$@37", "database_map_params",
  "database_map_param", "database_type", "$@38", "db_type", "user", "$@39",
  "password", "$@40", "host", "$@41", "port", "name", "$@42", "persist",
  "lfc_interval", "readonly", "connect_timeout", "read_timeout",
  "write_timeout", "tcp_user_timeout", "reconnect_wait_time", "on_fail",
  "$@43", "on_fail_mode", "max_row_errors", "max_reconnect_tries",
  "trust_anchor", "$@44", "cert_file", "$@45", "key_file", "$@46",
  "cipher_list", "$@47", "sanity_checks", "$@48", "sanity_checks_params",
  "sanity_checks_param", "lease_checks", "$@49", "extended_info_checks",
  "$@50", "mac_sources", "$@51", "mac_sources_list", "mac_sources_value",
  "duid_id", "string_id", "host_reservation_identifiers", "$@52",
  "host_reservation_identifiers_list", "host_reservation_identifier",
  "hw_address_id", "flex_id", "relay_supplied_options", "$@53",
  "dhcp_multi_threading", "$@54", "multi_threading_params",
  "multi_threading_param", "enable_multi_threading", "thread_pool_size",
  "packet_queue_size", "hooks_libraries", "$@55", "hooks_libraries_list",
  "not_empty_hooks_libraries_list", "hooks_library", "$@56",
  "sub_hooks_library", "$@57", "hooks_params", "hooks_param", "library",
  "$@58", "parameters", "$@59", "expired_leases_processing", "$@60",
  "expired_leases_params", "expired_leases_param",
  "reclaim_timer_wait_time", "flush_reclaimed_timer_wait_time",
  "hold_reclaimed_time", "max_reclaim_leases", "max_reclaim_time",
  "unwarned_reclaim_cycles", "subnet6_list", "$@61",
  "subnet6_list_content", "not_empty_subnet6_list", "subnet6", "$@62",
  "sub_subnet6", "$@63", "subnet6_params", "subnet6_param", "subnet",
  "$@64", "interface", "$@65", "interface_id", "$@66", "client_class",
  "$@67", "require_client_classes", "$@68", "reservations_global",
  "reservations_in_subnet", "reservations_out_of_pool", "reservation_mode",
  "$@69", "hr_mode", "id", "rapid_commit", "shared_networks", "$@70",
  "shared_networks_content", "shared_networks_list", "shared_network",
  "$@71", "shared_network_params", "shared_network_param",
  "option_def_list", "$@72", "sub_option_def_list", "$@73",
  "option_def_list_content", "not_empty_option_def_list",
  "option_def_entry", "$@74", "sub_option_def", "$@75",
  "option_def_params", "not_empty_option_def_params", "option_def_param",
  "option_def_name", "code", "option_def_code", "option_def_type", "$@76",
  "option_def_record_types", "$@77", "space", "$@78", "option_def_space",
  "option_def_encapsulate", "$@79", "option_def_array", "option_data_list",
  "$@80", "option_data_list_content", "not_empty_option_data_list",
  "option_data_entry", "$@81", "sub_option_data", "$@82",
  "option_data_params", "not_empty_option_data_params",
  "option_data_param", "option_data_name", "option_data_data", "$@83",
  "option_data_code", "option_data_space", "option_data_csv_format",
  "option_data_always_send", "option_data_never_send", "pools_list",
  "$@84", "pools_list_content", "not_empty_pools_list", "pool_list_entry",
  "$@85", "sub_pool6", "$@86", "pool_params", "pool_param", "pool_entry",
  "$@87", "user_context", "$@88", "comment", "$@89", "pd_pools_list",
  "$@90", "pd_pools_list_content", "not_empty_pd_pools_list",
  "pd_pool_entry", "$@91", "sub_pd_pool", "$@92", "pd_pool_params",
  "pd_pool_param", "pd_prefix", "$@93", "pd_prefix_len", "excluded_prefix",
  "$@94", "excluded_prefix_len", "pd_delegated_len", "reservations",
  "$@95", "reservations_list", "not_empty_reservations_list",
  "reservation", "$@96", "sub_reservation", "$@97", "reservation_params",
  "not_empty_reservation_params", "reservation_param", "ip_addresses",
  "$@98", "prefixes", "$@99", "duid", "$@100", "hw_address", "$@101",
  "hostname", "$@102", "flex_id_value", "$@103",
  "reservation_client_classes", "$@104", "relay", "$@105", "relay_map",
  "ip_address", "$@106", "client_classes", "$@107", "client_classes_list",
  "client_class_entry", "$@108", "client_class_params",
  "not_empty_client_class_params", "client_class_param",
  "client_class_name", "client_class_test", "$@109",
  "client_class_template_test", "$@110", "only_if_required", "server_id",
  "$@111", "server_id_params", "server_id_param", "server_id_type",
  "$@112", "duid_type", "htype", "identifier", "$@113", "time",
  "enterprise_id", "dhcp4o6_port", "control_socket", "$@114",
  "control_socket_params", "control_socket_param", "socket_type", "$@115",
  "socket_name", "$@116", "dhcp_queue_control", "$@117",
  "queue_control_params", "queue_control_param", "enable_queue",
  "queue_type", "$@118", "capacity", "arbitrary_map_entry", "$@119",
  "dhcp_ddns", "$@120", "sub_dhcp_ddns", "$@121", "dhcp_ddns_params",
  "dhcp_ddns_param", "enable_updates", "dep_qualifying_suffix", "$@122",
  "server_ip", "$@123", "server_port", "sender_ip", "$@124", "sender_port",
  "max_queue_size", "ncr_protocol", "$@125", "ncr_protocol_value",
  "ncr_format", "$@126", "dep_override_no_update",
  "dep_override_client_update", "dep_replace_client_name", "$@127",
  "dep_generated_prefix", "$@128", "dep_hostname_char_set", "$@129",
  "dep_hostname_char_replacement", "$@130", "config_control", "$@131",
  "sub_config_control", "$@132", "config_control_params",
  "config_control_param", "config_databases", "$@133",
  "config_fetch_wait_time", "loggers", "$@134", "loggers_entries",
  "logger_entry", "$@135", "logger_params", "logger_param", "debuglevel",
  "severity", "$@136", "output_options_list", "$@137",
  "output_options_list_content", "output_entry", "$@138",
  "output_params_list", "output_params", "output", "$@139", "flush",
  "maxsize", "maxver", "pattern", "$@140", "compatibility", "$@141",
  "compatibility_params", "compatibility_param", "lenient_option_parsing", YY_NULLPTR
  };
#endif


#if PARSER6_DEBUG
  const short
  Dhcp6Parser::yyrline_[] =
  {
       0,   322,   322,   322,   323,   323,   324,   324,   325,   325,
     326,   326,   327,   327,   328,   328,   329,   329,   330,   330,
     331,   331,   332,   332,   333,   333,   334,   334,   335,   335,
     343,   344,   345,   346,   347,   348,   349,   352,   357,   357,
     368,   371,   372,   375,   380,   386,   391,   391,   398,   399,
     402,   406,   410,   416,   416,   423,   424,   427,   431,   435,
     445,   454,   454,   469,   469,   483,   486,   492,   492,   501,
     502,   503,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   581,   581,   590,   596,   602,   608,   614,   620,   626,
     632,   638,   644,   650,   656,   662,   668,   674,   680,   686,
     692,   692,   701,   704,   707,   710,   713,   719,   719,   728,
     728,   737,   746,   756,   756,   765,   768,   771,   774,   779,
     785,   785,   794,   794,   803,   809,   815,   821,   821,   830,
     836,   836,   845,   845,   854,   860,   866,   872,   872,   884,
     884,   893,   894,   895,   900,   901,   902,   903,   904,   905,
     906,   907,   910,   910,   921,   927,   933,   939,   945,   945,
     958,   958,   971,   971,   982,   983,   986,   987,   988,   993,
     993,  1003,  1004,  1005,  1010,  1011,  1012,  1013,  1014,  1015,
    1016,  1017,  1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,
    1026,  1027,  1028,  1029,  1030,  1031,  1034,  1034,  1042,  1043,
    1044,  1047,  1047,  1056,  1056,  1065,  1065,  1074,  1080,  1080,
    1089,  1095,  1101,  1107,  1113,  1119,  1125,  1132,  1138,  1138,
    1146,  1147,  1148,  1151,  1157,  1163,  1163,  1172,  1172,  1181,
    1181,  1190,  1190,  1199,  1199,  1210,  1211,  1212,  1217,  1218,
    1221,  1221,  1240,  1240,  1258,  1258,  1269,  1270,  1271,  1276,
    1277,  1280,  1285,  1290,  1290,  1301,  1302,  1303,  1308,  1309,
    1310,  1313,  1318,  1325,  1325,  1338,  1338,  1351,  1352,  1353,
    1358,  1359,  1360,  1361,  1362,  1363,  1366,  1372,  1378,  1384,
    1384,  1395,  1396,  1399,  1400,  1401,  1406,  1406,  1416,  1416,
    1426,  1427,  1428,  1431,  1434,  1435,  1438,  1438,  1447,  1447,
    1456,  1456,  1468,  1469,  1470,  1475,  1476,  1477,  1478,  1479,
    1480,  1483,  1489,  1495,  1501,  1507,  1513,  1522,  1522,  1536,
    1537,  1540,  1541,  1542,  1551,  1551,  1577,  1577,  1588,  1589,
    1590,  1596,  1597,  1598,  1599,  1600,  1601,  1602,  1603,  1604,
    1605,  1606,  1607,  1608,  1609,  1610,  1611,  1612,  1613,  1614,
    1615,  1616,  1617,  1618,  1619,  1620,  1621,  1622,  1623,  1624,
    1625,  1626,  1627,  1628,  1629,  1630,  1631,  1632,  1633,  1634,
    1635,  1636,  1637,  1638,  1639,  1640,  1641,  1642,  1645,  1645,
    1654,  1654,  1663,  1663,  1672,  1672,  1681,  1681,  1692,  1698,
    1704,  1710,  1710,  1718,  1719,  1720,  1721,  1724,  1730,  1738,
    1738,  1750,  1751,  1755,  1756,  1757,  1762,  1762,  1770,  1771,
    1772,  1777,  1778,  1779,  1780,  1781,  1782,  1783,  1784,  1785,
    1786,  1787,  1788,  1789,  1790,  1791,  1792,  1793,  1794,  1795,
    1796,  1797,  1798,  1799,  1800,  1801,  1802,  1803,  1804,  1805,
    1806,  1807,  1808,  1809,  1810,  1811,  1812,  1813,  1814,  1815,
    1816,  1817,  1818,  1819,  1820,  1827,  1827,  1841,  1841,  1850,
    1851,  1854,  1855,  1856,  1863,  1863,  1878,  1878,  1892,  1893,
    1896,  1897,  1898,  1903,  1904,  1905,  1906,  1907,  1908,  1909,
    1910,  1911,  1912,  1915,  1917,  1923,  1925,  1925,  1934,  1934,
    1943,  1943,  1952,  1954,  1954,  1963,  1973,  1973,  1986,  1987,
    1992,  1993,  1994,  2001,  2001,  2013,  2013,  2025,  2026,  2031,
    2032,  2033,  2040,  2041,  2042,  2043,  2044,  2045,  2046,  2047,
    2048,  2049,  2052,  2054,  2054,  2063,  2065,  2067,  2073,  2079,
    2088,  2088,  2101,  2102,  2105,  2106,  2107,  2112,  2112,  2122,
    2122,  2132,  2133,  2134,  2139,  2140,  2141,  2142,  2143,  2144,
    2145,  2148,  2148,  2157,  2157,  2182,  2182,  2212,  2212,  2225,
    2226,  2229,  2230,  2231,  2236,  2236,  2248,  2248,  2260,  2261,
    2262,  2267,  2268,  2269,  2270,  2271,  2272,  2273,  2274,  2275,
    2276,  2277,  2280,  2280,  2289,  2295,  2295,  2304,  2310,  2319,
    2319,  2330,  2331,  2334,  2335,  2336,  2341,  2341,  2350,  2350,
    2359,  2360,  2363,  2364,  2365,  2371,  2372,  2373,  2374,  2375,
    2376,  2377,  2378,  2379,  2380,  2381,  2384,  2384,  2395,  2395,
    2406,  2406,  2415,  2415,  2424,  2424,  2433,  2433,  2442,  2442,
    2456,  2456,  2467,  2468,  2471,  2471,  2483,  2483,  2494,  2495,
    2496,  2501,  2501,  2511,  2512,  2515,  2516,  2517,  2522,  2523,
    2524,  2525,  2526,  2527,  2528,  2529,  2530,  2531,  2532,  2533,
    2534,  2535,  2538,  2540,  2540,  2549,  2549,  2558,  2567,  2567,
    2580,  2581,  2582,  2587,  2588,  2589,  2590,  2591,  2592,  2593,
    2594,  2595,  2598,  2598,  2606,  2607,  2608,  2611,  2617,  2617,
    2626,  2632,  2640,  2648,  2648,  2659,  2660,  2661,  2666,  2667,
    2668,  2669,  2670,  2673,  2673,  2682,  2682,  2694,  2694,  2707,
    2708,  2709,  2714,  2715,  2716,  2717,  2718,  2719,  2722,  2728,
    2728,  2737,  2743,  2743,  2753,  2753,  2766,  2766,  2776,  2777,
    2778,  2783,  2784,  2785,  2786,  2787,  2788,  2789,  2790,  2791,
    2792,  2793,  2794,  2795,  2796,  2797,  2798,  2799,  2800,  2803,
    2810,  2810,  2819,  2819,  2828,  2834,  2834,  2843,  2849,  2855,
    2855,  2864,  2865,  2868,  2868,  2878,  2885,  2892,  2892,  2901,
    2901,  2911,  2911,  2921,  2921,  2933,  2933,  2945,  2945,  2955,
    2956,  2957,  2963,  2964,  2967,  2967,  2978,  2986,  2986,  2999,
    3000,  3001,  3007,  3007,  3015,  3016,  3017,  3022,  3023,  3024,
    3025,  3026,  3027,  3028,  3031,  3037,  3037,  3046,  3046,  3057,
    3058,  3059,  3064,  3064,  3072,  3073,  3074,  3079,  3080,  3081,
    3082,  3083,  3086,  3086,  3095,  3101,  3107,  3113,  3113,  3122,
    3122,  3133,  3134,  3135,  3140,  3141,  3144
  };

  void
  Dhcp6Parser::yy_stack_print_ () const
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
  Dhcp6Parser::yy_reduce_print_ (int yyrule) const
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
#endif // PARSER6_DEBUG


#line 14 "dhcp6_parser.yy"
} } // isc::dhcp
#line 6610 "dhcp6_parser.cc"

#line 3150 "dhcp6_parser.yy"


void
isc::dhcp::Dhcp6Parser::error(const location_type& loc,
                              const std::string& what)
{
    ctx.error(loc, what);
}
