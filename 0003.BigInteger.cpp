#include <iostream.h> 
#include <string>     
#include <stdio.h>
#include <algorithm>

//大整数类
class BigInteger
{
public:
    //默认构造
    explicit BigInteger(const std::string& str="0") : m_str(str) {Normal();}
    //构造
    explicit BigInteger(double d)
    {
        m_str=ToString(d);
        Normal();
    }
    explicit BigInteger(float f)
    {
        m_str=ToString(f);
        Normal();
    }
    explicit BigInteger(int i)
    {
        m_str=ToString(i);
        Normal();
    }
    //输入流运算
    friend std::ostream& operator<< (std::ostream& out, const BigInteger& big);
    //输出流运算
    friend std::istream& operator>> (std::istream& in, BigInteger& big);
    //赋值
    BigInteger& operator= (const BigInteger& rbs);
    BigInteger& operator= (double d);
    BigInteger& operator= (float f);
    BigInteger& operator= (int i);
    //高精度乘法
    BigInteger operator* (const BigInteger& other)
    { return signMultiply(*this, other);}
    //高精度加法
    BigInteger operator +(const BigInteger& other)
    { return signAdd(*this, other);}
    //高精度减法
    BigInteger operator- (const BigInteger& other)
    { return signMinuse(*this, other);}
    //高精度乘方 
    BigInteger operator ^(int n)
    { return BigInteger(pow(m_str, n));}
    //高精度正数取模
    BigInteger operator% (const BigInteger& other);
    //比较
    bool operator< (const BigInteger& rbs)
    { return signCompare(*this, rbs)==-1; }
    bool operator== (const BigInteger& rbs)
    { return signCompare(*this, rbs)==0; }
    std::string ToString();
private:
    //规范化
    void Normal();
    void Unnormal();
    //转换
    std::string ToString(int n);
    std::string ToString(double n);
    std::string ToString(float n);
    //有符号高精度运算及其比较
    BigInteger signMultiply(const BigInteger& l, const BigInteger& r);
    BigInteger signAdd(const BigInteger& l, const BigInteger& r);
    BigInteger signMinuse(const BigInteger& l, const BigInteger& r);
    int signCompare(const BigInteger& a, const BigInteger& b);
    //无符号比较
    int Compare(const std::string& a, const std::string& b);
    //无符号高精度运算
    std::string MultiplyEx (std::string s, std::string t);
    std::string Multiply (std::string lbs, std::string rbs);
    std::string AddEx(std::string a, std::string b);
    std::string Add(std::string lbs, std::string rbs);
    std::string MinusEx(std::string a, std::string b, bool& sign);
    std::string Minuss (std::string lbs, std::string rbs, bool& sign);
    std::string pow(const std::string& b, int n);
    std::string mod(std::string s, const std::string& t);
    //
    bool isZero(const std::string& s);
private:
    bool m_sign;
    std::string m_str; //内部字符串
};

std::ostream& operator<< (std::ostream& out, const BigInteger& big)
{
    if (!big.m_sign)
        out.put('-');
     out<<big.m_str;
     return out;
}

std::istream& operator>> (std::istream& in, BigInteger& big)
{
     in>>big.m_str;
     big.Normal();
     return in;
}

BigInteger& BigInteger::operator= (const BigInteger& rbs)
{
    if ( this!=&rbs )
    {
        m_str=rbs.m_str;
    }
    return *this;
}

BigInteger& BigInteger::operator= (double d)
{
    m_str=ToString(d);
    Normal();
    return *this;
}

BigInteger& BigInteger::operator= (float f)
{
    m_str=ToString(f);
    Normal();
    return *this;
}

BigInteger& BigInteger::operator= (int i)
{
    m_str=ToString(i);
    Normal();
    return *this;
}

BigInteger BigInteger::operator% (const BigInteger& other)
{
    BigInteger ret;
    ret.m_str=mod(m_str, other.m_str);
    ret.m_sign=true;
    return ret;
}

bool BigInteger::isZero(const std::string& s)
{
    for (size_t i=0; i<s.size(); ++i)
        if (s[i]!='0')
            return false;
    return true;
}

std::string BigInteger::ToString()
{
    std::string s;
    if (!m_sign)
        s.push_back('-');
    return s+m_str;
}

std::string BigInteger::ToString(int n)
{
    static char buf[100];
    sprintf(buf,"%d", n);
    return std::string(buf);
}

std::string BigInteger::ToString(double n)
{
    static char buf[100];
    sprintf(buf,"%f", n);
    return std::string(buf);
}
std::string BigInteger::ToString(float n)
{
    static char buf[100];
    sprintf(buf,"%f", n);
    return std::string(buf);
}

void BigInteger::Normal()
{
    if (m_str[0]=='-')
    {
        m_sign=false;
        m_str.erase(0,1);
    }
    else
        m_sign=true;
}

void BigInteger::Unnormal()
{
    if (!m_sign)
        m_str="0"+m_str;
}

BigInteger BigInteger::signMultiply(const BigInteger& l, const BigInteger& r)
{
    BigInteger ret;
    ret.m_sign=!(l.m_sign^r.m_sign);
    ret.m_str=MultiplyEx(l.m_str, r.m_str);
    if (ret.m_str=="0")
        ret.m_sign=true;
    return ret;
}

std::string BigInteger::mod(std::string s, const std::string& t)
{
    std::string p;
    bool f;
    {
        int size=t.size();
        p=s.substr(0, size);
        s.erase(0, size);
        while (!s.empty())
        {
            while (Compare(p,t)>=0)
                p=Minuss(p,t, f);
            if (p=="0")
            {
                p=s.substr(0, size);
                s.erase(0, size);
                if (isZero(p))
                {
                    p="0";
                    break;
                }
            }
            else
            {
                p+=s.substr(0, 1);
                s.erase(0,1);
            }
        }

        if (p=="0")
            p=s;
        else
            p+=s;
        if (isZero(p))
            p="0";
        while (Compare(p,t)>=0)
            p=Minuss(p,t, f);
    }
    return p;
}

std::string BigInteger::Multiply(std::string lbs, std::string rbs)
{
    int* g_lbs;
    int* g_rbs;
    int* g_result;
    char buffer[10];
    int lenLbs=lbs.length();
    int lenRbs=rbs.length();
    //初始化数组
    int sizeLbs=lenLbs%4==0?lenLbs/4:lenLbs/4+1;
    int sizeRbs=lenRbs%4==0?lenRbs/4:lenRbs/4+1;
    g_lbs=new int[sizeLbs+1];
    g_rbs=new int[sizeRbs+1];
    int i,j;
    memset(g_lbs, 0, sizeof(int)*(sizeLbs+1));
    memset(g_rbs, 0, sizeof(int)*(sizeRbs+1));
    std::string str;
    //字符串到数组转化
    int count=1;
    while (lbs.length()>=4)
    {
        str=lbs.substr(lbs.length()-4);
        lbs.erase(lbs.length()-4);
        g_lbs[count]=atoi(str.c_str());
        ++count;
    }
    if (!lbs.empty())
    {
        str=lbs;
        lbs.clear();
        g_lbs[count]=atoi(str.c_str());
    }
    count=1;
    while (rbs.length()>=4)
    {
        str=rbs.substr(rbs.length()-4);
        rbs.erase(rbs.length()-4);
        g_rbs[count]=atoi(str.c_str());
        ++count;
    }
    if (!rbs.empty())
    {
        str=rbs;
        rbs.clear();
        g_rbs[count]=atoi(str.c_str());
    }
    //初始化结果数组
    g_result=new int[sizeLbs*sizeRbs+2];
    memset(g_result, 0, sizeof(int)*(sizeLbs*sizeRbs+2));
    //乘法运算
    for (i=1; i<=sizeLbs; ++i)
    {
        for (j=1; j<=sizeRbs; ++j)
        {
            g_result[i+j-1]+=g_lbs[i]*g_rbs[j];
            g_result[i+j]+=g_result[i+j-1]/10000;
            g_result[i+j-1]=g_result[i+j-1]%10000;
        }
    }
    //输出
    std::string ret;
    i=sizeLbs*sizeRbs+1;
    while (!g_result[i])
    {
        --i;
        if (i==0)
        {
            ret="0";
            goto leave;
        }
    }

    sprintf(buffer,"%d", g_result[i--]);
    ret.append(buffer);
    for (j=i; j>=1; --j)
    {
        if (g_result[j]<1000)
        {
            ret.append("0");
        }
        if (g_result[j]<100)
        {
            ret.append("0");
        }
        if (g_result[j]<10)
        {
            ret.append("0");
        }
        sprintf(buffer,"%d", g_result[j]);
        ret.append(buffer);
    }
leave:
    delete[] g_lbs;
    delete[] g_rbs;
    delete[] g_result;
    return ret;
}

std::string BigInteger::Add(std::string lbs, std::string rbs)
{
    int* g_lbs;
    int* g_rbs;
    int* g_result;
    char buffer[10];
    //调整
    int lenLbs=lbs.length();
    int lenRbs=rbs.length();
    if (lenLbs<lenRbs)
    {
        std::swap(lbs, rbs);
        std::swap(lenLbs, lenRbs);
    }
    //初始化数组
    int sizeLbs=lenLbs%4==0?lenLbs/4:lenLbs/4+1;
    int sizeRbs=lenRbs%4==0?lenRbs/4:lenRbs/4+1;
    g_lbs=new int[sizeLbs];
    g_rbs=new int[sizeRbs];
    int i,j;
    memset(g_lbs, 0, sizeof(int)*sizeLbs);
    memset(g_rbs, 0, sizeof(int)*sizeRbs);
    std::string str;
    //字符串到数组转化
    int count=0;
    while (lbs.length()>=4)
    {
        str=lbs.substr(lbs.length()-4);
        lbs.erase(lbs.length()-4);
        g_lbs[count]=atoi(str.c_str());
        ++count;
    }
    if (!lbs.empty())
    {
        str=lbs;
        lbs.clear();
        g_lbs[count]=atoi(str.c_str());
    }
    count=0;
    while (rbs.length()>=4)
    {
        str=rbs.substr(rbs.length()-4);
        rbs.erase(rbs.length()-4);
        g_rbs[count]=atoi(str.c_str());
        ++count;
    }
    if (!rbs.empty())
    {
        str=rbs;
        rbs.clear();
        g_rbs[count]=atoi(str.c_str());
    }
    //初始化结果数组
    g_result=new int[sizeLbs+1];
    memset(g_result, 0, sizeof(int)*(sizeLbs+1));
    //加法运算
    for (j=0; j<sizeLbs; ++j)
    {
        if (j<sizeRbs)
        {
            g_result[j]+=g_lbs[j]+g_rbs[j];
        }
        else
        {
            g_result[j]+=g_lbs[j];
        }
        g_result[j+1]+=g_result[j]/10000;
        g_result[j]%=10000;
    }
    //输出
    std::string ret;
    i=sizeLbs;
    while (!g_result[i])
    {
        --i;
        if (i==-1)
        {
            ret.append("0");
            goto leave;
        }
    }
    sprintf(buffer, "%d", g_result[i--]);
    ret.append(buffer);
    for (j=i; j>=0; --j)
    {
        if (g_result[j]<1000)
        {
            ret.append("0");
        }
        if (g_result[j]<100)
        {
            ret.append("0");
        }
        if (g_result[j]<10)
        {
            ret.append("0");
        }
        sprintf(buffer, "%d", g_result[j]);
        ret.append(buffer);
    }
leave:
    delete[] g_lbs;
    delete[] g_rbs;
    delete[] g_result;
    return ret;
}

BigInteger BigInteger::signAdd(const BigInteger& l, const BigInteger& r)
{
    BigInteger ret;
    if (l.m_sign==r.m_sign)
    {
        ret.m_sign=l.m_sign;
        ret.m_str=AddEx(l.m_str, r.m_str);
    }
    else
    {
        bool f;
        if (Compare(l.m_str, r.m_str)<0)
        {
            ret.m_str=MinusEx(r.m_str, l.m_str, f);
            ret.m_sign=r.m_sign;
        }
        else
        {
            ret.m_str=MinusEx(l.m_str, r.m_str, f);
            ret.m_sign=l.m_sign;
        }
    }
    if (ret.m_str=="0")
        ret.m_sign=true;
    return ret;
}

std::string BigInteger::MultiplyEx(std::string s, std::string t)
{
    int dots;
    int dott;
    int i;
    std::string ans;
    {
        dots=0;
        for (i=s.size()-1; i>=0; --i)
            if (s[i]=='.')
                break;
            else
                ++dots;
        if (dots<s.size())
            s.erase(i, 1);
        else
            dots=0;

        dott=0;
        for (i=t.size()-1; i>=0; --i)
            if (t[i]=='.')
                break;
            else
                ++dott;
        if (dott<t.size())
            t.erase(i, 1);
        else
            dott=0;

        int dot=dots+dott;
        std::string ret=Multiply(s, t);
        s.clear(); t.clear();
        s=ret;
        if (s.size()!=1)
        {
            if (dot!=0)
            {
                std::reverse(s.begin(), s.end());
                while (s[0]=='0')
                {
                    s.erase(0,1);
                    --dot;
                }
                std::reverse(s.begin(), s.end());
            }
        }
        else
            if (s[0]=='0')
                dot=0;
        int idx=s.size()-dot;
        if (idx<0)
        {
            ans="0.";
            while (idx<0)
            {
                ans.push_back('0');
                ++idx;
            }
            idx=-1;
        }
        for (i=0; i<s.size(); ++i)
        {
            if (i==idx)
            {
                if (i==0)
                    ans.push_back('0');
                ans.push_back('.');
            }
            ans.push_back(s[i]);
        }
    }
    return ans;
}

std::string BigInteger::AddEx(std::string a, std::string b)
{
    std::string ah, ab;
    std::string bh, bb;

    int i;
    int size;

    std::string ans;
    {
        //a
        for (i=0; i<a.size(); ++i)
            if (a[i]=='.')
                break;
        ah=a.substr(0, i);
        if (i<a.size())
            ab=a.substr(i+1);
        a.clear();

        //b
        for (i=0; i<b.size(); ++i)
            if (b[i]=='.')
                break;
        bh=b.substr(0, i);
        if (i<b.size())
            bb=b.substr(i+1);
        b.clear();

        a=Add(ah, bh);
        ah.clear(); bh.clear();

        size=(ab.size()<bb.size() ? bb.size() : ab.size());
        if (ab.size()<size)
        {
            int n=size-ab.size();
            while (n--)
                ab.push_back('0');
        }
        if (bb.size()<size)
        {
            int n=size-bb.size();
            while (n--)
                bb.push_back('0');
        }
        b=Add(ab, bb);
        ab.clear(); bb.clear();

        if (b.size()>size)
        {
            std::string c;
            c.push_back(b[0]);
            b.erase(0,1);
            a=Add(a, c);
        }
        else if (b.size()<size)
        {
            int n=size-b.size();
            while (n--)
                b="0"+b;
        }

        std::reverse(b.begin(), b.end());
        while (!b.empty()&&b[0]=='0')
            b.erase(0, 1);
        std::reverse(b.begin(), b.end());

        ans=a;
        if (!b.empty())
            ans.push_back('.');
        ans.append(b);
    }
    return ans;
}

BigInteger BigInteger::signMinuse(const BigInteger& l, const BigInteger& r)
{
    BigInteger ret;
    if (l.m_sign && r.m_sign)
        ret.m_str=MinusEx(l.m_str, r.m_str, ret.m_sign);
    else if (!l.m_sign && !r.m_sign)
    {
        ret.m_str=MinusEx(l.m_str, r.m_str, ret.m_sign);
        ret.m_sign=!ret.m_sign;
    }
    else if (l.m_sign && !r.m_sign)
    {
        ret.m_str=AddEx(l.m_str, r.m_str);
        ret.m_sign=true;
    }
    else
    {
        ret.m_str=AddEx(l.m_str, r.m_str);
        ret.m_sign=false;
    }
    if (ret.m_str=="0")
        ret.m_sign=true;
    return ret;
}

std::string BigInteger::Minuss (std::string lbs, std::string rbs, bool& sign)
{
    int* g_lbs;
    int* g_rbs;
    int* g_result;
    char buffer[10];
    //调整
    int lenLbs=lbs.length();
    int lenRbs=rbs.length();
    sign=true;
    if (lenLbs<lenRbs)
        sign=false;
    else if (lenLbs==lenRbs)
    {
        sign=(lbs>=rbs);
        if (!sign)
        {
            std::swap(lbs, rbs);
            std::swap(lenLbs, lenRbs);
        }
    }

    if (lenLbs<lenRbs)
    {
        std::swap(lbs, rbs);
        std::swap(lenLbs, lenRbs);
    }
    //初始化数组
    int sizeLbs=lenLbs%4==0?lenLbs/4:lenLbs/4+1;
    int sizeRbs=lenRbs%4==0?lenRbs/4:lenRbs/4+1;
    g_lbs=new int[sizeLbs];
    g_rbs=new int[sizeRbs];
    int i,j;
    memset(g_lbs, 0, sizeof(int)*sizeLbs);
    memset(g_rbs, 0, sizeof(int)*sizeRbs);
    std::string str;
    //字符串到数组转化
    int count=0;
    while (lbs.length()>=4)
    {
        str=lbs.substr(lbs.length()-4);
        lbs.erase(lbs.length()-4);
        g_lbs[count]=atoi(str.c_str());
        ++count;
    }
    if (!lbs.empty())
    {
        str=lbs;
        lbs.clear();
        g_lbs[count]=atoi(str.c_str());
    }
    count=0;
    while (rbs.length()>=4)
    {
        str=rbs.substr(rbs.length()-4);
        rbs.erase(rbs.length()-4);
        g_rbs[count]=atoi(str.c_str());
        ++count;
    }
    if (!rbs.empty())
    {
        str=rbs;
        rbs.clear();
        g_rbs[count]=atoi(str.c_str());
    }
    //初始化结果数组
    g_result=new int[sizeLbs+1];
    memset(g_result, 0, sizeof(int)*(sizeLbs+1));
    //加法运算
    for (j=0; j<sizeLbs; ++j)
    {
        if (j<sizeRbs)
        {
            if (g_lbs[j]-g_rbs[j]<0)
            {
                --g_lbs[j+1];
                g_lbs[j]+=10000;
            }
            g_result[j]=g_lbs[j]-g_rbs[j];
        }
        else
        {
            if (g_lbs[j]<0)
            {
                --g_lbs[j+1];
                g_lbs[j]+=10000;
            }
            g_result[j]=g_lbs[j];
        }
    }
    //输出
    std::string ret;
    i=sizeLbs;
    while (!g_result[i])
    {
        --i;
        if (i==-1)
        {
            ret.append("0");
            goto leave;
        }
    }
    sprintf(buffer, "%d", g_result[i--]);
    ret.append(buffer);
    for (j=i; j>=0; --j)
    {
        if (g_result[j]<1000)
        {
            ret.append("0");
        }
        if (g_result[j]<100)
        {
            ret.append("0");
        }
        if (g_result[j]<10)
        {
            ret.append("0");
        }
        sprintf(buffer, "%d", g_result[j]);
        ret.append(buffer);
    }
leave:
    delete[] g_lbs;
    delete[] g_rbs;
    delete[] g_result;
    return ret;
}

std::string BigInteger::MinusEx(std::string a, std::string b, bool& sign)
{
    std::string ah, ab;
    std::string bh, bb;

    int i;
    int size;

    std::string ans;
    {
        sign=true;
        if (Compare(a, b)==-1)
        {
            a.swap(b);
            sign=false;
        }
        //a
        for (i=0; i<a.size(); ++i)
            if (a[i]=='.')
                break;
        ah=a.substr(0, i);
        if (i<a.size())
            ab=a.substr(i+1);
        a.clear();

        //b
        for (i=0; i<b.size(); ++i)
            if (b[i]=='.')
                break;
        bh=b.substr(0, i);
        if (i<b.size())
            bb=b.substr(i+1);
        b.clear();

        bool f;
        a=Minuss(ah, bh, f);
        ah.clear(); bh.clear();

        size=(ab.size()<bb.size() ? bb.size() : ab.size());
        if (ab.size()<size)
        {
            int n=size-ab.size();
            while (n--)
                ab.push_back('0');
        }
        if (bb.size()<size)
        {
            int n=size-bb.size();
            while (n--)
                bb.push_back('0');
        }

        if (ab<bb)
        {
            if (a!="0")
            {
                a=Minuss(a, "1", f);
                ab="1"+ab;
                b=Minuss(ab, bb, f);
            }
            else
                b=Minuss(ab, bb, f);
        }
        else
            b=Minuss(ab, bb, f);
        ab.clear(); bb.clear();

        if (b.size()<size)
        {
            int n=size-b.size();
            while (n--)
                b="0"+b;
        }

        std::reverse(b.begin(), b.end());
        while (!b.empty()&&b[0]=='0')
            b.erase(0, 1);
        std::reverse(b.begin(), b.end());

        ans=a;
        if (!b.empty())
            ans.push_back('.');
        ans.append(b);
    }

    return ans;
}

int BigInteger::signCompare(const BigInteger& a, const BigInteger& b)
{
    if (a.m_sign && b.m_sign)
        return Compare(a.m_str, b.m_str);
    else if (!a.m_sign && !b.m_sign)
    {
        int ret=Compare(a.m_str, b.m_str);
        if (ret!=0)
            ret=0-ret;
        return ret;
    }
    else 
        return a.m_sign ? a.m_sign : b.m_sign;
}

int BigInteger::Compare(const std::string& a, const std::string& b)
{
    std::string ah, ab;
    std::string bh, bb;
    int i;

    for (i=0; i<a.size(); ++i)
        if (a[i]=='.')
            break;
    ah=a.substr(0, i);
    ab.clear();
    if (i<a.size())
        ab=a.substr(i+1);

    for (i=0; i<b.size(); ++i)
        if (b[i]=='.')
            break;
    bh=b.substr(0, i);
    bb.clear();
    if (i<b.size())
        bb=b.substr(i+1);

    if (ah.size()<bh.size())
        return -1;
    else if (ah.size()>bh.size())
        return 1;
    else
    {
        if (ah<bh)
            return -1;
        else if (ah>bh)
            return 1;
        else
        {
            if (ab<bb)
                return -1;
            else if (ab>bb)
                return 1;
            else
                return 0;
        }
    }
}

//大整数乘方运算
std::string BigInteger::pow(const std::string& b, int n)
{
    if ( n==1 )
    {
        return b;
    }
    else 
    {
        if ( n%2==0 )
        {
            std::string t=pow(b,n/2);
            return MultiplyEx(t, t);
        }
        else
        {
            std::string t=pow(b,n/2);
            return MultiplyEx(MultiplyEx(t,t),b);
        }
    }
}

//测试程序
int main(int argc, char* argv[])
{
    //usage
    //std::cout<<"Input any number:\n";
    BigInteger a, b;

    while(cin>>a>>b)
    cout<<a*b<<std::endl;
/*cout<<"a+b="<<a+b<<std::endl;
    cout<<"a-b="<<a-b<<std::endl;
cout<<"Input one of normal positive integer number:\n";
    int n;
cin>>a>>n;
cout<<"a^n="<<(a^n)<<std::endl;
cout<<"All integer number: \n";
cin>>a>>b;
cout<<"a%b="<<(a%b)<<std::endl;
    if (a<b)
        cout<<"a less b\n";
    else
    cout<<"a not less b\n";
    if (a==b)
        cout<<"a equal b\n";
    else
        cout<<"a not equal b\n";*/
    return 0;
}
[ Copy to Clipboard ]    [ Save to File]    [ Print ]

