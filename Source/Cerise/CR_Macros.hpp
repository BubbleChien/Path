
#ifndef CR_MACROS_HPP
#define CR_MACROS_HPP



#define CR_PRIVATE private:
#define CR_PROTECTED protected:
#define CR_PUBLIC public:



#define CR_IOPTR(a) reinterpret_cast<char*>(a)



#define CR_ENUM(a) static_cast<uint32_t>(a)



#define CR_TEXT_FLAGS (C2D_AtBaseline | C2D_WithColor)



#define CR_STR(a) std::to_string(a).c_str()



#define CR_EVT(a) CR::Hash::String(a)



#define CR_ARGS(a, b) struct { b } a;



#endif
