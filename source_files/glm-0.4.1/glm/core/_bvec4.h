//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2006-04-27
// Updated : 2006-04-27
// Licence : This source is under GNU LGPL licence
// File    : _bvec4.h
//////////////////////////////////////////////////////////////////////////////////

#ifndef __bvec4_h__
#define __bvec4_h__

namespace glm
{
    template <typename T> class _xvec2;
    template <typename T> class _xvec3;
    template <typename T> class _xvec4;
    class _bvec2;
    class _bvec3;

    //!< \brief Class for Vector of 4 booleans. (From GLSL 1.10.59 specification)
    class _bvec4
    {
    public:
        // Data
        union{bool x, r, s;};
        union{bool y, g, t;};
        union{bool z, b, p;};
        union{bool w, a, q;};

        // Common constructors
	    _bvec4();
        _bvec4(const _bvec4& v);

        // Bool constructors
        explicit _bvec4(const bool x);
        explicit _bvec4(const bool a, const bool b, const bool c, const bool d);
        explicit _bvec4(const bool a, const bool b, const bool c, const _bvec2& d);
        explicit _bvec4(const bool a, const bool b, const bool c, const _bvec3& d);
        explicit _bvec4(const bool a, const bool b, const bool c, const _bvec4& d);
        explicit _bvec4(const bool a, const bool b, const _bvec2& c);
        explicit _bvec4(const bool a, const bool b, const _bvec3& c);
        explicit _bvec4(const bool a, const bool b, const _bvec4& c);
        explicit _bvec4(const bool a, const _bvec2& b, const bool c);
        explicit _bvec4(const bool a, const _bvec2& b, const _bvec2& c);
        explicit _bvec4(const bool a, const _bvec2& b, const _bvec3& c);
        explicit _bvec4(const bool a, const _bvec2& b, const _bvec4& c);
        explicit _bvec4(const bool a, const _bvec3& b);
        explicit _bvec4(const bool a, const _bvec4& b);
        explicit _bvec4(const _bvec2& a, const bool b, const bool c);
        explicit _bvec4(const _bvec2& a, const bool b, const _bvec2& c);
        explicit _bvec4(const _bvec2& a, const bool b, const _bvec3& c);
        explicit _bvec4(const _bvec2& a, const bool b, const _bvec4& c);
        explicit _bvec4(const _bvec2& a, const _bvec2& b);
        explicit _bvec4(const _bvec2& a, const _bvec3& b);
        explicit _bvec4(const _bvec2& a, const _bvec4& b);
        explicit _bvec4(const _bvec3& a, const bool b);
        explicit _bvec4(const _bvec3& a, const _bvec2& b);
        explicit _bvec4(const _bvec3& a, const _bvec3& b);
        explicit _bvec4(const _bvec3& a, const _bvec4& b);

        // U constructors
        template <typename U> explicit _bvec4(const U x);
        template <typename U> explicit _bvec4(const U a, const U b, const U c, const U d);
        template <typename U> explicit _bvec4(const U a, const U b, const U c, const _xvec2<U>& d);
        template <typename U> explicit _bvec4(const U a, const U b, const U c, const _xvec3<U>& d);
        template <typename U> explicit _bvec4(const U a, const U b, const U c, const _xvec4<U>& d);
        template <typename U> explicit _bvec4(const U a, const U b, const _xvec2<U>& c);
        template <typename U> explicit _bvec4(const U a, const U b, const _xvec3<U>& c);
        template <typename U> explicit _bvec4(const U a, const U b, const _xvec4<U>& c);
        template <typename U> explicit _bvec4(const U a, const _xvec2<U>& b, const U c);
        template <typename U> explicit _bvec4(const U a, const _xvec2<U>& b, const _xvec2<U>& c);
        template <typename U> explicit _bvec4(const U a, const _xvec2<U>& b, const _xvec3<U>& c);
        template <typename U> explicit _bvec4(const U a, const _xvec2<U>& b, const _xvec4<U>& c);
        template <typename U> explicit _bvec4(const U a, const _xvec3<U>& b);
        template <typename U> explicit _bvec4(const U a, const _xvec4<U>& b);
        template <typename U> explicit _bvec4(const _xvec2<U>& a, const U b, const U c);
        template <typename U> explicit _bvec4(const _xvec2<U>& a, const U b, const _xvec2<U>& c);
        template <typename U> explicit _bvec4(const _xvec2<U>& a, const U b, const _xvec3<U>& c);
        template <typename U> explicit _bvec4(const _xvec2<U>& a, const U b, const _xvec4<U>& c);
        template <typename U> explicit _bvec4(const _xvec2<U>& a, const _xvec2<U>& b);
        template <typename U> explicit _bvec4(const _xvec2<U>& a, const _xvec3<U>& b);
        template <typename U> explicit _bvec4(const _xvec2<U>& a, const _xvec4<U>& b);
        template <typename U> explicit _bvec4(const _xvec3<U>& a, const U b);
        template <typename U> explicit _bvec4(const _xvec3<U>& a, const _xvec2<U>& b);
        template <typename U> explicit _bvec4(const _xvec3<U>& a, const _xvec3<U>& b);
        template <typename U> explicit _bvec4(const _xvec3<U>& a, const _xvec4<U>& b);
        template <typename U> explicit _bvec4(const _xvec4<U>& a);

        // Accesses
        bool& operator[](int i);
        bool operator[](int i) const;
        operator bool*();
	    operator const bool*() const;

        // Operators
        _bvec4& operator=(const _bvec4& x);
/*
	    _bvec4& operator++();
        _bvec4& operator--();
        const _bvec4 operator++(int n) const;
	    const _bvec4 operator--(int n) const;
*/
        _bvec4 operator!() const ;

        // 2 components swizzles operators
        _bvec2 _xx() const;
        _bvec2 _yx() const;
        _bvec2 _zx() const;
        _bvec2 _wx() const;
        _bvec2 _xy() const;
        _bvec2 _yy() const;
        _bvec2 _zy() const;
        _bvec2 _wy() const;
        _bvec2 _xz() const;
        _bvec2 _yz() const;
        _bvec2 _zz() const;
        _bvec2 _wz() const;
        _bvec2 _xw() const;
        _bvec2 _yw() const;
        _bvec2 _zw() const;
        _bvec2 _ww() const;

        // 3 components swizzles operators
        _bvec3 _xxx() const;
        _bvec3 _yxx() const;
        _bvec3 _zxx() const;
        _bvec3 _wxx() const;
        _bvec3 _xyx() const;
        _bvec3 _yyx() const;
        _bvec3 _zyx() const;
        _bvec3 _wyx() const;
        _bvec3 _xzx() const;
        _bvec3 _yzx() const;
        _bvec3 _zzx() const;
        _bvec3 _wzx() const;
        _bvec3 _xwx() const;
        _bvec3 _ywx() const;
        _bvec3 _zwx() const;
        _bvec3 _wwx() const;
        _bvec3 _xxy() const;
        _bvec3 _yxy() const;
        _bvec3 _zxy() const;
        _bvec3 _wxy() const;
        _bvec3 _xyy() const;
        _bvec3 _yyy() const;
        _bvec3 _zyy() const;
        _bvec3 _wyy() const;
        _bvec3 _xzy() const;
        _bvec3 _yzy() const;
        _bvec3 _zzy() const;
        _bvec3 _wzy() const;
        _bvec3 _xwy() const;
        _bvec3 _ywy() const;
        _bvec3 _zwy() const;
        _bvec3 _wwy() const;
        _bvec3 _xxz() const;
        _bvec3 _yxz() const;
        _bvec3 _zxz() const;
        _bvec3 _wxz() const;
        _bvec3 _xyz() const;
        _bvec3 _yyz() const;
        _bvec3 _zyz() const;
        _bvec3 _wyz() const;
        _bvec3 _xzz() const;
        _bvec3 _yzz() const;
        _bvec3 _zzz() const;
        _bvec3 _wzz() const;
        _bvec3 _xwz() const;
        _bvec3 _ywz() const;
        _bvec3 _zwz() const;
        _bvec3 _wwz() const;
        _bvec3 _xxw() const;
        _bvec3 _yxw() const;
        _bvec3 _zxw() const;
        _bvec3 _wxw() const;
        _bvec3 _xyw() const;
        _bvec3 _yyw() const;
        _bvec3 _zyw() const;
        _bvec3 _wyw() const;
        _bvec3 _xzw() const;
        _bvec3 _yzw() const;
        _bvec3 _zzw() const;
        _bvec3 _wzw() const;
        _bvec3 _xww() const;
        _bvec3 _yww() const;
        _bvec3 _zww() const;
        _bvec3 _www() const;

        // 4 components swizzles operators
        _bvec4 _xxxx() const;
        _bvec4 _yxxx() const;
        _bvec4 _zxxx() const;
        _bvec4 _wxxx() const;
        _bvec4 _xyxx() const;
        _bvec4 _yyxx() const;
        _bvec4 _zyxx() const;
        _bvec4 _wyxx() const;
        _bvec4 _xzxx() const;
        _bvec4 _yzxx() const;
        _bvec4 _zzxx() const;
        _bvec4 _wzxx() const;
        _bvec4 _xwxx() const;
        _bvec4 _ywxx() const;
        _bvec4 _zwxx() const;
        _bvec4 _wwxx() const;
        _bvec4 _xxyx() const;
        _bvec4 _yxyx() const;
        _bvec4 _zxyx() const;
        _bvec4 _wxyx() const;
        _bvec4 _xyyx() const;
        _bvec4 _yyyx() const;
        _bvec4 _zyyx() const;
        _bvec4 _wyyx() const;
        _bvec4 _xzyx() const;
        _bvec4 _yzyx() const;
        _bvec4 _zzyx() const;
        _bvec4 _wzyx() const;
        _bvec4 _xwyx() const;
        _bvec4 _ywyx() const;
        _bvec4 _zwyx() const;
        _bvec4 _wwyx() const;
        _bvec4 _xxzx() const;
        _bvec4 _yxzx() const;
        _bvec4 _zxzx() const;
        _bvec4 _wxzx() const;
        _bvec4 _xyzx() const;
        _bvec4 _yyzx() const;
        _bvec4 _zyzx() const;
        _bvec4 _wyzx() const;
        _bvec4 _xzzx() const;
        _bvec4 _yzzx() const;
        _bvec4 _zzzx() const;
        _bvec4 _wzzx() const;
        _bvec4 _xwzx() const;
        _bvec4 _ywzx() const;
        _bvec4 _zwzx() const;
        _bvec4 _wwzx() const;
        _bvec4 _xxwx() const;
        _bvec4 _yxwx() const;
        _bvec4 _zxwx() const;
        _bvec4 _wxwx() const;
        _bvec4 _xywx() const;
        _bvec4 _yywx() const;
        _bvec4 _zywx() const;
        _bvec4 _wywx() const;
        _bvec4 _xzwx() const;
        _bvec4 _yzwx() const;
        _bvec4 _zzwx() const;
        _bvec4 _wzwx() const;
        _bvec4 _xwwx() const;
        _bvec4 _ywwx() const;
        _bvec4 _zwwx() const;
        _bvec4 _wwwx() const;
        _bvec4 _xxxy() const;
        _bvec4 _yxxy() const;
        _bvec4 _zxxy() const;
        _bvec4 _wxxy() const;
        _bvec4 _xyxy() const;
        _bvec4 _yyxy() const;
        _bvec4 _zyxy() const;
        _bvec4 _wyxy() const;
        _bvec4 _xzxy() const;
        _bvec4 _yzxy() const;
        _bvec4 _zzxy() const;
        _bvec4 _wzxy() const;
        _bvec4 _xwxy() const;
        _bvec4 _ywxy() const;
        _bvec4 _zwxy() const;
        _bvec4 _wwxy() const;
        _bvec4 _xxyy() const;
        _bvec4 _yxyy() const;
        _bvec4 _zxyy() const;
        _bvec4 _wxyy() const;
        _bvec4 _xyyy() const;
        _bvec4 _yyyy() const;
        _bvec4 _zyyy() const;
        _bvec4 _wyyy() const;
        _bvec4 _xzyy() const;
        _bvec4 _yzyy() const;
        _bvec4 _zzyy() const;
        _bvec4 _wzyy() const;
        _bvec4 _xwyy() const;
        _bvec4 _ywyy() const;
        _bvec4 _zwyy() const;
        _bvec4 _wwyy() const;
        _bvec4 _xxzy() const;
        _bvec4 _yxzy() const;
        _bvec4 _zxzy() const;
        _bvec4 _wxzy() const;
        _bvec4 _xyzy() const;
        _bvec4 _yyzy() const;
        _bvec4 _zyzy() const;
        _bvec4 _wyzy() const;
        _bvec4 _xzzy() const;
        _bvec4 _yzzy() const;
        _bvec4 _zzzy() const;
        _bvec4 _wzzy() const;
        _bvec4 _xwzy() const;
        _bvec4 _ywzy() const;
        _bvec4 _zwzy() const;
        _bvec4 _wwzy() const;
        _bvec4 _xxwy() const;
        _bvec4 _yxwy() const;
        _bvec4 _zxwy() const;
        _bvec4 _wxwy() const;
        _bvec4 _xywy() const;
        _bvec4 _yywy() const;
        _bvec4 _zywy() const;
        _bvec4 _wywy() const;
        _bvec4 _xzwy() const;
        _bvec4 _yzwy() const;
        _bvec4 _zzwy() const;
        _bvec4 _wzwy() const;
        _bvec4 _xwwy() const;
        _bvec4 _ywwy() const;
        _bvec4 _zwwy() const;
        _bvec4 _wwwy() const;
        _bvec4 _xxxz() const;
        _bvec4 _yxxz() const;
        _bvec4 _zxxz() const;
        _bvec4 _wxxz() const;
        _bvec4 _xyxz() const;
        _bvec4 _yyxz() const;
        _bvec4 _zyxz() const;
        _bvec4 _wyxz() const;
        _bvec4 _xzxz() const;
        _bvec4 _yzxz() const;
        _bvec4 _zzxz() const;
        _bvec4 _wzxz() const;
        _bvec4 _xwxz() const;
        _bvec4 _ywxz() const;
        _bvec4 _zwxz() const;
        _bvec4 _wwxz() const;
        _bvec4 _xxyz() const;
        _bvec4 _yxyz() const;
        _bvec4 _zxyz() const;
        _bvec4 _wxyz() const;
        _bvec4 _xyyz() const;
        _bvec4 _yyyz() const;
        _bvec4 _zyyz() const;
        _bvec4 _wyyz() const;
        _bvec4 _xzyz() const;
        _bvec4 _yzyz() const;
        _bvec4 _zzyz() const;
        _bvec4 _wzyz() const;
        _bvec4 _xwyz() const;
        _bvec4 _ywyz() const;
        _bvec4 _zwyz() const;
        _bvec4 _wwyz() const;
        _bvec4 _xxzz() const;
        _bvec4 _yxzz() const;
        _bvec4 _zxzz() const;
        _bvec4 _wxzz() const;
        _bvec4 _xyzz() const;
        _bvec4 _yyzz() const;
        _bvec4 _zyzz() const;
        _bvec4 _wyzz() const;
        _bvec4 _xzzz() const;
        _bvec4 _yzzz() const;
        _bvec4 _zzzz() const;
        _bvec4 _wzzz() const;
        _bvec4 _xwzz() const;
        _bvec4 _ywzz() const;
        _bvec4 _zwzz() const;
        _bvec4 _wwzz() const;
        _bvec4 _xxwz() const;
        _bvec4 _yxwz() const;
        _bvec4 _zxwz() const;
        _bvec4 _wxwz() const;
        _bvec4 _xywz() const;
        _bvec4 _yywz() const;
        _bvec4 _zywz() const;
        _bvec4 _wywz() const;
        _bvec4 _xzwz() const;
        _bvec4 _yzwz() const;
        _bvec4 _zzwz() const;
        _bvec4 _wzwz() const;
        _bvec4 _xwwz() const;
        _bvec4 _ywwz() const;
        _bvec4 _zwwz() const;
        _bvec4 _wwwz() const;
        _bvec4 _xxxw() const;
        _bvec4 _yxxw() const;
        _bvec4 _zxxw() const;
        _bvec4 _wxxw() const;
        _bvec4 _xyxw() const;
        _bvec4 _yyxw() const;
        _bvec4 _zyxw() const;
        _bvec4 _wyxw() const;
        _bvec4 _xzxw() const;
        _bvec4 _yzxw() const;
        _bvec4 _zzxw() const;
        _bvec4 _wzxw() const;
        _bvec4 _xwxw() const;
        _bvec4 _ywxw() const;
        _bvec4 _zwxw() const;
        _bvec4 _wwxw() const;
        _bvec4 _xxyw() const;
        _bvec4 _yxyw() const;
        _bvec4 _zxyw() const;
        _bvec4 _wxyw() const;
        _bvec4 _xyyw() const;
        _bvec4 _yyyw() const;
        _bvec4 _zyyw() const;
        _bvec4 _wyyw() const;
        _bvec4 _xzyw() const;
        _bvec4 _yzyw() const;
        _bvec4 _zzyw() const;
        _bvec4 _wzyw() const;
        _bvec4 _xwyw() const;
        _bvec4 _ywyw() const;
        _bvec4 _zwyw() const;
        _bvec4 _wwyw() const;
        _bvec4 _xxzw() const;
        _bvec4 _yxzw() const;
        _bvec4 _zxzw() const;
        _bvec4 _wxzw() const;
        _bvec4 _xyzw() const;
        _bvec4 _yyzw() const;
        _bvec4 _zyzw() const;
        _bvec4 _wyzw() const;
        _bvec4 _xzzw() const;
        _bvec4 _yzzw() const;
        _bvec4 _zzzw() const;
        _bvec4 _wzzw() const;
        _bvec4 _xwzw() const;
        _bvec4 _ywzw() const;
        _bvec4 _zwzw() const;
        _bvec4 _wwzw() const;
        _bvec4 _xxww() const;
        _bvec4 _yxww() const;
        _bvec4 _zxww() const;
        _bvec4 _wxww() const;
        _bvec4 _xyww() const;
        _bvec4 _yyww() const;
        _bvec4 _zyww() const;
        _bvec4 _wyww() const;
        _bvec4 _xzww() const;
        _bvec4 _yzww() const;
        _bvec4 _zzww() const;
        _bvec4 _wzww() const;
        _bvec4 _xwww() const;
        _bvec4 _ywww() const;
        _bvec4 _zwww() const;
        _bvec4 _wwww() const;

        // 2 components color swizzle operators
        _bvec2 _rr() const;
        _bvec2 _gr() const;
        _bvec2 _br() const;
        _bvec2 _ar() const;
        _bvec2 _rg() const;
        _bvec2 _gg() const;
        _bvec2 _bg() const;
        _bvec2 _ag() const;
        _bvec2 _rb() const;
        _bvec2 _gb() const;
        _bvec2 _bb() const;
        _bvec2 _ab() const;
        _bvec2 _ra() const;
        _bvec2 _ga() const;
        _bvec2 _ba() const;
        _bvec2 _aa() const;

        // 3 components color swizzle operators
        _bvec3 _rrr() const;
        _bvec3 _grr() const;
        _bvec3 _brr() const;
        _bvec3 _arr() const;
        _bvec3 _rgr() const;
        _bvec3 _ggr() const;
        _bvec3 _bgr() const;
        _bvec3 _agr() const;
        _bvec3 _rbr() const;
        _bvec3 _gbr() const;
        _bvec3 _bbr() const;
        _bvec3 _abr() const;
        _bvec3 _rar() const;
        _bvec3 _gar() const;
        _bvec3 _bar() const;
        _bvec3 _aar() const;
        _bvec3 _rrg() const;
        _bvec3 _grg() const;
        _bvec3 _brg() const;
        _bvec3 _arg() const;
        _bvec3 _rgg() const;
        _bvec3 _ggg() const;
        _bvec3 _bgg() const;
        _bvec3 _agg() const;
        _bvec3 _rbg() const;
        _bvec3 _gbg() const;
        _bvec3 _bbg() const;
        _bvec3 _abg() const;
        _bvec3 _rag() const;
        _bvec3 _gag() const;
        _bvec3 _bag() const;
        _bvec3 _aag() const;
        _bvec3 _rrb() const;
        _bvec3 _grb() const;
        _bvec3 _brb() const;
        _bvec3 _arb() const;
        _bvec3 _rgb() const;
        _bvec3 _ggb() const;
        _bvec3 _bgb() const;
        _bvec3 _agb() const;
        _bvec3 _rbb() const;
        _bvec3 _gbb() const;
        _bvec3 _bbb() const;
        _bvec3 _abb() const;
        _bvec3 _rab() const;
        _bvec3 _gab() const;
        _bvec3 _bab() const;
        _bvec3 _aab() const;
        _bvec3 _rra() const;
        _bvec3 _gra() const;
        _bvec3 _bra() const;
        _bvec3 _ara() const;
        _bvec3 _rga() const;
        _bvec3 _gga() const;
        _bvec3 _bga() const;
        _bvec3 _aga() const;
        _bvec3 _rba() const;
        _bvec3 _gba() const;
        _bvec3 _bba() const;
        _bvec3 _aba() const;
        _bvec3 _raa() const;
        _bvec3 _gaa() const;
        _bvec3 _baa() const;
        _bvec3 _aaa() const;

        // 4 components color swizzle operators
        _bvec4 _rrrr() const;
        _bvec4 _grrr() const;
        _bvec4 _brrr() const;
        _bvec4 _arrr() const;
        _bvec4 _rgrr() const;
        _bvec4 _ggrr() const;
        _bvec4 _bgrr() const;
        _bvec4 _agrr() const;
        _bvec4 _rbrr() const;
        _bvec4 _gbrr() const;
        _bvec4 _bbrr() const;
        _bvec4 _abrr() const;
        _bvec4 _rarr() const;
        _bvec4 _garr() const;
        _bvec4 _barr() const;
        _bvec4 _aarr() const;
        _bvec4 _rrgr() const;
        _bvec4 _grgr() const;
        _bvec4 _brgr() const;
        _bvec4 _argr() const;
        _bvec4 _rggr() const;
        _bvec4 _gggr() const;
        _bvec4 _bggr() const;
        _bvec4 _aggr() const;
        _bvec4 _rbgr() const;
        _bvec4 _gbgr() const;
        _bvec4 _bbgr() const;
        _bvec4 _abgr() const;
        _bvec4 _ragr() const;
        _bvec4 _gagr() const;
        _bvec4 _bagr() const;
        _bvec4 _aagr() const;
        _bvec4 _rrbr() const;
        _bvec4 _grbr() const;
        _bvec4 _brbr() const;
        _bvec4 _arbr() const;
        _bvec4 _rgbr() const;
        _bvec4 _ggbr() const;
        _bvec4 _bgbr() const;
        _bvec4 _agbr() const;
        _bvec4 _rbbr() const;
        _bvec4 _gbbr() const;
        _bvec4 _bbbr() const;
        _bvec4 _abbr() const;
        _bvec4 _rabr() const;
        _bvec4 _gabr() const;
        _bvec4 _babr() const;
        _bvec4 _aabr() const;
        _bvec4 _rrar() const;
        _bvec4 _grar() const;
        _bvec4 _brar() const;
        _bvec4 _arar() const;
        _bvec4 _rgar() const;
        _bvec4 _ggar() const;
        _bvec4 _bgar() const;
        _bvec4 _agar() const;
        _bvec4 _rbar() const;
        _bvec4 _gbar() const;
        _bvec4 _bbar() const;
        _bvec4 _abar() const;
        _bvec4 _raar() const;
        _bvec4 _gaar() const;
        _bvec4 _baar() const;
        _bvec4 _aaar() const;
        _bvec4 _rrrg() const;
        _bvec4 _grrg() const;
        _bvec4 _brrg() const;
        _bvec4 _arrg() const;
        _bvec4 _rgrg() const;
        _bvec4 _ggrg() const;
        _bvec4 _bgrg() const;
        _bvec4 _agrg() const;
        _bvec4 _rbrg() const;
        _bvec4 _gbrg() const;
        _bvec4 _bbrg() const;
        _bvec4 _abrg() const;
        _bvec4 _rarg() const;
        _bvec4 _garg() const;
        _bvec4 _barg() const;
        _bvec4 _aarg() const;
        _bvec4 _rrgg() const;
        _bvec4 _grgg() const;
        _bvec4 _brgg() const;
        _bvec4 _argg() const;
        _bvec4 _rggg() const;
        _bvec4 _gggg() const;
        _bvec4 _bggg() const;
        _bvec4 _aggg() const;
        _bvec4 _rbgg() const;
        _bvec4 _gbgg() const;
        _bvec4 _bbgg() const;
        _bvec4 _abgg() const;
        _bvec4 _ragg() const;
        _bvec4 _gagg() const;
        _bvec4 _bagg() const;
        _bvec4 _aagg() const;
        _bvec4 _rrbg() const;
        _bvec4 _grbg() const;
        _bvec4 _brbg() const;
        _bvec4 _arbg() const;
        _bvec4 _rgbg() const;
        _bvec4 _ggbg() const;
        _bvec4 _bgbg() const;
        _bvec4 _agbg() const;
        _bvec4 _rbbg() const;
        _bvec4 _gbbg() const;
        _bvec4 _bbbg() const;
        _bvec4 _abbg() const;
        _bvec4 _rabg() const;
        _bvec4 _gabg() const;
        _bvec4 _babg() const;
        _bvec4 _aabg() const;
        _bvec4 _rrag() const;
        _bvec4 _grag() const;
        _bvec4 _brag() const;
        _bvec4 _arag() const;
        _bvec4 _rgag() const;
        _bvec4 _ggag() const;
        _bvec4 _bgag() const;
        _bvec4 _agag() const;
        _bvec4 _rbag() const;
        _bvec4 _gbag() const;
        _bvec4 _bbag() const;
        _bvec4 _abag() const;
        _bvec4 _raag() const;
        _bvec4 _gaag() const;
        _bvec4 _baag() const;
        _bvec4 _aaag() const;
        _bvec4 _rrrb() const;
        _bvec4 _grrb() const;
        _bvec4 _brrb() const;
        _bvec4 _arrb() const;
        _bvec4 _rgrb() const;
        _bvec4 _ggrb() const;
        _bvec4 _bgrb() const;
        _bvec4 _agrb() const;
        _bvec4 _rbrb() const;
        _bvec4 _gbrb() const;
        _bvec4 _bbrb() const;
        _bvec4 _abrb() const;
        _bvec4 _rarb() const;
        _bvec4 _garb() const;
        _bvec4 _barb() const;
        _bvec4 _aarb() const;
        _bvec4 _rrgb() const;
        _bvec4 _grgb() const;
        _bvec4 _brgb() const;
        _bvec4 _argb() const;
        _bvec4 _rggb() const;
        _bvec4 _gggb() const;
        _bvec4 _bggb() const;
        _bvec4 _aggb() const;
        _bvec4 _rbgb() const;
        _bvec4 _gbgb() const;
        _bvec4 _bbgb() const;
        _bvec4 _abgb() const;
        _bvec4 _ragb() const;
        _bvec4 _gagb() const;
        _bvec4 _bagb() const;
        _bvec4 _aagb() const;
        _bvec4 _rrbb() const;
        _bvec4 _grbb() const;
        _bvec4 _brbb() const;
        _bvec4 _arbb() const;
        _bvec4 _rgbb() const;
        _bvec4 _ggbb() const;
        _bvec4 _bgbb() const;
        _bvec4 _agbb() const;
        _bvec4 _rbbb() const;
        _bvec4 _gbbb() const;
        _bvec4 _bbbb() const;
        _bvec4 _abbb() const;
        _bvec4 _rabb() const;
        _bvec4 _gabb() const;
        _bvec4 _babb() const;
        _bvec4 _aabb() const;
        _bvec4 _rrab() const;
        _bvec4 _grab() const;
        _bvec4 _brab() const;
        _bvec4 _arab() const;
        _bvec4 _rgab() const;
        _bvec4 _ggab() const;
        _bvec4 _bgab() const;
        _bvec4 _agab() const;
        _bvec4 _rbab() const;
        _bvec4 _gbab() const;
        _bvec4 _bbab() const;
        _bvec4 _abab() const;
        _bvec4 _raab() const;
        _bvec4 _gaab() const;
        _bvec4 _baab() const;
        _bvec4 _aaab() const;
        _bvec4 _rrra() const;
        _bvec4 _grra() const;
        _bvec4 _brra() const;
        _bvec4 _arra() const;
        _bvec4 _rgra() const;
        _bvec4 _ggra() const;
        _bvec4 _bgra() const;
        _bvec4 _agra() const;
        _bvec4 _rbra() const;
        _bvec4 _gbra() const;
        _bvec4 _bbra() const;
        _bvec4 _abra() const;
        _bvec4 _rara() const;
        _bvec4 _gara() const;
        _bvec4 _bara() const;
        _bvec4 _aara() const;
        _bvec4 _rrga() const;
        _bvec4 _grga() const;
        _bvec4 _brga() const;
        _bvec4 _arga() const;
        _bvec4 _rgga() const;
        _bvec4 _ggga() const;
        _bvec4 _bgga() const;
        _bvec4 _agga() const;
        _bvec4 _rbga() const;
        _bvec4 _gbga() const;
        _bvec4 _bbga() const;
        _bvec4 _abga() const;
        _bvec4 _raga() const;
        _bvec4 _gaga() const;
        _bvec4 _baga() const;
        _bvec4 _aaga() const;
        _bvec4 _rrba() const;
        _bvec4 _grba() const;
        _bvec4 _brba() const;
        _bvec4 _arba() const;
        _bvec4 _rgba() const;
        _bvec4 _ggba() const;
        _bvec4 _bgba() const;
        _bvec4 _agba() const;
        _bvec4 _rbba() const;
        _bvec4 _gbba() const;
        _bvec4 _bbba() const;
        _bvec4 _abba() const;
        _bvec4 _raba() const;
        _bvec4 _gaba() const;
        _bvec4 _baba() const;
        _bvec4 _aaba() const;
        _bvec4 _rraa() const;
        _bvec4 _graa() const;
        _bvec4 _braa() const;
        _bvec4 _araa() const;
        _bvec4 _rgaa() const;
        _bvec4 _ggaa() const;
        _bvec4 _bgaa() const;
        _bvec4 _agaa() const;
        _bvec4 _rbaa() const;
        _bvec4 _gbaa() const;
        _bvec4 _bbaa() const;
        _bvec4 _abaa() const;
        _bvec4 _raaa() const;
        _bvec4 _gaaa() const;
        _bvec4 _baaa() const;
        _bvec4 _aaaa() const;

        // 2 components texcoord swizzle operators
        _bvec2 _ss() const;
        _bvec2 _ts() const;
        _bvec2 _ps() const;
        _bvec2 _qs() const;
        _bvec2 _st() const;
        _bvec2 _tt() const;
        _bvec2 _pt() const;
        _bvec2 _qt() const;
        _bvec2 _sp() const;
        _bvec2 _tp() const;
        _bvec2 _pp() const;
        _bvec2 _qp() const;
        _bvec2 _sq() const;
        _bvec2 _tq() const;
        _bvec2 _pq() const;
        _bvec2 _qq() const;

        // 3 components texcoosd swizzle opesqtoss
        _bvec3 _sss() const;
        _bvec3 _tss() const;
        _bvec3 _pss() const;
        _bvec3 _qss() const;
        _bvec3 _sts() const;
        _bvec3 _tts() const;
        _bvec3 _pts() const;
        _bvec3 _qts() const;
        _bvec3 _sps() const;
        _bvec3 _tps() const;
        _bvec3 _pps() const;
        _bvec3 _qps() const;
        _bvec3 _sqs() const;
        _bvec3 _tqs() const;
        _bvec3 _pqs() const;
        _bvec3 _qqs() const;
        _bvec3 _sst() const;
        _bvec3 _tst() const;
        _bvec3 _pst() const;
        _bvec3 _qst() const;
        _bvec3 _stt() const;
        _bvec3 _ttt() const;
        _bvec3 _ptt() const;
        _bvec3 _qtt() const;
        _bvec3 _spt() const;
        _bvec3 _tpt() const;
        _bvec3 _ppt() const;
        _bvec3 _qpt() const;
        _bvec3 _sqt() const;
        _bvec3 _tqt() const;
        _bvec3 _pqt() const;
        _bvec3 _qqt() const;
        _bvec3 _ssp() const;
        _bvec3 _tsp() const;
        _bvec3 _psp() const;
        _bvec3 _qsp() const;
        _bvec3 _stp() const;
        _bvec3 _ttp() const;
        _bvec3 _ptp() const;
        _bvec3 _qtp() const;
        _bvec3 _spp() const;
        _bvec3 _tpp() const;
        _bvec3 _ppp() const;
        _bvec3 _qpp() const;
        _bvec3 _sqp() const;
        _bvec3 _tqp() const;
        _bvec3 _pqp() const;
        _bvec3 _qqp() const;
        _bvec3 _ssq() const;
        _bvec3 _tsq() const;
        _bvec3 _psq() const;
        _bvec3 _qsq() const;
        _bvec3 _stq() const;
        _bvec3 _ttq() const;
        _bvec3 _ptq() const;
        _bvec3 _qtq() const;
        _bvec3 _spq() const;
        _bvec3 _tpq() const;
        _bvec3 _ppq() const;
        _bvec3 _qpq() const;
        _bvec3 _sqq() const;
        _bvec3 _tqq() const;
        _bvec3 _pqq() const;
        _bvec3 _qqq() const;

        // 4 components texcoosd swizzle opesqtoss
        _bvec4 _ssss() const;
        _bvec4 _tsss() const;
        _bvec4 _psss() const;
        _bvec4 _qsss() const;
        _bvec4 _stss() const;
        _bvec4 _ttss() const;
        _bvec4 _ptss() const;
        _bvec4 _qtss() const;
        _bvec4 _spss() const;
        _bvec4 _tpss() const;
        _bvec4 _ppss() const;
        _bvec4 _qpss() const;
        _bvec4 _sqss() const;
        _bvec4 _tqss() const;
        _bvec4 _pqss() const;
        _bvec4 _qqss() const;
        _bvec4 _ssts() const;
        _bvec4 _tsts() const;
        _bvec4 _psts() const;
        _bvec4 _qsts() const;
        _bvec4 _stts() const;
        _bvec4 _ttts() const;
        _bvec4 _ptts() const;
        _bvec4 _qtts() const;
        _bvec4 _spts() const;
        _bvec4 _tpts() const;
        _bvec4 _ppts() const;
        _bvec4 _qpts() const;
        _bvec4 _sqts() const;
        _bvec4 _tqts() const;
        _bvec4 _pqts() const;
        _bvec4 _qqts() const;
        _bvec4 _ssps() const;
        _bvec4 _tsps() const;
        _bvec4 _psps() const;
        _bvec4 _qsps() const;
        _bvec4 _stps() const;
        _bvec4 _ttps() const;
        _bvec4 _ptps() const;
        _bvec4 _qtps() const;
        _bvec4 _spps() const;
        _bvec4 _tpps() const;
        _bvec4 _ppps() const;
        _bvec4 _qpps() const;
        _bvec4 _sqps() const;
        _bvec4 _tqps() const;
        _bvec4 _pqps() const;
        _bvec4 _qqps() const;
        _bvec4 _ssqs() const;
        _bvec4 _tsqs() const;
        _bvec4 _psqs() const;
        _bvec4 _qsqs() const;
        _bvec4 _stqs() const;
        _bvec4 _ttqs() const;
        _bvec4 _ptqs() const;
        _bvec4 _qtqs() const;
        _bvec4 _spqs() const;
        _bvec4 _tpqs() const;
        _bvec4 _ppqs() const;
        _bvec4 _qpqs() const;
        _bvec4 _sqqs() const;
        _bvec4 _tqqs() const;
        _bvec4 _pqqs() const;
        _bvec4 _qqqs() const;
        _bvec4 _ssst() const;
        _bvec4 _tsst() const;
        _bvec4 _psst() const;
        _bvec4 _qsst() const;
        _bvec4 _stst() const;
        _bvec4 _ttst() const;
        _bvec4 _ptst() const;
        _bvec4 _qtst() const;
        _bvec4 _spst() const;
        _bvec4 _tpst() const;
        _bvec4 _ppst() const;
        _bvec4 _qpst() const;
        _bvec4 _sqst() const;
        _bvec4 _tqst() const;
        _bvec4 _pqst() const;
        _bvec4 _qqst() const;
        _bvec4 _sstt() const;
        _bvec4 _tstt() const;
        _bvec4 _pstt() const;
        _bvec4 _qstt() const;
        _bvec4 _sttt() const;
        _bvec4 _tttt() const;
        _bvec4 _pttt() const;
        _bvec4 _qttt() const;
        _bvec4 _sptt() const;
        _bvec4 _tptt() const;
        _bvec4 _pptt() const;
        _bvec4 _qptt() const;
        _bvec4 _sqtt() const;
        _bvec4 _tqtt() const;
        _bvec4 _pqtt() const;
        _bvec4 _qqtt() const;
        _bvec4 _sspt() const;
        _bvec4 _tspt() const;
        _bvec4 _pspt() const;
        _bvec4 _qspt() const;
        _bvec4 _stpt() const;
        _bvec4 _ttpt() const;
        _bvec4 _ptpt() const;
        _bvec4 _qtpt() const;
        _bvec4 _sppt() const;
        _bvec4 _tppt() const;
        _bvec4 _pppt() const;
        _bvec4 _qppt() const;
        _bvec4 _sqpt() const;
        _bvec4 _tqpt() const;
        _bvec4 _pqpt() const;
        _bvec4 _qqpt() const;
        _bvec4 _ssqt() const;
        _bvec4 _tsqt() const;
        _bvec4 _psqt() const;
        _bvec4 _qsqt() const;
        _bvec4 _stqt() const;
        _bvec4 _ttqt() const;
        _bvec4 _ptqt() const;
        _bvec4 _qtqt() const;
        _bvec4 _spqt() const;
        _bvec4 _tpqt() const;
        _bvec4 _ppqt() const;
        _bvec4 _qpqt() const;
        _bvec4 _sqqt() const;
        _bvec4 _tqqt() const;
        _bvec4 _pqqt() const;
        _bvec4 _qqqt() const;
        _bvec4 _sssp() const;
        _bvec4 _tssp() const;
        _bvec4 _pssp() const;
        _bvec4 _qssp() const;
        _bvec4 _stsp() const;
        _bvec4 _ttsp() const;
        _bvec4 _ptsp() const;
        _bvec4 _qtsp() const;
        _bvec4 _spsp() const;
        _bvec4 _tpsp() const;
        _bvec4 _ppsp() const;
        _bvec4 _qpsp() const;
        _bvec4 _sqsp() const;
        _bvec4 _tqsp() const;
        _bvec4 _pqsp() const;
        _bvec4 _qqsp() const;
        _bvec4 _sstp() const;
        _bvec4 _tstp() const;
        _bvec4 _pstp() const;
        _bvec4 _qstp() const;
        _bvec4 _sttp() const;
        _bvec4 _tttp() const;
        _bvec4 _pttp() const;
        _bvec4 _qttp() const;
        _bvec4 _sptp() const;
        _bvec4 _tptp() const;
        _bvec4 _pptp() const;
        _bvec4 _qptp() const;
        _bvec4 _sqtp() const;
        _bvec4 _tqtp() const;
        _bvec4 _pqtp() const;
        _bvec4 _qqtp() const;
        _bvec4 _sspp() const;
        _bvec4 _tspp() const;
        _bvec4 _pspp() const;
        _bvec4 _qspp() const;
        _bvec4 _stpp() const;
        _bvec4 _ttpp() const;
        _bvec4 _ptpp() const;
        _bvec4 _qtpp() const;
        _bvec4 _sppp() const;
        _bvec4 _tppp() const;
        _bvec4 _pppp() const;
        _bvec4 _qppp() const;
        _bvec4 _sqpp() const;
        _bvec4 _tqpp() const;
        _bvec4 _pqpp() const;
        _bvec4 _qqpp() const;
        _bvec4 _ssqp() const;
        _bvec4 _tsqp() const;
        _bvec4 _psqp() const;
        _bvec4 _qsqp() const;
        _bvec4 _stqp() const;
        _bvec4 _ttqp() const;
        _bvec4 _ptqp() const;
        _bvec4 _qtqp() const;
        _bvec4 _spqp() const;
        _bvec4 _tpqp() const;
        _bvec4 _ppqp() const;
        _bvec4 _qpqp() const;
        _bvec4 _sqqp() const;
        _bvec4 _tqqp() const;
        _bvec4 _pqqp() const;
        _bvec4 _qqqp() const;
        _bvec4 _sssq() const;
        _bvec4 _tssq() const;
        _bvec4 _pssq() const;
        _bvec4 _qssq() const;
        _bvec4 _stsq() const;
        _bvec4 _ttsq() const;
        _bvec4 _ptsq() const;
        _bvec4 _qtsq() const;
        _bvec4 _spsq() const;
        _bvec4 _tpsq() const;
        _bvec4 _ppsq() const;
        _bvec4 _qpsq() const;
        _bvec4 _sqsq() const;
        _bvec4 _tqsq() const;
        _bvec4 _pqsq() const;
        _bvec4 _qqsq() const;
        _bvec4 _sstq() const;
        _bvec4 _tstq() const;
        _bvec4 _pstq() const;
        _bvec4 _qstq() const;
        _bvec4 _sttq() const;
        _bvec4 _tttq() const;
        _bvec4 _pttq() const;
        _bvec4 _qttq() const;
        _bvec4 _sptq() const;
        _bvec4 _tptq() const;
        _bvec4 _pptq() const;
        _bvec4 _qptq() const;
        _bvec4 _sqtq() const;
        _bvec4 _tqtq() const;
        _bvec4 _pqtq() const;
        _bvec4 _qqtq() const;
        _bvec4 _sspq() const;
        _bvec4 _tspq() const;
        _bvec4 _pspq() const;
        _bvec4 _qspq() const;
        _bvec4 _stpq() const;
        _bvec4 _ttpq() const;
        _bvec4 _ptpq() const;
        _bvec4 _qtpq() const;
        _bvec4 _sppq() const;
        _bvec4 _tppq() const;
        _bvec4 _pppq() const;
        _bvec4 _qppq() const;
        _bvec4 _sqpq() const;
        _bvec4 _tqpq() const;
        _bvec4 _pqpq() const;
        _bvec4 _qqpq() const;
        _bvec4 _ssqq() const;
        _bvec4 _tsqq() const;
        _bvec4 _psqq() const;
        _bvec4 _qsqq() const;
        _bvec4 _stqq() const;
        _bvec4 _ttqq() const;
        _bvec4 _ptqq() const;
        _bvec4 _qtqq() const;
        _bvec4 _spqq() const;
        _bvec4 _tpqq() const;
        _bvec4 _ppqq() const;
        _bvec4 _qpqq() const;
        _bvec4 _sqqq() const;
        _bvec4 _tqqq() const;
        _bvec4 _pqqq() const;
        _bvec4 _qqqq() const;
    };
} //namespace glm

#endif//__bvec4_h__
