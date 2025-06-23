/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.

 2) revise the 'else' statement in main() that handles when `smaller` is a nullptr. 
 there is only one reason for `compare` to return nullptr. 
 Update this std::cout expression to specify why nullptr was returned.
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(int v, const char* n):   //1
    value(v),name(n)
    {}

    int value;//2
    std::string name;//3
};

struct CompareStruct                                //4
{
    T* compare(T* a, T* b) //5
    {
        if( a->value < b->value ) return a;
        if( a->value > b->value ) return b;
        return nullptr;
    }
};

struct U
{
    float v1 { 0 }, v2 { 0 };
    float unsharedMemberFunction(float* updateValueAddress)      //12
    {
        if (updateValueAddress != nullptr)
            {
                std::cout << "U's v1 value: " << this->v1 << std::endl;
                this->v1 = *updateValueAddress;
                std::cout << "U's v1 updated value: " << this->v1 << std::endl;
                while( std::abs(this->v2 - this->v1) > 0.001f )
                {
                    /*
                     write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
                     */
                    this->v2 += 0.5f;
                }
                std::cout << "U's v2 updated value: " << this->v2 << std::endl;
                return this->v2 * this->v1;
            }
            return 0.0f;
    }
};

struct StaticFunctionStruct
{
    static float staticSharedFunction(U* that, float* updateValueAddress)        //10
    {

        if (that != nullptr && updateValueAddress != nullptr)
        {
            std::cout << "U's v1 value: " << that->v1 << std::endl;
            that->v1 = *updateValueAddress;
            std::cout << "U's v1 updated value: " << that->v1 << std::endl;
            while( std::abs(that->v2 - that->v1) > 0.001f )
            {
                /*
                 write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
                 */
                that->v2 += 0.5f;
            }
            std::cout << "U's v2 updated value: " << that->v2 << std::endl;
            return that->v2 * that->v1;
        }
        return 0.0f;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    const char* t1name = "a";
    const char* t2name = "b";
    T t1(5, t1name);                                             //6
    T t2(6, t2name);                                             //6
    T* t1ptr = &t1;
    T* t2ptr = &t2;
    
    CompareStruct f;                                            //7
    auto* smaller = f.compare(t1ptr, t2ptr);                              //8
    
    if (smaller != nullptr)
    {
        std::cout << "the smaller one is: " << smaller->name << std::endl; //9    
    }
    else
    {
        std::cout << "there is no smaller one, so it returned nullptr" << std::endl; //9
    }
    
    U u1;
    U* u1ptr = &u1;
    float updatedValue = 5.f;

    if( u1ptr != nullptr)
    {
        std::cout << "[static func] u1's multiplied values: " << StaticFunctionStruct::staticSharedFunction(u1ptr, &updatedValue) << std::endl;                  //11
    }
    
    
    U u2;
    std::cout << "[member func] u2's multiplied values: " << u2.unsharedMemberFunction( &updatedValue ) << std::endl;
}
