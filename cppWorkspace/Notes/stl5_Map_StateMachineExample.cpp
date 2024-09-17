#include <iostream>
#include <unordered_map>


void print(std::unordered_map<std::string, std::string>& l_map);


enum class TrafficLightStatus {
    RED,
    YELLOW,
    GREEN
};
enum class TrafficLightTrigger {
    gotoRED,
    gotoYELLOW,
    gotoGREEN
};

int main() {
    std::unordered_map< TrafficLightStatus, std::pair<TrafficLightTrigger, TrafficLightStatus> > dB = {
        {GREEN, {gotoYELLOW, YELLOW}},
        {YELLOW, {gotoRED, RED}},
        {RED, {gotoGREEN, GREEN}}
    };

    TrafficLightStatus currentState = TrafficLightStatus::GREEN;

    return 0;
}

void print(std::unordered_map<std::string, std::string>& l_map) {
    
    for(auto it: l_map) {
        std::cout << it.first << ": " << it.second << std::endl;
    }
}