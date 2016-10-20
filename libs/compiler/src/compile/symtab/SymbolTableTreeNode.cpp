//
// Created by Michael Fong on 2016/10/20.
//

#include "compile/symtab/SymbolTableTreeNode.h"

SymbolTableTreeNode::SymbolTableTreeNode() : SimpleSymbolTable(), TreeNode() {

}

SymbolTableTreeNode::SymbolTableTreeNode(SymbolScope scope) : SimpleSymbolTable(scope), TreeNode() {

}

SymbolTableTreeNode::~SymbolTableTreeNode() {

}