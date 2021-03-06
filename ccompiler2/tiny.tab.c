/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 9 "tiny.y"

#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define YYSTYPE TreeNode *
static int savedDec;
static char * savedName; /* for use in assignments */
static StmtType savedStmtType;
static ExpType savedType;
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */
static int yylex(void);
int yyerror(char *s);


#line 91 "tiny.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "tiny.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_ASSIGN = 5,                     /* ASSIGN  */
  YYSYMBOL_RETURN = 6,                     /* RETURN  */
  YYSYMBOL_WHILE = 7,                      /* WHILE  */
  YYSYMBOL_INT = 8,                        /* INT  */
  YYSYMBOL_VOID = 9,                       /* VOID  */
  YYSYMBOL_EQ = 10,                        /* EQ  */
  YYSYMBOL_LT = 11,                        /* LT  */
  YYSYMBOL_PLUS = 12,                      /* PLUS  */
  YYSYMBOL_LTE = 13,                       /* LTE  */
  YYSYMBOL_GT = 14,                        /* GT  */
  YYSYMBOL_GTE = 15,                       /* GTE  */
  YYSYMBOL_DIFF = 16,                      /* DIFF  */
  YYSYMBOL_MINUS = 17,                     /* MINUS  */
  YYSYMBOL_TIMES = 18,                     /* TIMES  */
  YYSYMBOL_OVER = 19,                      /* OVER  */
  YYSYMBOL_ID = 20,                        /* ID  */
  YYSYMBOL_NUM = 21,                       /* NUM  */
  YYSYMBOL_LPAREN = 22,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 23,                    /* RPAREN  */
  YYSYMBOL_LBRACES = 24,                   /* LBRACES  */
  YYSYMBOL_RBRACES = 25,                   /* RBRACES  */
  YYSYMBOL_LBRACK = 26,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 27,                    /* RBRACK  */
  YYSYMBOL_COMMA = 28,                     /* COMMA  */
  YYSYMBOL_SEMI = 29,                      /* SEMI  */
  YYSYMBOL_ERROR = 30,                     /* ERROR  */
  YYSYMBOL_YYACCEPT = 31,                  /* $accept  */
  YYSYMBOL_programa = 32,                  /* programa  */
  YYSYMBOL_declaracao_lista = 33,          /* declaracao_lista  */
  YYSYMBOL_declaracao = 34,                /* declaracao  */
  YYSYMBOL_id = 35,                        /* id  */
  YYSYMBOL_num = 36,                       /* num  */
  YYSYMBOL_tipo_especificador = 37,        /* tipo_especificador  */
  YYSYMBOL_var_declaracao = 38,            /* var_declaracao  */
  YYSYMBOL_39_1 = 39,                      /* @1  */
  YYSYMBOL_40_2 = 40,                      /* @2  */
  YYSYMBOL_41_3 = 41,                      /* @3  */
  YYSYMBOL_42_4 = 42,                      /* @4  */
  YYSYMBOL_43_5 = 43,                      /* @5  */
  YYSYMBOL_fun_declaracao = 44,            /* fun_declaracao  */
  YYSYMBOL_45_6 = 45,                      /* @6  */
  YYSYMBOL_params = 46,                    /* params  */
  YYSYMBOL_param_lista = 47,               /* param_lista  */
  YYSYMBOL_param = 48,                     /* param  */
  YYSYMBOL_49_7 = 49,                      /* @7  */
  YYSYMBOL_composto_decl = 50,             /* composto_decl  */
  YYSYMBOL_local_declaracoes = 51,         /* local_declaracoes  */
  YYSYMBOL_statement_lista = 52,           /* statement_lista  */
  YYSYMBOL_statement = 53,                 /* statement  */
  YYSYMBOL_expressao_decl = 54,            /* expressao_decl  */
  YYSYMBOL_selecao_decl = 55,              /* selecao_decl  */
  YYSYMBOL_iteracao_decl = 56,             /* iteracao_decl  */
  YYSYMBOL_retorno_decl = 57,              /* retorno_decl  */
  YYSYMBOL_expressao = 58,                 /* expressao  */
  YYSYMBOL_var = 59,                       /* var  */
  YYSYMBOL_60_8 = 60,                      /* @8  */
  YYSYMBOL_61_9 = 61,                      /* @9  */
  YYSYMBOL_62_10 = 62,                     /* @10  */
  YYSYMBOL_simples_expressao = 63,         /* simples_expressao  */
  YYSYMBOL_soma_expressao = 64,            /* soma_expressao  */
  YYSYMBOL_termo = 65,                     /* termo  */
  YYSYMBOL_fator = 66,                     /* fator  */
  YYSYMBOL_ativacao = 67,                  /* ativacao  */
  YYSYMBOL_68_11 = 68,                     /* @11  */
  YYSYMBOL_args = 69,                      /* args  */
  YYSYMBOL_args_lista = 70                 /* args_lista  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   133

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  121

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    39,    39,    44,    54,    59,    61,    63,    67,    74,
      82,    87,    97,    96,   106,   115,   121,   128,   105,   138,
     137,   156,   158,   163,   173,   178,   188,   187,   200,   213,
     223,   227,   237,   241,   243,   245,   247,   249,   254,   256,
     262,   269,   280,   290,   294,   302,   310,   315,   322,   328,
     334,   321,   347,   355,   363,   371,   379,   387,   395,   400,
     408,   416,   421,   428,   435,   440,   442,   444,   446,   452,
     458,   457,   471,   473,   477,   487
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "ASSIGN",
  "RETURN", "WHILE", "INT", "VOID", "EQ", "LT", "PLUS", "LTE", "GT", "GTE",
  "DIFF", "MINUS", "TIMES", "OVER", "ID", "NUM", "LPAREN", "RPAREN",
  "LBRACES", "RBRACES", "LBRACK", "RBRACK", "COMMA", "SEMI", "ERROR",
  "$accept", "programa", "declaracao_lista", "declaracao", "id", "num",
  "tipo_especificador", "var_declaracao", "@1", "@2", "@3", "@4", "@5",
  "fun_declaracao", "@6", "params", "param_lista", "param", "@7",
  "composto_decl", "local_declaracoes", "statement_lista", "statement",
  "expressao_decl", "selecao_decl", "iteracao_decl", "retorno_decl",
  "expressao", "var", "@8", "@9", "@10", "simples_expressao",
  "soma_expressao", "termo", "fator", "ativacao", "@11", "args",
  "args_lista", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285
};
#endif

#define YYPACT_NINF (-102)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-74)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      23,  -102,  -102,  -102,     7,     9,  -102,    -7,  -102,  -102,
    -102,  -102,  -102,    25,   -10,    -5,    16,  -102,  -102,    55,
      27,    74,    -7,    83,    22,  -102,  -102,  -102,    20,    85,
      64,    80,    82,  -102,  -102,  -102,  -102,    86,    64,    81,
    -102,    -7,  -102,     5,  -102,    88,  -102,    89,    32,    90,
      54,  -102,  -102,    40,  -102,  -102,  -102,  -102,  -102,  -102,
    -102,    87,   110,  -102,    77,    84,  -102,  -102,    54,  -102,
      91,    54,    94,    92,    97,  -102,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    98,  -102,    99,
    -102,  -102,    48,  -102,  -102,    24,    24,    84,    24,    24,
      24,    24,    84,  -102,  -102,    36,    36,    54,  -102,   100,
      96,   121,  -102,  -102,  -102,    54,    36,   101,  -102,  -102,
    -102
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     7,    10,    11,     0,     0,     4,     0,     5,     6,
       1,     3,     8,    12,     0,     0,     0,    13,    15,     0,
       0,    11,     0,     0,    21,    24,     9,    16,    25,     0,
       0,     0,     0,    30,    20,    23,    17,     0,    32,     0,
      27,     0,    29,     0,    18,    12,    69,     0,     0,     0,
       0,    28,    39,    47,    68,    34,    31,    33,    35,    36,
      37,     0,    66,    46,    58,    61,    64,    67,     0,    43,
       0,     0,     0,     0,     0,    38,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    44,     0,
      65,    49,     0,    45,    66,    56,    52,    59,    53,    54,
      55,    57,    60,    62,    63,     0,     0,     0,    75,     0,
      72,    40,    42,    50,    71,     0,     0,     0,    74,    41,
      51
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -102,  -102,  -102,   122,    -6,   106,   -16,    93,  -102,  -102,
    -102,  -102,  -102,  -102,  -102,  -102,  -102,   102,  -102,   104,
    -102,  -102,  -101,  -102,  -102,  -102,  -102,   -48,     0,  -102,
    -102,  -102,  -102,    18,   -39,    19,  -102,  -102,  -102,  -102
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,    53,    54,     7,     8,    14,    15,
      20,    31,    39,     9,    16,    23,    24,    25,    32,    55,
      38,    43,    56,    57,    58,    59,    60,    61,    62,    73,
     107,   117,    63,    64,    65,    66,    67,    74,   109,   110
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      70,    13,    72,    22,   111,   112,    46,    10,    47,    -2,
       1,    48,    49,    12,    22,   119,    28,     2,     3,    17,
      87,    18,    41,    89,     1,    12,    26,    50,    93,    33,
      51,     2,     3,    46,    52,    45,    79,    46,    19,    47,
      97,    84,    48,    49,   108,   102,   -26,   -19,    26,    46,
      30,   -14,    12,    26,    50,    46,    12,    26,    50,   113,
      33,    69,   -70,     2,    21,    52,   -48,   118,    12,    26,
      50,   -73,     2,     3,    12,    26,    50,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    77,    78,    79,
      80,    81,    82,    83,    84,    95,    96,   -22,    98,    99,
     100,   101,    85,    86,   103,   104,    29,    36,    37,    33,
      44,    68,    71,    40,   -14,    76,    75,    90,    91,    92,
      88,   105,   106,   114,   115,   116,    27,    11,   120,     0,
       0,    42,    35,    34
};

static const yytype_int8 yycheck[] =
{
      48,     7,    50,    19,   105,   106,     1,     0,     3,     0,
       1,     6,     7,    20,    30,   116,    22,     8,     9,    29,
      68,    26,    38,    71,     1,    20,    21,    22,    76,    24,
      25,     8,     9,     1,    29,    41,    12,     1,    22,     3,
      79,    17,     6,     7,    92,    84,    26,    22,    21,     1,
      28,    26,    20,    21,    22,     1,    20,    21,    22,   107,
      24,    29,    22,     8,     9,    29,    26,   115,    20,    21,
      22,    23,     8,     9,    20,    21,    22,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    10,    11,    12,
      13,    14,    15,    16,    17,    77,    78,    23,    80,    81,
      82,    83,    18,    19,    85,    86,    23,    27,    26,    24,
      29,    22,    22,    27,    26,     5,    29,    23,    26,    22,
      29,    23,    23,    23,    28,     4,    20,     5,    27,    -1,
      -1,    38,    30,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     8,     9,    32,    33,    34,    37,    38,    44,
       0,    34,    20,    35,    39,    40,    45,    29,    26,    22,
      41,     9,    37,    46,    47,    48,    21,    36,    35,    23,
      28,    42,    49,    24,    50,    48,    27,    26,    51,    43,
      27,    37,    38,    52,    29,    35,     1,     3,     6,     7,
      22,    25,    29,    35,    36,    50,    53,    54,    55,    56,
      57,    58,    59,    63,    64,    65,    66,    67,    22,    29,
      58,    22,    58,    60,    68,    29,     5,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    58,    29,    58,
      23,    26,    22,    58,    59,    64,    64,    65,    64,    64,
      64,    64,    65,    66,    66,    23,    23,    61,    58,    69,
      70,    53,    53,    58,    23,    28,     4,    62,    58,    53,
      27
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    32,    33,    33,    34,    34,    34,    35,    36,
      37,    37,    39,    38,    40,    41,    42,    43,    38,    45,
      44,    46,    46,    47,    47,    48,    49,    48,    50,    51,
      51,    52,    52,    53,    53,    53,    53,    53,    54,    54,
      55,    55,    56,    57,    57,    58,    58,    59,    60,    61,
      62,    59,    63,    63,    63,    63,    63,    63,    63,    64,
      64,    64,    65,    65,    65,    66,    66,    66,    66,    66,
      68,    67,    69,    69,    70,    70
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     4,     0,     0,     0,     0,    10,     0,
       7,     1,     1,     3,     1,     2,     0,     5,     4,     2,
       0,     2,     0,     1,     1,     1,     1,     1,     2,     1,
       5,     7,     5,     2,     3,     3,     1,     1,     0,     0,
       0,     7,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     1,     1,     1,     1,
       0,     5,     1,     0,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* programa: declaracao_lista  */
#line 40 "tiny.y"
                        { savedTree = yyvsp[0]; }
#line 1246 "tiny.tab.c"
    break;

  case 3: /* declaracao_lista: declaracao_lista declaracao  */
#line 45 "tiny.y"
                        { 
                          YYSTYPE t = yyvsp[-1];
                          if (t != NULL) { 
                            while (t->sibling != NULL)
                                t = t->sibling;
                            t->sibling = yyvsp[0];
                            yyval = yyvsp[-1];
                          } else yyval = yyvsp[0];
                        }
#line 1260 "tiny.tab.c"
    break;

  case 4: /* declaracao_lista: declaracao  */
#line 55 "tiny.y"
                        { yyval = yyvsp[0]; }
#line 1266 "tiny.tab.c"
    break;

  case 5: /* declaracao: var_declaracao  */
#line 60 "tiny.y"
                        { yyval = yyvsp[0]; }
#line 1272 "tiny.tab.c"
    break;

  case 6: /* declaracao: fun_declaracao  */
#line 62 "tiny.y"
                        { yyval = yyvsp[0]; }
#line 1278 "tiny.tab.c"
    break;

  case 7: /* declaracao: error  */
#line 64 "tiny.y"
                        { yyval = NULL; }
#line 1284 "tiny.tab.c"
    break;

  case 8: /* id: ID  */
#line 68 "tiny.y"
                        { 
                          savedName = copyString(tokenString);
                          savedLineNo = lineno; 
                        }
#line 1293 "tiny.tab.c"
    break;

  case 9: /* num: NUM  */
#line 75 "tiny.y"
                        {
                          savedDec = atoi(tokenString);
                          savedLineNo = lineno; 
                        }
#line 1302 "tiny.tab.c"
    break;

  case 10: /* tipo_especificador: INT  */
#line 83 "tiny.y"
                        { 
                          yyval = newStmtNode(IntK);
                          savedType = Integer;
                         }
#line 1311 "tiny.tab.c"
    break;

  case 11: /* tipo_especificador: VOID  */
#line 88 "tiny.y"
                        { 
                          yyval = newStmtNode(VoidK); 
                          savedType = Void;
                        }
#line 1320 "tiny.tab.c"
    break;

  case 12: /* @1: %empty  */
#line 97 "tiny.y"
                        { 
                          yyval = yyvsp[-1];
                          yyval->child[0] = newExpNode(IdK);
                          yyval->child[0]->attr.name = savedName;
                          yyval->child[0]->type = savedType;
                          yyval->child[0]->stmtType = Variable;
                          yyval->lineno = savedLineNo;
                        }
#line 1333 "tiny.tab.c"
    break;

  case 14: /* @2: %empty  */
#line 106 "tiny.y"
                        {
                          yyval = yyvsp[-1];
                          yyval->child[0] = newExpNode(IdK);
                          yyval->child[0]->attr.name = savedName;
                          yyval->child[0]->type = savedType;
                          yyval->child[0]->stmtType = Variable;
                          yyval->lineno = savedLineNo;
                        }
#line 1346 "tiny.tab.c"
    break;

  case 15: /* @3: %empty  */
#line 115 "tiny.y"
                        {
                          yyval = yyvsp[-3]->child[0];
                          yyval->child[0] = newExpNode(OpK);
                          yyval->child[0]->attr.op = LBRACK;
                        }
#line 1356 "tiny.tab.c"
    break;

  case 16: /* @4: %empty  */
#line 121 "tiny.y"
                        {
                          yyval = yyvsp[-5]->child[0];
                          yyval->child[1] = newExpNode(ConstK);
                          yyval->child[1]->attr.val = savedDec;
                          yyval->child[1]->type = Integer;
                        }
#line 1367 "tiny.tab.c"
    break;

  case 17: /* @5: %empty  */
#line 128 "tiny.y"
                        {
                          yyval = yyvsp[-7]->child[0];
                          yyval->child[0] = newExpNode(OpK);
                          yyval->child[0]->attr.op = RBRACK;
                        }
#line 1377 "tiny.tab.c"
    break;

  case 19: /* @6: %empty  */
#line 138 "tiny.y"
                        {
                          yyval = yyvsp[-1];
                          yyval->lineno = savedLineNo;
                          yyval->composto = 1;
                          yyval->child[0] = newExpNode(IdK);
                          yyval->child[0]->attr.name = savedName;
                          yyval->child[0]->type = savedType;
                          yyval->child[0]->stmtType = Function;
                        }
#line 1391 "tiny.tab.c"
    break;

  case 20: /* fun_declaracao: tipo_especificador id @6 LPAREN params RPAREN composto_decl  */
#line 148 "tiny.y"
                        {
                          yyval = yyvsp[-4];
                          yyval->child[0]->child[0] = yyvsp[-2];
                          yyval->child[0]->child[1] = yyvsp[0];
                        }
#line 1401 "tiny.tab.c"
    break;

  case 21: /* params: param_lista  */
#line 157 "tiny.y"
                        { yyval = yyvsp[0]; }
#line 1407 "tiny.tab.c"
    break;

  case 22: /* params: VOID  */
#line 159 "tiny.y"
                        { yyval = NULL; }
#line 1413 "tiny.tab.c"
    break;

  case 23: /* param_lista: param_lista COMMA param  */
#line 164 "tiny.y"
                        { 
                          YYSTYPE t = yyvsp[-2];
                          if (t != NULL){ 
                            while (t->sibling != NULL)
                                t = t->sibling;
                            t->sibling = yyvsp[0];
                            yyval = yyvsp[-2];
                          } else yyval = yyvsp[0];
                        }
#line 1427 "tiny.tab.c"
    break;

  case 24: /* param_lista: param  */
#line 174 "tiny.y"
                        { yyval = yyvsp[0]; }
#line 1433 "tiny.tab.c"
    break;

  case 25: /* param: tipo_especificador id  */
#line 179 "tiny.y"
                        {
                          yyval = yyvsp[-1];
                          yyval->lineno = savedLineNo;
                          yyval->child[0] = newExpNode(IdK);
                          yyval->child[0]->attr.name = savedName;
                          yyval->child[0]->type = savedType;
                          yyval->child[0]->stmtType = Variable;
                        }
#line 1446 "tiny.tab.c"
    break;

  case 26: /* @7: %empty  */
#line 188 "tiny.y"
                        {
                          yyval = yyvsp[-1];
                          yyval->lineno = savedLineNo;
                          yyval->child[0] = newExpNode(IdK);
                          yyval->child[0]->attr.name = savedName;
                          yyval->child[0]->type = savedType;
                          yyval->child[0]->stmtType = Variable;
                        }
#line 1459 "tiny.tab.c"
    break;

  case 28: /* composto_decl: LBRACES local_declaracoes statement_lista RBRACES  */
#line 201 "tiny.y"
                        {
                          YYSTYPE t = yyvsp[-2];
                          if (t != NULL){ 
                            while (t->sibling != NULL)
                                t = t->sibling;
                            t->sibling = yyvsp[-1];
                            yyval = yyvsp[-2];
                          } else yyval = yyvsp[-1];
                        }
#line 1473 "tiny.tab.c"
    break;

  case 29: /* local_declaracoes: local_declaracoes var_declaracao  */
#line 214 "tiny.y"
                        { 
                          YYSTYPE t = yyvsp[-1];
                          if (t != NULL){ 
                            while (t->sibling != NULL)
                                t = t->sibling;
                            t->sibling = yyvsp[0];
                            yyval = yyvsp[-1];
                          } else yyval = yyvsp[0];
                        }
#line 1487 "tiny.tab.c"
    break;

  case 30: /* local_declaracoes: %empty  */
#line 223 "tiny.y"
                      { yyval = NULL; }
#line 1493 "tiny.tab.c"
    break;

  case 31: /* statement_lista: statement_lista statement  */
#line 228 "tiny.y"
                        { 
                          YYSTYPE t = yyvsp[-1];
                          if (t != NULL) { 
                            while (t->sibling != NULL)
                                t = t->sibling;
                            t->sibling = yyvsp[0];
                            yyval = yyvsp[-1];
                          } else yyval = yyvsp[0];
                        }
#line 1507 "tiny.tab.c"
    break;

  case 32: /* statement_lista: %empty  */
#line 237 "tiny.y"
                      { yyval = NULL; }
#line 1513 "tiny.tab.c"
    break;

  case 33: /* statement: expressao_decl  */
#line 242 "tiny.y"
                        { yyval = yyvsp[0]; }
#line 1519 "tiny.tab.c"
    break;

  case 34: /* statement: composto_decl  */
#line 244 "tiny.y"
                        { yyval = yyvsp[0]; }
#line 1525 "tiny.tab.c"
    break;

  case 35: /* statement: selecao_decl  */
#line 246 "tiny.y"
                        { yyval = yyvsp[0]; }
#line 1531 "tiny.tab.c"
    break;

  case 36: /* statement: iteracao_decl  */
#line 248 "tiny.y"
                        { yyval = yyvsp[0]; }
#line 1537 "tiny.tab.c"
    break;

  case 37: /* statement: retorno_decl  */
#line 250 "tiny.y"
                        { yyval = yyvsp[0]; }
#line 1543 "tiny.tab.c"
    break;

  case 38: /* expressao_decl: expressao SEMI  */
#line 255 "tiny.y"
                        { yyval = yyvsp[-1]; }
#line 1549 "tiny.tab.c"
    break;

  case 39: /* expressao_decl: SEMI  */
#line 257 "tiny.y"
                        { yyval = NULL; }
#line 1555 "tiny.tab.c"
    break;

  case 40: /* selecao_decl: IF LPAREN expressao RPAREN statement  */
#line 263 "tiny.y"
                        { 
                          yyval = newStmtNode(IfK);
                          yyval->composto = 1;
                          yyval->child[0] = yyvsp[-2];
                          yyval->child[1] = yyvsp[0];
                        }
#line 1566 "tiny.tab.c"
    break;

  case 41: /* selecao_decl: IF LPAREN expressao RPAREN statement ELSE statement  */
#line 270 "tiny.y"
                        { 
                          yyval = newStmtNode(IfK);
                          yyval->composto = 1;
                          yyval->child[0] = yyvsp[-4];
                          yyval->child[1] = yyvsp[-2];
                          yyval->child[2] = yyvsp[0];
                        }
#line 1578 "tiny.tab.c"
    break;

  case 42: /* iteracao_decl: WHILE LPAREN expressao RPAREN statement  */
#line 281 "tiny.y"
                        {
                          yyval = newStmtNode(WhileK);
                          yyval->composto = 1;
                          yyval->child[0] = yyvsp[-2];
                          yyval->child[1] = yyvsp[0];
                        }
#line 1589 "tiny.tab.c"
    break;

  case 43: /* retorno_decl: RETURN SEMI  */
#line 291 "tiny.y"
                        {        
                          yyval = newStmtNode(ReturnK);
                        }
#line 1597 "tiny.tab.c"
    break;

  case 44: /* retorno_decl: RETURN expressao SEMI  */
#line 295 "tiny.y"
                        {
                          yyval = newStmtNode(ReturnK);
                          yyval->child[0] = yyvsp[-1];
                        }
#line 1606 "tiny.tab.c"
    break;

  case 45: /* expressao: var ASSIGN expressao  */
#line 303 "tiny.y"
                        {
                          yyval = newExpNode(OpK); 
                          yyval->attr.op = ASSIGN; 
                          yyval->child[0] = yyvsp[-2];
                          yyval->child[0]->type = savedType;
                          yyval->child[1] = yyvsp[0]; 
                        }
#line 1618 "tiny.tab.c"
    break;

  case 46: /* expressao: simples_expressao  */
#line 311 "tiny.y"
                        { yyval = yyvsp[0]; }
#line 1624 "tiny.tab.c"
    break;

  case 47: /* var: id  */
#line 316 "tiny.y"
                        { 
                          yyval = newExpNode(IdK);
                          yyval->lineno = savedLineNo;
                          yyval->attr.name = savedName;
                        }
#line 1634 "tiny.tab.c"
    break;

  case 48: /* @8: %empty  */
#line 322 "tiny.y"
                        {
                          yyval = newExpNode(IdK);
                          yyval->lineno = savedLineNo;
                          yyval->attr.name = savedName;
                        }
#line 1644 "tiny.tab.c"
    break;

  case 49: /* @9: %empty  */
#line 328 "tiny.y"
                        {
                          yyval = yyvsp[-1];
                          yyval->child[0] = newExpNode(OpK);
                          yyval->child[0]->attr.op = LBRACK;
                        }
#line 1654 "tiny.tab.c"
    break;

  case 50: /* @10: %empty  */
#line 334 "tiny.y"
                        {
                          yyval = yyvsp[-3];
                          yyval->child[1] = yyvsp[0];
                        }
#line 1663 "tiny.tab.c"
    break;

  case 51: /* var: id @8 LBRACK @9 expressao @10 RBRACK  */
#line 339 "tiny.y"
                        {
                          yyval = yyvsp[-5];
                          yyval->child[2] = newExpNode(OpK);
                          yyval->child[2]->attr.op = RBRACK;
                        }
#line 1673 "tiny.tab.c"
    break;

  case 52: /* simples_expressao: soma_expressao LT soma_expressao  */
#line 348 "tiny.y"
                        {
                          yyval = newExpNode(OpK);
                          yyval->attr.op = LT;
                          yyval->child[0] = yyvsp[-2];
                          yyval->child[1] = yyvsp[0];
                          
                        }
#line 1685 "tiny.tab.c"
    break;

  case 53: /* simples_expressao: soma_expressao LTE soma_expressao  */
#line 356 "tiny.y"
                        {
                          yyval = newExpNode(OpK);
                          yyval->attr.op = LTE;
                          yyval->child[0] = yyvsp[-2];
                          yyval->child[1] = yyvsp[0];
                          
                        }
#line 1697 "tiny.tab.c"
    break;

  case 54: /* simples_expressao: soma_expressao GT soma_expressao  */
#line 364 "tiny.y"
                        {
                          yyval = newExpNode(OpK);
                          yyval->attr.op = GT;
                          yyval->child[0] = yyvsp[-2];
                          yyval->child[1] = yyvsp[0];
                          
                        }
#line 1709 "tiny.tab.c"
    break;

  case 55: /* simples_expressao: soma_expressao GTE soma_expressao  */
#line 372 "tiny.y"
                        {
                          yyval = newExpNode(OpK);
                          yyval->attr.op = GTE;    
                          yyval->child[0] = yyvsp[-2];
                          yyval->child[1] = yyvsp[0];
                          
                        }
#line 1721 "tiny.tab.c"
    break;

  case 56: /* simples_expressao: soma_expressao EQ soma_expressao  */
#line 380 "tiny.y"
                        {
                          yyval = newExpNode(OpK);
                          yyval->attr.op = EQ;  
                          yyval->child[0] = yyvsp[-2];
                          yyval->child[1] = yyvsp[0];
                          
                        }
#line 1733 "tiny.tab.c"
    break;

  case 57: /* simples_expressao: soma_expressao DIFF soma_expressao  */
#line 388 "tiny.y"
                        {
                          yyval = newExpNode(OpK);
                          yyval->attr.op = DIFF;  
                          yyval->child[0] = yyvsp[-2];
                          yyval->child[1] = yyvsp[0];
                          
                        }
#line 1745 "tiny.tab.c"
    break;

  case 58: /* simples_expressao: soma_expressao  */
#line 396 "tiny.y"
                        { yyval = yyvsp[0]; }
#line 1751 "tiny.tab.c"
    break;

  case 59: /* soma_expressao: soma_expressao PLUS termo  */
#line 401 "tiny.y"
                        {
                          yyval = newExpNode(OpK);
                          yyval->attr.op = PLUS;  
                          yyval->child[0] = yyvsp[-2];
                          yyval->child[1] = yyvsp[0];
                          
                        }
#line 1763 "tiny.tab.c"
    break;

  case 60: /* soma_expressao: soma_expressao MINUS termo  */
#line 409 "tiny.y"
                        {
                          yyval = newExpNode(OpK);
                          yyval->attr.op = MINUS; 
                          yyval->child[0] = yyvsp[-2];
                          yyval->child[1] = yyvsp[0];
                          
                        }
#line 1775 "tiny.tab.c"
    break;

  case 61: /* soma_expressao: termo  */
#line 417 "tiny.y"
                        { yyval = yyvsp[0]; }
#line 1781 "tiny.tab.c"
    break;

  case 62: /* termo: termo TIMES fator  */
#line 422 "tiny.y"
                        {
                          yyval = newExpNode(OpK);
                          yyval->attr.op = TIMES; 
                          yyval->child[0] = yyvsp[-2];
                          yyval->child[1] = yyvsp[0];
                        }
#line 1792 "tiny.tab.c"
    break;

  case 63: /* termo: termo OVER fator  */
#line 429 "tiny.y"
                        {
                          yyval = newExpNode(OpK);
                          yyval->attr.op = OVER; 
                          yyval->child[0] = yyvsp[-2];
                          yyval->child[1] = yyvsp[0];
                        }
#line 1803 "tiny.tab.c"
    break;

  case 64: /* termo: fator  */
#line 436 "tiny.y"
                        { yyval = yyvsp[0]; }
#line 1809 "tiny.tab.c"
    break;

  case 65: /* fator: LPAREN expressao RPAREN  */
#line 441 "tiny.y"
                        { yyval = yyvsp[-1]; }
#line 1815 "tiny.tab.c"
    break;

  case 66: /* fator: var  */
#line 443 "tiny.y"
                        { yyval = yyvsp[0]; }
#line 1821 "tiny.tab.c"
    break;

  case 67: /* fator: ativacao  */
#line 445 "tiny.y"
                        { yyval = yyvsp[0]; }
#line 1827 "tiny.tab.c"
    break;

  case 68: /* fator: num  */
#line 447 "tiny.y"
                        {
                          yyval = newExpNode(ConstK);
                          yyval->type = Integer;
                          yyval->attr.val = savedDec;
                        }
#line 1837 "tiny.tab.c"
    break;

  case 69: /* fator: error  */
#line 453 "tiny.y"
                        { yyval = NULL; }
#line 1843 "tiny.tab.c"
    break;

  case 70: /* @11: %empty  */
#line 458 "tiny.y"
                        {
                          yyval = newExpNode(IdK);
                          yyval->attr.name = savedName;
                          yyval->lineno = savedLineNo;
                        }
#line 1853 "tiny.tab.c"
    break;

  case 71: /* ativacao: id @11 LPAREN args RPAREN  */
#line 464 "tiny.y"
                        {
                          yyval = yyvsp[-3];
                          yyval->child[0] = yyvsp[-1];
                        }
#line 1862 "tiny.tab.c"
    break;

  case 72: /* args: args_lista  */
#line 472 "tiny.y"
                        { yyval = yyvsp[0]; }
#line 1868 "tiny.tab.c"
    break;

  case 73: /* args: %empty  */
#line 473 "tiny.y"
                      { yyval = NULL; }
#line 1874 "tiny.tab.c"
    break;

  case 74: /* args_lista: args_lista COMMA expressao  */
#line 478 "tiny.y"
                        { 
                          YYSTYPE t = yyvsp[-2];
                          if (t != NULL) { 
                            while (t->sibling != NULL)
                                t = t->sibling;
                            t->sibling = yyvsp[0];
                            yyval = yyvsp[-2];
                          } else yyval = yyvsp[0];
                        }
#line 1888 "tiny.tab.c"
    break;

  case 75: /* args_lista: expressao  */
#line 488 "tiny.y"
                        { yyval = yyvsp[0]; }
#line 1894 "tiny.tab.c"
    break;


#line 1898 "tiny.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 492 "tiny.y"


int yyerror(char * message)
{ fprintf(listing,"Syntax error at line %d: %s\n",lineno,message);
  fprintf(listing,"Current token: ");
  printToken(yychar,tokenString);
  Error = TRUE;
  return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the TINY scanner
 */
static int yylex(void)
{ return getToken(); }

TreeNode * parse(void)
{ 
  yyparse();
  return savedTree;
}

