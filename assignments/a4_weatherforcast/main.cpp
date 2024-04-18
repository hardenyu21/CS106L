/* 
Assignment 4: Weather Forecast

This assignment works with template functions and lambdas to become the best weather forecaster
at the Stanford Daily. Be sure to read the assignment details in the PDF.

Submit to Paperless by 11:59pm on 2/16/2024.
*/

// TODO: import anything from the STL that might be useful!
#include <iostream>
#include <vector>
#include <concepts>
#include <numeric>
#include <algorithm>
#include <fstream>


// TODO: write convert_f_to_c function here. Remember it must be a template function that always returns
// a double.
// [function definition here]
template<typename T>
concept Numerical = std::is_arithmetic_v<T>;

template <Numerical T> 
double convert_f_to_c(T temp){
   return static_cast<double> (temp - 32.0) * 5.0 / 9.0;
}

template<typename Function>
std::vector<double> get_forecast(std::vector<std::vector<int>> readings, Function fn) {
    // TODO: write get_forecast here!
    std::vector<double> forecast;
    for(size_t i = 0; i < readings.size(); i++){
        std::vector<int> vec = readings[i];
        forecast.push_back(fn(vec));
    }
    return forecast;
}

int main() {
    std::vector<std::vector<int>> readings = {
        {70, 75, 80, 85, 90},
        {60, 65, 70, 75, 80},
        {50, 55, 60, 65, 70},
        {40, 45, 50, 55, 60},
        {30, 35, 40, 45, 50},
        {50, 55, 61, 65, 70},
        {40, 45, 50, 55, 60}
    };

    std::ofstream ofs("assignments/a4_weatherforcast/output.txt");
    ofs << std::fixed << std::setprecision(2);
    ofs << "Converted temperature: " << "\n";
    // TODO: Convert temperatures to Celsius and output to output.txt
    for (const auto vec : readings) {
       for (const auto temp: vec){
           ofs << convert_f_to_c(temp) << " ";
       }
       ofs << "\n";
    }

    
    std::vector<double> max_forecast;
    std::vector<double> min_forecast;
    std::vector<double> average_forecast;
    // TODO: Find the maximum temperature for each day and output to output.txt
    auto max_temp = [](const std::vector<int> vec) -> double {
        auto max_elem_iter = std::max_element(vec.begin(), vec.end());
        double max_value = *max_elem_iter;
        return max_value;
    };
    max_forecast = get_forecast(readings, max_temp);
    ofs << "Max temperature: " ;
    for (auto forcast: max_forecast){
        ofs << forcast << " ";
    }
    ofs << "\n";
    // TODO: Find the minimum temperature for each day and output to output.txt
    auto min_temp = [](const std::vector<int> vec) -> double {
        auto min_elem_iter = std::min_element(vec.begin(), vec.end());
        double min_value = *min_elem_iter;
        return min_value;
    };
    min_forecast = get_forecast(readings, min_temp);
    ofs << "Min temperature: " ;
    for (auto forcast: min_forecast){
        ofs << forcast << " ";
    }
    ofs << "\n";
    // TODO: Find the average temperature for each day and output to output.txt
    auto average_temp = [](const std::vector<int> vec) -> double {
        double average_value = std::accumulate(vec.begin(), vec.end(), 0) / static_cast<double> (vec.size());
        return average_value;
    };
    average_forecast = get_forecast(readings, average_temp);
    ofs << "Average temperature: " ;
    for (auto forcast: average_forecast){
        ofs << forcast << " ";
    }
    return 0;

}