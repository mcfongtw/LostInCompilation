//
// Created by shannaracat on 2016/10/20.
//

#ifndef MAINPROJECT_HIERARCHICALSYMBOLTABLE_H
#define MAINPROJECT_HIERARCHICALSYMBOLTABLE_H

#include "algorithm/tree/TreeNode.h"
#include "compile/symtab/SimpleSymbolTable.h"

class SymbolTableTreeNode  : public SimpleSymbolTable, public TreeNode {
public:
    SymbolTableTreeNode();

    SymbolTableTreeNode(SymbolScope scope);

    virtual ~SymbolTableTreeNode();
};

typedef std::shared_ptr<SymbolTableTreeNode> HierarchicalSymbolTablePtr;


#endif //MAINPROJECT_HIERARCHICALSYMBOLTABLE_H
