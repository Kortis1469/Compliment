#include <type_traits>
#include "basicTypes.h"

class angle{
    private:
        double value;
        void biasValue();
    public:
        operator double() const;
        template <typename T>
        void operator=(const T& a);
        
        angle operator+(const angle& a);
        angle operator-(const  angle& a);
        angle operator*(const  angle& a);
        angle operator/(const  angle& a);
        bool operator<(const  angle& a) const;
        bool operator>(const  angle& a) const;
        bool operator<=(const angle& a) const;
        bool operator>=(const angle& a) const;
        bool operator==(const angle& a) const;

};

template <typename T>
inline void angle::operator=(const T &a)
{
    if constexpr (std::is_same_v<T, angle>) {
        this->value = a.value;  
    }
    else{
        this->value = static_cast<double>(a);
    }
    biasValue();
}
