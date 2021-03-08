#ifndef BASE_UTILS_BU_TIME_DEF_H
#define BASE_UTILS_BU_TIME_DEF_H


#include <chrono>
#include <string>

/**                         Suport Macro
 *******************************************************************/


/**                         Time Record
 *******************************************************************/


namespace base_utils {

    class Watch {
    public:
        /** \brief Constructor. */
        Watch() : start_time_(std::chrono::steady_clock::now()) {
        }

        /** \brief Retrieve the time in milliseconds spent since the last call to \a reset(). */
        inline double
        getTime() const {
            auto end_time = std::chrono::steady_clock::now();
            return std::chrono::duration<double, std::ratio<1, 1000>>(end_time - start_time_).count();
        }

        /** \brief Retrieve the time in seconds spent since the last call to \a reset(). */
        inline double
        getTimeSeconds() const {
            return (getTime() * 0.001);
        }

        /** \brief Reset the stopwatch to 0. */
        inline void
        reset() {
            start_time_ = std::chrono::steady_clock::now();
        }

    protected:
        std::chrono::time_point<std::chrono::steady_clock> start_time_;
    };


    class ScopeTime : public Watch {
    public:

        inline ScopeTime(const std::string &_title = "",
                         double *_time_ref = nullptr, size_t *_times = nullptr, const char _end = '\0') :
                title_(_title), time_ref_(_time_ref), times_(_times), end_(_end) {
        }

        inline ~ScopeTime() {
            double val = this->getTime();
            if (time_ref_) {
                *time_ref_ += val;
                val = *time_ref_ / ++(*times_);
            }
            printf(BU_ANSI_CLEAR_LINE BU_ANSI_C(8, (FG, YELLOW, H)) BU_ANSI_BOLD  "> "
                   BU_ANSI_NONE "%s""%s took"
                   BU_ANSI_C(8, (FG, RED, H)) " %-5.1lfms%c"
                   BU_ANSI_NONE,
                   title_.c_str(), time_ref_ ? " average" : "", val, end_);
        }

    private:
        std::string title_;
        double *time_ref_;
        size_t *times_;
        char end_;
    };
}


#endif //BASE_UTILS_BU_TIME_DEF_H
