//
// Created by Michael Fong on 2/11/17.
//

#ifndef LOSTINCOMPILATION_METRICSERVICE_H
#define LOSTINCOMPILATION_METRICSERVICE_H

#include "algorithm/event/listener/EventListener.h"

/**
 *
 * MetricsManager inherits from EventReceivedListener and implements the concrete functionalities
 * for recording internal metrics after receiving an event. MetricsManager is a singleton design
 * that there is only one global instance that handles all types of metrics.
 *
 * Currently supported event include
 * 1) # of parsing error
 *
 * @since 0.1
 */
class MetricsManager : public EventReceivedListener {

public:
    virtual std::string toString();

    static EventListenerPtr getInstance();

    virtual int getParsingErrorCount();

protected:

    virtual void onReceived(Event event);

    int _parsing_error_count = 0;
private :

    static EventListenerPtr INSTANCE;
};


#endif //LOSTINCOMPILATION_METRICSERVICE_H
