#include "cli/MetricsManager.h"
#include <sstream>

// Allocating and initializing MetricsManager's
// static data member.  The pointer is being
// allocated - not the object inself.
EventListenerPtr MetricsManager::INSTANCE = 0;

EventListenerPtr MetricsManager::getInstance() {
    if(INSTANCE == 0) {
        INSTANCE = std::make_shared<MetricsManager>();
    }

    return INSTANCE;
}

std::string MetricsManager::toString() {
    std::stringstream ss;

    ss << "Parsing Error Count: " << this->_parsing_error_count << std::endl;

    return ss.str();
}

void MetricsManager::onReceived(Event event) {
    this->_parsing_error_count++;
}

int MetricsManager::getParsingErrorCount() {
    return this->_parsing_error_count;
}