// Generated by Bisonc++ V6.02.04 on Wed, 21 Jul 2021 15:15:04 +0700

// hdr/includes
#ifndef ParserBase_h_included
#define ParserBase_h_included

#include <exception>
#include <vector>
#include <iostream>
// $insert polyincludes
#include <memory>
// $insert preincludes

// hdr/baseclass

namespace // anonymous
{
    struct PI_;
}


// $insert polymorphic
enum class Tag_
{
    UCHAR,
    INT,
    STRING,
};

namespace Meta_
{

extern size_t const *t_nErrors;

extern size_t const *s_nErrors_;

template <Tag_ tag>
struct TypeOf;

template <typename Tp_>
struct TagOf;

// $insert polymorphicSpecializations
enum { sizeofTag_ = 3 };

extern char const *idOfTag_[];
template <>
struct TagOf<unsigned char>
{
    static Tag_ const tag = Tag_::UCHAR;
};

template <>
struct TagOf<int>
{
    static Tag_ const tag = Tag_::INT;
};

template <>
struct TagOf<std::string>
{
    static Tag_ const tag = Tag_::STRING;
};

template <>
struct TypeOf<Tag_::UCHAR>
{
    typedef unsigned char type;
};

template <>
struct TypeOf<Tag_::INT>
{
    typedef int type;
};

template <>
struct TypeOf<Tag_::STRING>
{
    typedef std::string type;
};


    // Individual semantic value classes are derived from Base, offering a
    // member returning the value's Tag_, a member cloning the object of its
    // derived Semantic<Tag_> and a member returning a pointerr to its
    // derived Semantic<Tag_> data. See also Bisonc++'s distribution file
    // README.polymorphic-techical
class Base
{
    protected:
        Tag_ d_baseTag;        // d_baseTag is assigned by Semantic.

    public:
        Base() = default;
        Base(Base const &other) = delete;

        virtual ~Base();

        Tag_ tag() const;
        Base *clone() const;
        void *data() const;        

    private:
        virtual Base *vClone() const = 0;
        virtual void *vData() const = 0;
};

inline Base *Base::clone() const
{
    return vClone();
}

inline void *Base::data() const
{
    return vData();
}

inline Tag_ Base::tag() const
{
    return d_baseTag;
}

    // The class Semantic stores a semantic value of the type matching tg_
template <Tag_ tg_>
class Semantic: public Base
{
    typename TypeOf<tg_>::type d_data;
    
    public:
        Semantic();
        Semantic(Semantic<tg_> const &other);   // req'd for cloning

            // This constructor member template forwards its arguments to
            // d_data, allowing it to be initialized using whatever
            // constructor is available for DataType
        template <typename ...Params>
        Semantic(Params &&...params);

    private:
        Base *vClone() const override;
        void *vData() const override;
};

template <Tag_ tg_>
Semantic<tg_>::Semantic()
{
    d_baseTag = tg_;                // Base's data member:
}

template <Tag_ tg_>
Semantic<tg_>::Semantic(Semantic<tg_> const &other)
:
    d_data(other.d_data)
{
    d_baseTag = other.d_baseTag;
}

template <Tag_ tg_>
template <typename ...Params>
Semantic<tg_>::Semantic(Params &&...params)
:
    d_data(std::forward<Params>(params) ...)
{
    d_baseTag = tg_;
}


template <Tag_ tg_>
Base *Semantic<tg_>::vClone() const
{
    return new Semantic<tg_>{*this};
}

template <Tag_ tg_>
void *Semantic<tg_>::vData() const 
{
    return const_cast<typename TypeOf<tg_>::type *>(&d_data);
}


    // The class SType wraps a pointer to Base.  It becomes the polymorphic
    // STYPE_ type. It also defines get members, allowing constructions like
    // $$.get<INT> to be used.  
class SType: private std::unique_ptr<Base>
{
    typedef std::unique_ptr<Base> BasePtr;

    public:
        SType() = default;
        SType(SType const &other);
        SType(SType &&tmp);

        ~SType() = default;

            // Specific overloads are needed for SType = SType assignments
        SType &operator=(SType const &rhs);
        SType &operator=(SType &rhs);           // required so it is used
                                                // instead of the template op=
        SType &operator=(SType &&tmp);

            // A template member operator= can be used when the compiler is
            // able to deduce the appropriate typename. Otherwise use assign.
        template <typename Type>
        SType &operator=(Type const &value);

        template <typename Type>                // same, now moving
        SType &operator=(Type &&tmp);

        template <Tag_ tagParam, typename ...Args>
        void assign(Args &&...args);
    
            // By default the get()-members check whether the specified <tag>
            // matches the tag returned by SType::tag (d_data's tag). If they
            // don't match a run-time fatal error results.
        template <Tag_ tag>
        typename TypeOf<tag>::type &get();

        template <Tag_ tag>
        typename TypeOf<tag>::type const &get() const;

        Tag_ tag() const;
        bool valid() const;
};

inline SType::SType(SType const &other)
:
    BasePtr{other ? other->clone() : 0}
{}

inline SType::SType(SType &&tmp)
:
    BasePtr{std::move(tmp)}
{}

inline SType &SType::operator=(SType const &rhs)
{
    reset(rhs->clone());
    return *this;
}

inline SType &SType::operator=(SType &rhs)
{
    reset(rhs->clone());
    return *this;
}

inline SType &SType::operator=(SType &&tmp)
{
    BasePtr::operator=(std::move(tmp));
    return *this;
}

    // A template assignment function can be used when the compiler is 
    // able to deduce the appropriate typename
template <typename Type>
inline SType &SType::operator=(Type const &value)
{
    assign< TagOf<Type>::tag >(value);
    return *this;
}

template <typename Type>
inline SType &SType::operator=(Type &&tmp)
{
    assign< 
        TagOf<
            typename std::remove_reference<Type>::type
        >::tag 
    >(std::move(tmp));

    return *this;
}

template <Tag_ tagParam, typename ...Args>
void SType::assign(Args &&...args)
{
    reset(new Semantic<tagParam>(std::forward<Args>(args) ...));
}

template <Tag_ tg>
typename TypeOf<tg>::type &SType::get()
{
// $insert warnTagMismatches

    if (tag() != tg)
    {
        if (*t_nErrors != 0)
            const_cast<SType *>(this)->assign<tg>();
        else
        {
            std::cerr << "[Fatal] calling `.get<Tag_::" << 
                idOfTag_[static_cast<int>(tg)] << 
                ">()', but Tag " <<
                idOfTag_[static_cast<int>(tag())] << " is encountered. Try "
                "option --debug and call setDebug(Parser::ACTIONCASES)\n";
            throw 1;        // ABORTs
        }
    }

    return *static_cast<typename TypeOf<tg>::type *>( (*this)->data() );
}

template <Tag_ tg>
typename TypeOf<tg>::type const &SType::get() const
{
// $insert warnTagMismatches

    if (tag() != tg)
    {
        if (*t_nErrors != 0)
            const_cast<SType *>(this)->assign<tg>();
        else
        {
            std::cerr << "[Fatal] calling `.get<Tag_::" << 
                idOfTag_[static_cast<int>(tg)] << 
                ">()', but Tag " <<
                idOfTag_[static_cast<int>(tag())] << " is encountered. Try "
                "option --debug and call setDebug(Parser::ACTIONCASES)\n";
            throw 1;        // ABORTs
        }
    }

    return *static_cast<typename TypeOf<tg>::type *>( (*this)->data() );
}

inline Tag_ SType::tag() const
{
    return valid() ? (*this)->tag() : static_cast<Tag_>(sizeofTag_);
}

inline bool SType::valid() const
{
    return BasePtr::get() != 0;
}

}  // namespace Meta_

class ParserBase
{
    public:
        enum DebugMode_
        {
            OFF           = 0,
            ON            = 1 << 0,
            ACTIONCASES   = 1 << 1
        };

// $insert tokens

    // Symbolic tokens:
    enum Tokens_
    {
        DEF = 257,
        COMMA,
        DB,
        WORD,
        REG,
        REG_LINK,
        REG_LINK_LINK,
        NEW_LINE,
        START,
        VALUE,
        NUMBER_HEX,
        NUMBER_DEC,
        NUMBER_BIN,
        NUMBER_CHAR,
        IDENTIFIER,
        COMMAND_1,
        COMMAND_2,
        COMMAND_3,
        LABEL,
    };

// $insert STYPE
    typedef Meta_::SType STYPE_;


    private:
                        // state  semval
        typedef std::pair<size_t, STYPE_> StatePair;
                       // token   semval
        typedef std::pair<int,    STYPE_> TokenPair;

        int d_stackIdx = -1;
        std::vector<StatePair> d_stateStack;
        StatePair  *d_vsp = 0;       // points to the topmost value stack
        size_t      d_state = 0;

        TokenPair   d_next;
        int         d_token;

        bool        d_terminalToken = false;
        bool        d_recovery = false;


    protected:
        enum Return_
        {
            PARSE_ACCEPT_ = 0,   // values used as parse()'s return values
            PARSE_ABORT_  = 1
        };
        enum ErrorRecovery_
        {
            UNEXPECTED_TOKEN_,
        };

        bool        d_actionCases_ = false;    // set by options/directives
        bool        d_debug_ = true;
        size_t      d_requiredTokens_;
        size_t      d_nErrors_;                // initialized by clearin()
        size_t      d_acceptedTokens_;
        STYPE_     d_val_;


        ParserBase();

        void ABORT() const;
        void ACCEPT() const;
        void ERROR() const;

        STYPE_ &vs_(int idx);             // value stack element idx 
        int  lookup_() const;
        int  savedToken_() const;
        int  token_() const;
        size_t stackSize_() const;
        size_t state_() const;
        size_t top_() const;
        void clearin_();
        void errorVerbose_();
        void lex_(int token);
        void popToken_();
        void pop_(size_t count = 1);
        void pushToken_(int token);
        void push_(size_t nextState);
        void redoToken_();
        bool recovery_() const;
        void reduce_(int rule);
        void shift_(int state);
        void startRecovery_();

    public:
        void setDebug(bool mode);
        void setDebug(DebugMode_ mode);
}; 

// hdr/abort
inline void ParserBase::ABORT() const
{
    throw PARSE_ABORT_;
}

// hdr/accept
inline void ParserBase::ACCEPT() const
{
    throw PARSE_ACCEPT_;
}


// hdr/error
inline void ParserBase::ERROR() const
{
    throw UNEXPECTED_TOKEN_;
}

// hdr/savedtoken
inline int ParserBase::savedToken_() const
{
    return d_next.first;
}

// hdr/opbitand
inline ParserBase::DebugMode_ operator&(ParserBase::DebugMode_ lhs,
                                     ParserBase::DebugMode_ rhs)
{
    return static_cast<ParserBase::DebugMode_>(
            static_cast<int>(lhs) & rhs);
}

// hdr/opbitor
inline ParserBase::DebugMode_ operator|(ParserBase::DebugMode_ lhs, 
                                     ParserBase::DebugMode_ rhs)
{
    return static_cast<ParserBase::DebugMode_>(static_cast<int>(lhs) | rhs);
};

// hdr/recovery
inline bool ParserBase::recovery_() const
{
    return d_recovery;
}

// hdr/stacksize
inline size_t ParserBase::stackSize_() const
{
    return d_stackIdx + 1;
}

// hdr/state
inline size_t ParserBase::state_() const
{
    return d_state;
}

// hdr/token
inline int ParserBase::token_() const
{
    return d_token;
}

// hdr/vs
inline ParserBase::STYPE_ &ParserBase::vs_(int idx) 
{
    return (d_vsp + idx)->second;
}

// hdr/tail
// For convenience, when including ParserBase.h its symbols are available as
// symbols in the class Parser, too.
#define Parser ParserBase


#endif



