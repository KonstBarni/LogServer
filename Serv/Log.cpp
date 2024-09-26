#include "Log.h"

Log::Log()
{
    time_t rowtime;
    tm* ptm;
    std::stringstream out;

    time(&rowtime);
    ptm = localtime(&rowtime);
    out << 1900+(ptm->tm_year) << "-" << ptm->tm_mon << "-" << ptm->tm_mday << " "
        << ptm->tm_hour << ":" << ptm->tm_min << ":" << ptm->tm_sec << "." 
        << std::chrono::duration_cast<std::chrono::milliseconds>
        (std::chrono::system_clock::now().time_since_epoch()).count() % 1000;

    getline(out, this->date);

}

void Log::showTime()
{
    std::cout << this->date << std::endl;
}