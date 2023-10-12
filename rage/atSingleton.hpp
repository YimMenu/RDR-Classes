#pragma once

namespace rage
{
    template <typename T>
    class atSingleton 
    {
    public:
        static T& getInstance() 
        {
            return m_instance;
        }

        bool isValid() const 
        {
            return m_instance != nullptr;
        }

        atSingleton(const atSingleton&) = delete;
        atSingleton& operator=(const atSingleton&) = delete;

    protected:
        atSingleton() = default;
        virtual ~atSingleton() = default;

    private:
        static T m_instance;
    };
}