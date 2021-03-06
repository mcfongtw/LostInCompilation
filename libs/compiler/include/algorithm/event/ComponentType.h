//
// Created by Michael Fong on 2016/11/19.
//

#ifndef LOSTINCOMPILATION_COMPONENT_H
#define LOSTINCOMPILATION_COMPONENT_H

/**
 * Each element represents for an internal component for a compiler, including
 * - Parser
 * - Analyzer
 * - Symbol Binding
 */
enum ComponentType {
    COMPONENT_PARSER,
    COMPONENT_ANALYZER,
    COMPONENT_INTEPRETER,
    COMPONENT_COMPILER,
    COMPONENT_BINDING,
    COMPONENT_UNKNOWN
};

#endif //LOSTINCOMPILATION_COMPONENT_H
