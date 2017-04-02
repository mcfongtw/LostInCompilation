<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>
<tagfile>
  <compound kind="file">
    <name>ComponentType.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/include/algorithm/event/</path>
    <filename>ComponentType_8h</filename>
    <member kind="enumeration">
      <type></type>
      <name>ComponentType</name>
      <anchorfile>ComponentType_8h.html</anchorfile>
      <anchor>a81f78fc173dedefe5a049c0aa3eed2c0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>COMPONENT_PARSER</name>
      <anchorfile>ComponentType_8h.html</anchorfile>
      <anchor>a81f78fc173dedefe5a049c0aa3eed2c0ad708553bd62ac0c378d612a34a237a89</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>COMPONENT_ANALYZER</name>
      <anchorfile>ComponentType_8h.html</anchorfile>
      <anchor>a81f78fc173dedefe5a049c0aa3eed2c0ae166e39bd13d57519f38ce5f2a074813</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>COMPONENT_INTEPRETER</name>
      <anchorfile>ComponentType_8h.html</anchorfile>
      <anchor>a81f78fc173dedefe5a049c0aa3eed2c0aa82205fc0de8c0e5b55510ad4fdb7a43</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>COMPONENT_COMPILER</name>
      <anchorfile>ComponentType_8h.html</anchorfile>
      <anchor>a81f78fc173dedefe5a049c0aa3eed2c0a3348a4cb26ce87fe0b5af27da3f06b53</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>COMPONENT_BINDING</name>
      <anchorfile>ComponentType_8h.html</anchorfile>
      <anchor>a81f78fc173dedefe5a049c0aa3eed2c0a097a67039a86d8d9723b222eee4a1e8e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>COMPONENT_UNKNOWN</name>
      <anchorfile>ComponentType_8h.html</anchorfile>
      <anchor>a81f78fc173dedefe5a049c0aa3eed2c0ae0dd59d6c62e8979ad03d614b7508de4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>InternalEvent.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/include/algorithm/event/</path>
    <filename>InternalEvent_8h</filename>
    <includes id="ComponentType_8h" name="ComponentType.h" local="yes" imported="no">algorithm/event/ComponentType.h</includes>
    <class kind="class">InternalEvent</class>
    <class kind="class">ParserEvent</class>
    <class kind="class">AnalyzerEvent</class>
    <class kind="class">SymbolBindingEvent</class>
  </compound>
  <compound kind="file">
    <name>ASTNode.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/include/algorithm/tree/ast/</path>
    <filename>ASTNode_8h</filename>
    <includes id="SourceCodePosition_8h" name="SourceCodePosition.h" local="yes" imported="no">compile/SourceCodePosition.h</includes>
    <class kind="class">ASTNode</class>
    <member kind="typedef">
      <type>ASTNode *</type>
      <name>ASTNodePtr</name>
      <anchorfile>ASTNode_8h.html</anchorfile>
      <anchor>ad51b339b5c2b5d6d46c0e1d737ccdd3c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ASTUtils.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/include/algorithm/tree/ast/</path>
    <filename>ASTUtils_8h</filename>
    <includes id="ASTNode_8h" name="ASTNode.h" local="yes" imported="no">algorithm/tree/ast/ASTNode.h</includes>
    <class kind="class">ASTUtils</class>
  </compound>
  <compound kind="file">
    <name>DataBindingUtils.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/include/compile/binding/</path>
    <filename>DataBindingUtils_8h</filename>
    <class kind="class">DataBindingUtils</class>
  </compound>
  <compound kind="file">
    <name>DataValueHolder.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/include/compile/binding/</path>
    <filename>DataValueHolder_8h</filename>
    <includes id="ValueHolder_8h" name="ValueHolder.h" local="yes" imported="no">compile/binding/ValueHolder.h</includes>
  </compound>
  <compound kind="file">
    <name>RuntimeData.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/include/compile/binding/</path>
    <filename>RuntimeData_8h</filename>
    <includes id="DataBindingUtils_8h" name="DataBindingUtils.h" local="yes" imported="no">compile/binding/DataBindingUtils.h</includes>
    <includes id="ValueHolder_8h" name="ValueHolder.h" local="yes" imported="no">compile/binding/ValueHolder.h</includes>
    <class kind="class">RuntimeData</class>
    <class kind="class">RuntimeData::DataValueHolder</class>
  </compound>
  <compound kind="file">
    <name>ValueHolder.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/include/compile/binding/</path>
    <filename>ValueHolder_8h</filename>
    <includes id="RuntimeData_8h" name="RuntimeData.h" local="yes" imported="no">compile/binding/RuntimeData.h</includes>
    <class kind="class">ValueHolder</class>
  </compound>
  <compound kind="file">
    <name>Compilable.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/include/compile/</path>
    <filename>Compilable_8h</filename>
    <class kind="class">Compilable</class>
  </compound>
  <compound kind="file">
    <name>Evaluator.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/include/compile/eval/</path>
    <filename>Evaluator_8h</filename>
    <includes id="ASTNode_8h" name="ASTNode.h" local="yes" imported="no">algorithm/tree/ast/ASTNode.h</includes>
    <class kind="class">Evaluator</class>
  </compound>
  <compound kind="file">
    <name>Interpretable.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/include/compile/</path>
    <filename>Interpretable_8h</filename>
    <class kind="class">Interpretable</class>
  </compound>
  <compound kind="file">
    <name>Parser.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/include/compile/parser/</path>
    <filename>Parser_8h</filename>
    <includes id="ASTNode_8h" name="ASTNode.h" local="yes" imported="no">algorithm/tree/ast/ASTNode.h</includes>
    <class kind="class">Parsable</class>
  </compound>
  <compound kind="file">
    <name>SourceCodePosition.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/include/compile/</path>
    <filename>SourceCodePosition_8h</filename>
    <class kind="class">SourceCodePosition</class>
  </compound>
  <compound kind="file">
    <name>RuntimeStack.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/include/compile/symtab/</path>
    <filename>RuntimeStack_8h</filename>
    <includes id="RuntimeData_8h" name="RuntimeData.h" local="yes" imported="no">compile/binding/RuntimeData.h</includes>
    <class kind="class">RuntimeStack</class>
  </compound>
  <compound kind="file">
    <name>ScopedSymbolTable.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/include/compile/symtab/</path>
    <filename>ScopedSymbolTable_8h</filename>
    <includes id="SymbolRepository_8h" name="SymbolRepository.h" local="yes" imported="no">compile/symtab/SymbolRepository.h</includes>
    <class kind="class">ScopedSymbolTable</class>
    <member kind="typedef">
      <type>ScopedSymbolTable *</type>
      <name>SymbolTablePtr</name>
      <anchorfile>ScopedSymbolTable_8h.html</anchorfile>
      <anchor>a369bbacf0d6ff542aa4c2ce93dd22cd7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>SymbolScope</name>
      <anchorfile>ScopedSymbolTable_8h.html</anchorfile>
      <anchor>a3fe761f243c83b8d2828b7f75f9fcc58</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>SCOPE_GLOBAL</name>
      <anchorfile>ScopedSymbolTable_8h.html</anchorfile>
      <anchor>a3fe761f243c83b8d2828b7f75f9fcc58ae8e9210011c34fb548688d6cd9426cd8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>SCOPE_FUNCTIONAL</name>
      <anchorfile>ScopedSymbolTable_8h.html</anchorfile>
      <anchor>a3fe761f243c83b8d2828b7f75f9fcc58a3f86e8be75017a8fbdd9d34434517ded</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>SCOPE_FUNCTIONAL_ANONYMOUS</name>
      <anchorfile>ScopedSymbolTable_8h.html</anchorfile>
      <anchor>a3fe761f243c83b8d2828b7f75f9fcc58a88b80e2680ddb84f4d90607580029080</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>SCOPE_LOCAL</name>
      <anchorfile>ScopedSymbolTable_8h.html</anchorfile>
      <anchor>a3fe761f243c83b8d2828b7f75f9fcc58af828bc82c537119c89b55d2db41ec75b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>SimpleSymbolTable.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/include/compile/symtab/</path>
    <filename>SimpleSymbolTable_8h</filename>
    <includes id="Symbol_8h" name="Symbol.h" local="yes" imported="no">compile/symtab/Symbol.h</includes>
    <includes id="VisitedSymbolTable_8h" name="VisitedSymbolTable.h" local="yes" imported="no">compile/symtab/visitor/VisitedSymbolTable.h</includes>
    <class kind="class">SimpleSymbolTable</class>
    <member kind="typedef">
      <type>SimpleSymbolTable *</type>
      <name>SimpleSymbolTablePtr</name>
      <anchorfile>SimpleSymbolTable_8h.html</anchorfile>
      <anchor>a4ff01bd19c2282b3faab38879b71d74b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>Symbol.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/include/compile/symtab/</path>
    <filename>Symbol_8h</filename>
    <includes id="RuntimeData_8h" name="RuntimeData.h" local="yes" imported="no">compile/binding/RuntimeData.h</includes>
    <class kind="class">Symbol</class>
    <member kind="typedef">
      <type>Symbol *</type>
      <name>SymbolPtr</name>
      <anchorfile>Symbol_8h.html</anchorfile>
      <anchor>adaa88bee2f5595eeab528874065e0cf7</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>SymbolRepository.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/include/compile/symtab/</path>
    <filename>SymbolRepository_8h</filename>
    <includes id="Symbol_8h" name="Symbol.h" local="no" imported="no">compile/symtab/Symbol.h</includes>
    <class kind="class">SymbolRepository</class>
  </compound>
  <compound kind="file">
    <name>SymbolTableFactory.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/include/compile/symtab/</path>
    <filename>SymbolTableFactory_8h</filename>
    <includes id="ScopedSymbolTable_8h" name="ScopedSymbolTable.h" local="yes" imported="no">compile/symtab/ScopedSymbolTable.h</includes>
    <class kind="class">SymbolTableFactory</class>
    <member kind="enumeration">
      <type></type>
      <name>SymbolTableStrategy</name>
      <anchorfile>SymbolTableFactory_8h.html</anchorfile>
      <anchor>ad675952e9e0be72fbf62787cc14f0623</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ST_Simple</name>
      <anchorfile>SymbolTableFactory_8h.html</anchorfile>
      <anchor>ad675952e9e0be72fbf62787cc14f0623ac21d23d4aae36f227d8bd173f06ecd05</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ST_Tree</name>
      <anchorfile>SymbolTableFactory_8h.html</anchorfile>
      <anchor>ad675952e9e0be72fbf62787cc14f0623ab3779a22f2a299fb27235528590b5f99</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ST_Hash_Table</name>
      <anchorfile>SymbolTableFactory_8h.html</anchorfile>
      <anchor>ad675952e9e0be72fbf62787cc14f0623a9c7576622851a2f3d9ef51001b8f828c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>SymbolTableStack.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/include/compile/symtab/</path>
    <filename>SymbolTableStack_8h</filename>
    <includes id="ScopedSymbolTable_8h" name="ScopedSymbolTable.h" local="yes" imported="no">compile/symtab/ScopedSymbolTable.h</includes>
    <includes id="SymbolTableFactory_8h" name="SymbolTableFactory.h" local="yes" imported="no">SymbolTableFactory.h</includes>
    <class kind="class">SymbolTableStack</class>
    <member kind="typedef">
      <type>SymbolTableStack *</type>
      <name>SymTabStackPtr</name>
      <anchorfile>SymbolTableStack_8h.html</anchorfile>
      <anchor>a8b8fbe676cdf84d8b3f655d79e1ec004</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>SimpleSymbolTableVisitor.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/include/compile/symtab/visitor/</path>
    <filename>SimpleSymbolTableVisitor_8h</filename>
    <includes id="SymbolTableVisitor_8h" name="SymbolTableVisitor.h" local="yes" imported="no">compile/symtab/visitor/SymbolTableVisitor.h</includes>
    <class kind="class">SimpleSymbolTableVisitor</class>
    <member kind="typedef">
      <type>SimpleSymbolTableVisitor *</type>
      <name>SimpleSTVisitorPtr</name>
      <anchorfile>SimpleSymbolTableVisitor_8h.html</anchorfile>
      <anchor>ad6175c321d1bbd4d89ceda91260a892a</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>SymbolTableVisitor.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/include/compile/symtab/visitor/</path>
    <filename>SymbolTableVisitor_8h</filename>
    <includes id="ScopedSymbolTable_8h" name="ScopedSymbolTable.h" local="yes" imported="no">compile/symtab/ScopedSymbolTable.h</includes>
    <class kind="class">SymbolTableVisitor</class>
    <member kind="typedef">
      <type>SymbolTableVisitor *</type>
      <name>SymbolTableVisitorPtr</name>
      <anchorfile>SymbolTableVisitor_8h.html</anchorfile>
      <anchor>a4983cd5aa669c9dd5574a42304fc88c2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>VisitedSymbolTable.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/include/compile/symtab/visitor/</path>
    <filename>VisitedSymbolTable_8h</filename>
    <includes id="ScopedSymbolTable_8h" name="ScopedSymbolTable.h" local="yes" imported="no">compile/symtab/ScopedSymbolTable.h</includes>
    <class kind="class">VisitedSymbolTable</class>
  </compound>
  <compound kind="file">
    <name>ArithmeticException.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/include/error/</path>
    <filename>ArithmeticException_8h</filename>
    <class kind="class">ArithmeticException</class>
  </compound>
  <compound kind="file">
    <name>ParseException.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/include/error/</path>
    <filename>ParseException_8h</filename>
    <class kind="class">ParseException</class>
    <class kind="class">ParseExceptionTranslator</class>
  </compound>
  <compound kind="file">
    <name>SyntaxError.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/include/error/</path>
    <filename>SyntaxError_8h</filename>
    <includes id="ParseException_8h" name="ParseException.h" local="yes" imported="no">error/ParseException.h</includes>
    <class kind="class">SyntaxError</class>
  </compound>
  <compound kind="file">
    <name>Appender.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/include/tool/</path>
    <filename>Appender_8h</filename>
    <includes id="ASTNode_8h" name="ASTNode.h" local="yes" imported="no">algorithm/tree/ast/ASTNode.h</includes>
    <class kind="class">Appender</class>
    <class kind="class">ConsoleAppender</class>
    <class kind="class">StringAppender</class>
    <class kind="class">FileAppender</class>
    <member kind="typedef">
      <type>Appender *</type>
      <name>AppenderPtr</name>
      <anchorfile>Appender_8h.html</anchorfile>
      <anchor>ad206e80482a03c0961cc5b61b24e1c3d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>AsciiTreePrinter.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/include/tool/</path>
    <filename>AsciiTreePrinter_8h</filename>
    <includes id="ASTNode_8h" name="ASTNode.h" local="yes" imported="no">algorithm/tree/ast/ASTNode.h</includes>
    <includes id="Printer_8h" name="Printer.h" local="yes" imported="no">tool/Printer.h</includes>
    <class kind="class">AsciiTreePrinter</class>
  </compound>
  <compound kind="file">
    <name>DotTreePrinter.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/include/tool/</path>
    <filename>DotTreePrinter_8h</filename>
    <includes id="ASTNode_8h" name="ASTNode.h" local="yes" imported="no">algorithm/tree/ast/ASTNode.h</includes>
    <includes id="Printer_8h" name="Printer.h" local="yes" imported="no">tool/Printer.h</includes>
    <class kind="class">DotTreePrinter</class>
  </compound>
  <compound kind="file">
    <name>Printer.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/include/tool/</path>
    <filename>Printer_8h</filename>
    <includes id="Appender_8h" name="Appender.h" local="yes" imported="no">tool/Appender.h</includes>
    <class kind="class">Printer</class>
  </compound>
  <compound kind="file">
    <name>InternalEvent.cpp</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/src/algorithm/event/</path>
    <filename>InternalEvent_8cpp</filename>
    <includes id="InternalEvent_8h" name="InternalEvent.h" local="yes" imported="no">algorithm/event/InternalEvent.h</includes>
  </compound>
  <compound kind="file">
    <name>ASTNode.cpp</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/src/algorithm/tree/ast/</path>
    <filename>ASTNode_8cpp</filename>
    <includes id="ASTNode_8h" name="ASTNode.h" local="yes" imported="no">algorithm/tree/ast/ASTNode.h</includes>
  </compound>
  <compound kind="file">
    <name>ASTUtils.cpp</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/src/algorithm/tree/ast/</path>
    <filename>ASTUtils_8cpp</filename>
    <includes id="ASTUtils_8h" name="ASTUtils.h" local="yes" imported="no">algorithm/tree/ast/ASTUtils.h</includes>
  </compound>
  <compound kind="file">
    <name>DataBindingUtils.cpp</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/src/compile/binding/</path>
    <filename>DataBindingUtils_8cpp</filename>
    <includes id="DataBindingUtils_8h" name="DataBindingUtils.h" local="yes" imported="no">compile/binding/DataBindingUtils.h</includes>
  </compound>
  <compound kind="file">
    <name>DataValueHolder.cpp</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/src/compile/binding/</path>
    <filename>DataValueHolder_8cpp</filename>
  </compound>
  <compound kind="file">
    <name>RuntimeData.cpp</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/src/compile/binding/</path>
    <filename>RuntimeData_8cpp</filename>
    <includes id="RuntimeData_8h" name="RuntimeData.h" local="yes" imported="no">compile/binding/RuntimeData.h</includes>
  </compound>
  <compound kind="file">
    <name>SourceCodePosition.cpp</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/src/compile/</path>
    <filename>SourceCodePosition_8cpp</filename>
    <includes id="SourceCodePosition_8h" name="SourceCodePosition.h" local="yes" imported="no">compile/SourceCodePosition.h</includes>
  </compound>
  <compound kind="file">
    <name>RuntimeStack.cpp</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/src/compile/symtab/</path>
    <filename>RuntimeStack_8cpp</filename>
    <includes id="RuntimeStack_8h" name="RuntimeStack.h" local="yes" imported="no">compile/symtab/RuntimeStack.h</includes>
  </compound>
  <compound kind="file">
    <name>SimpleSymbolTable.cpp</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/src/compile/symtab/</path>
    <filename>SimpleSymbolTable_8cpp</filename>
    <includes id="SimpleSymbolTable_8h" name="SimpleSymbolTable.h" local="yes" imported="no">compile/symtab/SimpleSymbolTable.h</includes>
  </compound>
  <compound kind="file">
    <name>Symbol.cpp</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/src/compile/symtab/</path>
    <filename>Symbol_8cpp</filename>
    <includes id="Symbol_8h" name="Symbol.h" local="no" imported="no">compile/symtab/Symbol.h</includes>
  </compound>
  <compound kind="file">
    <name>SymbolTableFactory.cpp</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/src/compile/symtab/</path>
    <filename>SymbolTableFactory_8cpp</filename>
    <includes id="SymbolTableFactory_8h" name="SymbolTableFactory.h" local="yes" imported="no">compile/symtab/SymbolTableFactory.h</includes>
    <includes id="SimpleSymbolTable_8h" name="SimpleSymbolTable.h" local="yes" imported="no">compile/symtab/SimpleSymbolTable.h</includes>
  </compound>
  <compound kind="file">
    <name>SymbolTableStack.cpp</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/src/compile/symtab/</path>
    <filename>SymbolTableStack_8cpp</filename>
    <includes id="SymbolTableStack_8h" name="SymbolTableStack.h" local="yes" imported="no">compile/symtab/SymbolTableStack.h</includes>
  </compound>
  <compound kind="file">
    <name>SimpleSymbolTableVisitor.cpp</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/src/compile/symtab/visitor/</path>
    <filename>SimpleSymbolTableVisitor_8cpp</filename>
    <includes id="SimpleSymbolTableVisitor_8h" name="SimpleSymbolTableVisitor.h" local="yes" imported="no">compile/symtab/visitor/SimpleSymbolTableVisitor.h</includes>
  </compound>
  <compound kind="file">
    <name>ArithmeticException.cpp</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/src/error/</path>
    <filename>ArithmeticException_8cpp</filename>
    <includes id="ArithmeticException_8h" name="ArithmeticException.h" local="yes" imported="no">error/ArithmeticException.h</includes>
  </compound>
  <compound kind="file">
    <name>ParseException.cpp</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/src/error/</path>
    <filename>ParseException_8cpp</filename>
    <includes id="SyntaxError_8h" name="SyntaxError.h" local="yes" imported="no">error/SyntaxError.h</includes>
    <includes id="ParseException_8h" name="ParseException.h" local="yes" imported="no">error/ParseException.h</includes>
  </compound>
  <compound kind="file">
    <name>SyntaxError.cpp</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/src/error/</path>
    <filename>SyntaxError_8cpp</filename>
    <includes id="SyntaxError_8h" name="SyntaxError.h" local="yes" imported="no">error/SyntaxError.h</includes>
  </compound>
  <compound kind="file">
    <name>Appender.cpp</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/src/tool/</path>
    <filename>Appender_8cpp</filename>
    <includes id="Appender_8h" name="Appender.h" local="yes" imported="no">tool/Appender.h</includes>
  </compound>
  <compound kind="file">
    <name>AsciiTreePrinter.cpp</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/src/tool/</path>
    <filename>AsciiTreePrinter_8cpp</filename>
    <includes id="AsciiTreePrinter_8h" name="AsciiTreePrinter.h" local="yes" imported="no">tool/AsciiTreePrinter.h</includes>
  </compound>
  <compound kind="file">
    <name>DotTreePrinter.cpp</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/src/tool/</path>
    <filename>DotTreePrinter_8cpp</filename>
    <includes id="DotTreePrinter_8h" name="DotTreePrinter.h" local="yes" imported="no">tool/DotTreePrinter.h</includes>
  </compound>
  <compound kind="file">
    <name>Printer.cpp</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/compiler/src/tool/</path>
    <filename>Printer_8cpp</filename>
    <includes id="Printer_8h" name="Printer.h" local="yes" imported="no">tool/Printer.h</includes>
  </compound>
  <compound kind="class">
    <name>AnalyzerEvent</name>
    <filename>classAnalyzerEvent.html</filename>
    <base>InternalEvent</base>
    <member kind="function">
      <type></type>
      <name>AnalyzerEvent</name>
      <anchorfile>classAnalyzerEvent.html</anchorfile>
      <anchor>adcd213a60871851b7d9e948e84751acd</anchor>
      <arglist>(std::string summary, std::string msg)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~AnalyzerEvent</name>
      <anchorfile>classAnalyzerEvent.html</anchorfile>
      <anchor>a5070bd67738777f34c226d07fc10d47e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ComponentType</type>
      <name>getComponent</name>
      <anchorfile>classInternalEvent.html</anchorfile>
      <anchor>a4b0ea581d3cb441ed0d63c5b996aada6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ComponentType</type>
      <name>_component</name>
      <anchorfile>classInternalEvent.html</anchorfile>
      <anchor>a60ecc9e27d72c7be4eda3f51ffc03644</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Appender</name>
    <filename>classAppender.html</filename>
    <member kind="function">
      <type></type>
      <name>Appender</name>
      <anchorfile>classAppender.html</anchorfile>
      <anchor>adf07da85ab45ccc24ea22b1cc6373274</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Appender</name>
      <anchorfile>classAppender.html</anchorfile>
      <anchor>a3abd7f959fd249dc355fdd8168c50feb</anchor>
      <arglist>(const Appender &amp;that)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Appender</name>
      <anchorfile>classAppender.html</anchorfile>
      <anchor>a7194b4ff5130399352c356852023004d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>append</name>
      <anchorfile>classAppender.html</anchorfile>
      <anchor>a53919c10a1c7583eb5c099a13b8ebd49</anchor>
      <arglist>(const std::string &amp;msg)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>close</name>
      <anchorfile>classAppender.html</anchorfile>
      <anchor>af04d7d30603d76b01e3ba672951260e9</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="pure">
      <type>virtual void</type>
      <name>internalWrite</name>
      <anchorfile>classAppender.html</anchorfile>
      <anchor>a174fa9c233fed4b9fa73fecbe14bbe3c</anchor>
      <arglist>(const std::string &amp;msg)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ArithmeticException</name>
    <filename>classArithmeticException.html</filename>
    <base>Exception</base>
    <member kind="function">
      <type></type>
      <name>ArithmeticException</name>
      <anchorfile>classArithmeticException.html</anchorfile>
      <anchor>a7df4a4a575ae55124218fd653e0752da</anchor>
      <arglist>(const std::string &amp;msg)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ArithmeticException</name>
      <anchorfile>classArithmeticException.html</anchorfile>
      <anchor>a19624b6aae12a2d2dabfe96d5c123aac</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>AsciiTreePrinter</name>
    <filename>classAsciiTreePrinter.html</filename>
    <base>TreeWalker</base>
    <base>Printer</base>
    <member kind="function">
      <type></type>
      <name>AsciiTreePrinter</name>
      <anchorfile>classAsciiTreePrinter.html</anchorfile>
      <anchor>a7af114424acd9e833737b0887956ea9b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>AsciiTreePrinter</name>
      <anchorfile>classAsciiTreePrinter.html</anchorfile>
      <anchor>afc354435044831f820c01a33241f0527</anchor>
      <arglist>(AsciiTreePrinter &amp;that)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~AsciiTreePrinter</name>
      <anchorfile>classAsciiTreePrinter.html</anchorfile>
      <anchor>a833af1b0bb7aaf8c3c69fe97f24dc129</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>startWalking</name>
      <anchorfile>classAsciiTreePrinter.html</anchorfile>
      <anchor>a2363444f0f6ca576ed92d29d8f6407f9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>stopWalking</name>
      <anchorfile>classAsciiTreePrinter.html</anchorfile>
      <anchor>a535bed4e50236f59370e67d13060ba57</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>walk</name>
      <anchorfile>classAsciiTreePrinter.html</anchorfile>
      <anchor>a90c1322066d78f94632d8a208551b654</anchor>
      <arglist>(VisitedTreeNodePtr ptr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>addAppender</name>
      <anchorfile>classPrinter.html</anchorfile>
      <anchor>a60537a54e0a5503a1c23b2c52d909e11</anchor>
      <arglist>(AppenderPtr appender)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>write</name>
      <anchorfile>classPrinter.html</anchorfile>
      <anchor>a482d937cbb33686a5ce0c7c5bd68afe6</anchor>
      <arglist>(const std::string &amp;msg)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>closeAppenders</name>
      <anchorfile>classPrinter.html</anchorfile>
      <anchor>ad65a5a51dc17fb0d57551ba46791c640</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>std::vector&lt; AppenderPtr &gt;</type>
      <name>_appenderChain</name>
      <anchorfile>classPrinter.html</anchorfile>
      <anchor>a753cddf7c99b8f78a129b8bd65f015a9</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ASTNode</name>
    <filename>classASTNode.html</filename>
    <base>VisitedTreeNode</base>
    <member kind="function">
      <type></type>
      <name>ASTNode</name>
      <anchorfile>classASTNode.html</anchorfile>
      <anchor>a1196ed4f19c0b62cdc42fe35946b91d2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ASTNode</name>
      <anchorfile>classASTNode.html</anchorfile>
      <anchor>a47b225d2b07cd6310a255d1884bad478</anchor>
      <arglist>(const char *, int token)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ASTNode</name>
      <anchorfile>classASTNode.html</anchorfile>
      <anchor>a9332a800b1c096c3c0bbc859b3ec2118</anchor>
      <arglist>(const char *, int token, SourceCodePosition position)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ASTNode</name>
      <anchorfile>classASTNode.html</anchorfile>
      <anchor>a41a691f37fa038eb183280effeb8ba4e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setImage</name>
      <anchorfile>classASTNode.html</anchorfile>
      <anchor>a4a36a5760a05170cad5ded39953b626a</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual char *</type>
      <name>getText</name>
      <anchorfile>classASTNode.html</anchorfile>
      <anchor>a1c6d4143a8367e1c5ba84b30570f3f07</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::string</type>
      <name>getImage</name>
      <anchorfile>classASTNode.html</anchorfile>
      <anchor>a726ab4e7d66e418d24c2809f90e166c0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setToken</name>
      <anchorfile>classASTNode.html</anchorfile>
      <anchor>a977968bfb0d4c462e9acc84d71dd760a</anchor>
      <arglist>(int token)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>getToken</name>
      <anchorfile>classASTNode.html</anchorfile>
      <anchor>a43a26149f533357bf66598121bf40239</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual SourceCodePosition</type>
      <name>getPosition</name>
      <anchorfile>classASTNode.html</anchorfile>
      <anchor>a566981ed6df559b7ce85436a588c7e83</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>char *</type>
      <name>_text</name>
      <anchorfile>classASTNode.html</anchorfile>
      <anchor>ad6a78989759fed6279ca47eeacae5207</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>_token</name>
      <anchorfile>classASTNode.html</anchorfile>
      <anchor>a467bbbf8292e7865d95d1ff702a19c1d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>SourceCodePosition</type>
      <name>_pos</name>
      <anchorfile>classASTNode.html</anchorfile>
      <anchor>ac5482aaaffabce09ab8bf63c471a3010</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ASTUtils</name>
    <filename>classASTUtils.html</filename>
    <member kind="function" static="yes">
      <type>static int</type>
      <name>reduceTreeWithoutChildren</name>
      <anchorfile>classASTUtils.html</anchorfile>
      <anchor>a5e9891f7237ea21ea1059d2f205f2302</anchor>
      <arglist>(VisitedTreeNodePtr oldNode, VisitedTreeNodePtr newNode)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static int</type>
      <name>reduceTree</name>
      <anchorfile>classASTUtils.html</anchorfile>
      <anchor>a3185ba2235bddbd9a77a2cbc4fe55111</anchor>
      <arglist>(VisitedTreeNodePtr oldNode, VisitedTreeNodePtr newNode)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static ASTNode *</type>
      <name>createAST</name>
      <anchorfile>classASTUtils.html</anchorfile>
      <anchor>a33229b62ac0b7a65395c9a7f32e354e5</anchor>
      <arglist>(const char *txt, int tokenType, SourceCodePosition position)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static ASTNode *</type>
      <name>createAST</name>
      <anchorfile>classASTUtils.html</anchorfile>
      <anchor>a50dca8e54c4e2fa1bfadcc90b9ad3302</anchor>
      <arglist>(const char *txt, int tokenType, ASTNode *child, SourceCodePosition position)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static ASTNode *</type>
      <name>createAST</name>
      <anchorfile>classASTUtils.html</anchorfile>
      <anchor>a8b2e5414df844d3cd88a255639da5b48</anchor>
      <arglist>(const char *txt, int tokenType, ASTNode *child1, ASTNode *child2, SourceCodePosition position)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Compilable</name>
    <filename>classCompilable.html</filename>
    <member kind="function">
      <type></type>
      <name>Compilable</name>
      <anchorfile>classCompilable.html</anchorfile>
      <anchor>a263ae9a614cda787c1273fc59b95dc35</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Compilable</name>
      <anchorfile>classCompilable.html</anchorfile>
      <anchor>a06e407f99f69a73d97f03c27c6c1870b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual bool</type>
      <name>compile</name>
      <anchorfile>classCompilable.html</anchorfile>
      <anchor>a1d792f2ec4f52b0baf57fdcfb6ca02ab</anchor>
      <arglist>(std::string &amp;fname)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ConsoleAppender</name>
    <filename>classConsoleAppender.html</filename>
    <base>Appender</base>
    <member kind="function">
      <type></type>
      <name>ConsoleAppender</name>
      <anchorfile>classConsoleAppender.html</anchorfile>
      <anchor>a47659008483aea73f49f6e172a0249d7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ConsoleAppender</name>
      <anchorfile>classConsoleAppender.html</anchorfile>
      <anchor>a32e2c9693d70cd6851d569fa3cb51aac</anchor>
      <arglist>(const ConsoleAppender &amp;that)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ConsoleAppender</name>
      <anchorfile>classConsoleAppender.html</anchorfile>
      <anchor>a6e96b3deda7c57e59ce3a7885164cadd</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>close</name>
      <anchorfile>classConsoleAppender.html</anchorfile>
      <anchor>aba44ab7a2da42b471baeec482b5f1cfc</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>append</name>
      <anchorfile>classAppender.html</anchorfile>
      <anchor>a53919c10a1c7583eb5c099a13b8ebd49</anchor>
      <arglist>(const std::string &amp;msg)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>internalWrite</name>
      <anchorfile>classConsoleAppender.html</anchorfile>
      <anchor>a8e3d32560668a35dba53ae8c24eb8d8e</anchor>
      <arglist>(const std::string &amp;msg)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DataBindingUtils</name>
    <filename>classDataBindingUtils.html</filename>
    <member kind="function" static="yes">
      <type>static std::string</type>
      <name>toString</name>
      <anchorfile>classDataBindingUtils.html</anchorfile>
      <anchor>ad7ed78891bc4bf45b914f002d0ea13e1</anchor>
      <arglist>(const std::type_info &amp;type)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RuntimeData::DataValueHolder</name>
    <filename>classRuntimeData_1_1DataValueHolder.html</filename>
    <templarg>T</templarg>
    <base>ValueHolder</base>
    <member kind="function">
      <type></type>
      <name>DataValueHolder</name>
      <anchorfile>classRuntimeData_1_1DataValueHolder.html</anchorfile>
      <anchor>a96151bd055837ec2ffd74d15e2c81809</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DataValueHolder</name>
      <anchorfile>classRuntimeData_1_1DataValueHolder.html</anchorfile>
      <anchor>ae80b156f86abed71aa66ecb9f6fc88e7</anchor>
      <arglist>(const DataValueHolder &amp;that)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DataValueHolder</name>
      <anchorfile>classRuntimeData_1_1DataValueHolder.html</anchorfile>
      <anchor>a2fd61c01fade7c58c899e0ec204fecd2</anchor>
      <arglist>(const T &amp;val)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~DataValueHolder</name>
      <anchorfile>classRuntimeData_1_1DataValueHolder.html</anchorfile>
      <anchor>aa835d2789a4c80f41cf5ff188bcbf07f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const std::type_info &amp;</type>
      <name>getType</name>
      <anchorfile>classRuntimeData_1_1DataValueHolder.html</anchorfile>
      <anchor>a432202880dbb567baa266ecced283148</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual DataValueHolder *</type>
      <name>clone</name>
      <anchorfile>classRuntimeData_1_1DataValueHolder.html</anchorfile>
      <anchor>a1653c5138cfdf8e9275e6a1996600b61</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>equal</name>
      <anchorfile>classRuntimeData_1_1DataValueHolder.html</anchorfile>
      <anchor>ad9cdbfcbf3ff4f11c5bc37bd6b3e3ddb</anchor>
      <arglist>(RuntimeData obj)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const size_t</type>
      <name>getSizeof</name>
      <anchorfile>classRuntimeData_1_1DataValueHolder.html</anchorfile>
      <anchor>a2d70c1ebc7cc4d158f55456df3f082f9</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isInit</name>
      <anchorfile>classRuntimeData_1_1DataValueHolder.html</anchorfile>
      <anchor>ad4ca18405724cfc23cc1ea7808397d15</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="variable">
      <type>T</type>
      <name>_value</name>
      <anchorfile>classRuntimeData_1_1DataValueHolder.html</anchorfile>
      <anchor>a003a98f2b8cf2439fc421898f3bceeea</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>bool</type>
      <name>init</name>
      <anchorfile>classRuntimeData_1_1DataValueHolder.html</anchorfile>
      <anchor>ae440fb14c3f56c3790979c55f54462d3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DotTreePrinter</name>
    <filename>classDotTreePrinter.html</filename>
    <base>TreeWalker</base>
    <base>Printer</base>
    <member kind="function">
      <type></type>
      <name>DotTreePrinter</name>
      <anchorfile>classDotTreePrinter.html</anchorfile>
      <anchor>a58c60bbb880b9add292b912929fc91c3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DotTreePrinter</name>
      <anchorfile>classDotTreePrinter.html</anchorfile>
      <anchor>a91af49a58450f198555a4b4450269490</anchor>
      <arglist>(DotTreePrinter &amp;that)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~DotTreePrinter</name>
      <anchorfile>classDotTreePrinter.html</anchorfile>
      <anchor>a1e8e7f35d5b09bb7104efc8e6b6e951d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>startWalking</name>
      <anchorfile>classDotTreePrinter.html</anchorfile>
      <anchor>adba92dec6fc8e26c1e88003816afb955</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>stopWalking</name>
      <anchorfile>classDotTreePrinter.html</anchorfile>
      <anchor>ac8a9e473449df5f6622b330a8a3ff232</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>walk</name>
      <anchorfile>classDotTreePrinter.html</anchorfile>
      <anchor>ac839be72ce5d63f8be5585533a33935c</anchor>
      <arglist>(VisitedTreeNodePtr ptr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>addAppender</name>
      <anchorfile>classPrinter.html</anchorfile>
      <anchor>a60537a54e0a5503a1c23b2c52d909e11</anchor>
      <arglist>(AppenderPtr appender)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>write</name>
      <anchorfile>classPrinter.html</anchorfile>
      <anchor>a482d937cbb33686a5ce0c7c5bd68afe6</anchor>
      <arglist>(const std::string &amp;msg)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>closeAppenders</name>
      <anchorfile>classPrinter.html</anchorfile>
      <anchor>ad65a5a51dc17fb0d57551ba46791c640</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>std::vector&lt; AppenderPtr &gt;</type>
      <name>_appenderChain</name>
      <anchorfile>classPrinter.html</anchorfile>
      <anchor>a753cddf7c99b8f78a129b8bd65f015a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>int</type>
      <name>_nodeIdForDot</name>
      <anchorfile>classDotTreePrinter.html</anchorfile>
      <anchor>a510ec859603481eb118f3207a0201768</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Evaluator</name>
    <filename>classEvaluator.html</filename>
    <member kind="function">
      <type></type>
      <name>Evaluator</name>
      <anchorfile>classEvaluator.html</anchorfile>
      <anchor>ab0fae467aa1c3870f9cfb0c8368710be</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Evaluator</name>
      <anchorfile>classEvaluator.html</anchorfile>
      <anchor>aef091da4bfefb11d62104dfcccfc1220</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>startEval</name>
      <anchorfile>classEvaluator.html</anchorfile>
      <anchor>ad9ffe590a2ec97783a6f8fadeaddde52</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>doEval</name>
      <anchorfile>classEvaluator.html</anchorfile>
      <anchor>a24cdd05712c55c845eef83e75f644856</anchor>
      <arglist>(VisitedTreeNodePtr root)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>stopEval</name>
      <anchorfile>classEvaluator.html</anchorfile>
      <anchor>aef459743604cb6af0f29159c7f4d2858</anchor>
      <arglist>()=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>FileAppender</name>
    <filename>classFileAppender.html</filename>
    <base>Appender</base>
    <member kind="function">
      <type></type>
      <name>FileAppender</name>
      <anchorfile>classFileAppender.html</anchorfile>
      <anchor>ad39b9b9d4eac4ebd9fa92a4f03ebb3e5</anchor>
      <arglist>(const std::string &amp;fname)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>FileAppender</name>
      <anchorfile>classFileAppender.html</anchorfile>
      <anchor>a4f96013d65821ef64ceb9b348484b1d9</anchor>
      <arglist>(const FileAppender &amp;that)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~FileAppender</name>
      <anchorfile>classFileAppender.html</anchorfile>
      <anchor>a9430d0ff3c2cbcaad70bbac2a41e142c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>close</name>
      <anchorfile>classFileAppender.html</anchorfile>
      <anchor>a84f82ad0ae7953ab2659e9c63f9294cd</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>append</name>
      <anchorfile>classAppender.html</anchorfile>
      <anchor>a53919c10a1c7583eb5c099a13b8ebd49</anchor>
      <arglist>(const std::string &amp;msg)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>internalWrite</name>
      <anchorfile>classFileAppender.html</anchorfile>
      <anchor>ad05fbc88d3d9e032ab2597c23b6e3124</anchor>
      <arglist>(const std::string &amp;msg)</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::ofstream</type>
      <name>_fout</name>
      <anchorfile>classFileAppender.html</anchorfile>
      <anchor>adde79a9fdb7da72d32a25224eeec6432</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>InternalEvent</name>
    <filename>classInternalEvent.html</filename>
    <base>Event</base>
    <member kind="function">
      <type></type>
      <name>InternalEvent</name>
      <anchorfile>classInternalEvent.html</anchorfile>
      <anchor>a75b5de727c80cc81a2d86bd12c86037a</anchor>
      <arglist>(ComponentType comp, std::string summary, std::string msg)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~InternalEvent</name>
      <anchorfile>classInternalEvent.html</anchorfile>
      <anchor>a2a03021b2e5fa83a384936f9543ab53a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ComponentType</type>
      <name>getComponent</name>
      <anchorfile>classInternalEvent.html</anchorfile>
      <anchor>a4b0ea581d3cb441ed0d63c5b996aada6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ComponentType</type>
      <name>_component</name>
      <anchorfile>classInternalEvent.html</anchorfile>
      <anchor>a60ecc9e27d72c7be4eda3f51ffc03644</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Interpretable</name>
    <filename>classInterpretable.html</filename>
    <member kind="function">
      <type></type>
      <name>Interpretable</name>
      <anchorfile>classInterpretable.html</anchorfile>
      <anchor>a8dd6c449ceaaf60988d58c703ad946db</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Interpretable</name>
      <anchorfile>classInterpretable.html</anchorfile>
      <anchor>a12370de34ac0dd965d3fab7702732cc1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>startInterpret</name>
      <anchorfile>classInterpretable.html</anchorfile>
      <anchor>ad564024ad785156bc91be1320f73ecbc</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual RuntimeData</type>
      <name>interpret</name>
      <anchorfile>classInterpretable.html</anchorfile>
      <anchor>ab58725293749d4f800c3664edf415fbb</anchor>
      <arglist>(std::string &amp;line)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>stopInterpret</name>
      <anchorfile>classInterpretable.html</anchorfile>
      <anchor>ab525b760adfbf44b8e0cf1eddef3d812</anchor>
      <arglist>()=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Parsable</name>
    <filename>classParsable.html</filename>
    <member kind="function">
      <type></type>
      <name>Parsable</name>
      <anchorfile>classParsable.html</anchorfile>
      <anchor>ab8e4514a35b53e8ff85628780c815422</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Parsable</name>
      <anchorfile>classParsable.html</anchorfile>
      <anchor>a1e75b8656371405ece019bafd8a9f52b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>parse</name>
      <anchorfile>classParsable.html</anchorfile>
      <anchor>afd59c3151052967f44c6a6f0019db061</anchor>
      <arglist>(ASTNodePtr &amp;root, std::string line)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>parse</name>
      <anchorfile>classParsable.html</anchorfile>
      <anchor>a1d1e0542e25c319c7f917afba1a34242</anchor>
      <arglist>(std::ifstream inFile)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ParseException</name>
    <filename>classParseException.html</filename>
    <base>Exception</base>
    <member kind="function">
      <type></type>
      <name>ParseException</name>
      <anchorfile>classParseException.html</anchorfile>
      <anchor>a919b4176e1168034fa799bb3fdb2299d</anchor>
      <arglist>(const std::string &amp;prefix, const std::string &amp;msg, const bool includeStackTrace)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ParseException</name>
      <anchorfile>classParseException.html</anchorfile>
      <anchor>a4db094560c75ba83593d0a7c53d79c3a</anchor>
      <arglist>(const std::string &amp;msg, const bool includeStackTrace)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ParseException</name>
      <anchorfile>classParseException.html</anchorfile>
      <anchor>a013f9fef08198853282a501ab04ef54a</anchor>
      <arglist>(const std::string &amp;msg)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ParseException</name>
      <anchorfile>classParseException.html</anchorfile>
      <anchor>afc28de19b38cf2d40a0248b74477b1cf</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ParseExceptionTranslator</name>
    <filename>classParseExceptionTranslator.html</filename>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>translate</name>
      <anchorfile>classParseExceptionTranslator.html</anchorfile>
      <anchor>af7d4747bc0d23b4116af3b50e5217406</anchor>
      <arglist>(const std::string &amp;hint, const std::string &amp;message)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ParserEvent</name>
    <filename>classParserEvent.html</filename>
    <base>InternalEvent</base>
    <member kind="function">
      <type></type>
      <name>ParserEvent</name>
      <anchorfile>classParserEvent.html</anchorfile>
      <anchor>ab6819a3e380fe9f082b20d3e87f60e55</anchor>
      <arglist>(std::string summary, std::string msg)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ParserEvent</name>
      <anchorfile>classParserEvent.html</anchorfile>
      <anchor>af98b80667834e8c073e3313357156caf</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ComponentType</type>
      <name>getComponent</name>
      <anchorfile>classInternalEvent.html</anchorfile>
      <anchor>a4b0ea581d3cb441ed0d63c5b996aada6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ComponentType</type>
      <name>_component</name>
      <anchorfile>classInternalEvent.html</anchorfile>
      <anchor>a60ecc9e27d72c7be4eda3f51ffc03644</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Printer</name>
    <filename>classPrinter.html</filename>
    <member kind="function">
      <type></type>
      <name>Printer</name>
      <anchorfile>classPrinter.html</anchorfile>
      <anchor>a1aba91ebff40aebda570d92f17f28b27</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Printer</name>
      <anchorfile>classPrinter.html</anchorfile>
      <anchor>a011da1d2aa31df5440071c0b6e80eb1d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Printer</name>
      <anchorfile>classPrinter.html</anchorfile>
      <anchor>ab4a0d01b25845fb598f696f185afa6a4</anchor>
      <arglist>(Printer &amp;that)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>addAppender</name>
      <anchorfile>classPrinter.html</anchorfile>
      <anchor>a60537a54e0a5503a1c23b2c52d909e11</anchor>
      <arglist>(AppenderPtr appender)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>write</name>
      <anchorfile>classPrinter.html</anchorfile>
      <anchor>a482d937cbb33686a5ce0c7c5bd68afe6</anchor>
      <arglist>(const std::string &amp;msg)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>closeAppenders</name>
      <anchorfile>classPrinter.html</anchorfile>
      <anchor>ad65a5a51dc17fb0d57551ba46791c640</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>std::vector&lt; AppenderPtr &gt;</type>
      <name>_appenderChain</name>
      <anchorfile>classPrinter.html</anchorfile>
      <anchor>a753cddf7c99b8f78a129b8bd65f015a9</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RuntimeData</name>
    <filename>classRuntimeData.html</filename>
    <class kind="class">RuntimeData::DataValueHolder</class>
    <member kind="function">
      <type></type>
      <name>RuntimeData</name>
      <anchorfile>classRuntimeData.html</anchorfile>
      <anchor>a778b94ec5b7de2e7da55eb271826ec69</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RuntimeData</name>
      <anchorfile>classRuntimeData.html</anchorfile>
      <anchor>a912edf1201b6171c738feb1479b6e0f5</anchor>
      <arglist>(const T &amp;val)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RuntimeData</name>
      <anchorfile>classRuntimeData.html</anchorfile>
      <anchor>a0b2545a53d94991b953b181aaecb7e7b</anchor>
      <arglist>(const RuntimeData &amp;obj)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~RuntimeData</name>
      <anchorfile>classRuntimeData.html</anchorfile>
      <anchor>ab89c44c643ba9c22fe88f2618b57d1a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>const std::type_info &amp;</type>
      <name>getType</name>
      <anchorfile>classRuntimeData.html</anchorfile>
      <anchor>a6dbc4f2d6d757d6ee6a2aeb008aea302</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>const size_t</type>
      <name>getSizeof</name>
      <anchorfile>classRuntimeData.html</anchorfile>
      <anchor>ac8ca9b6a5f4841b75133f321e6b0efcc</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>get</name>
      <anchorfile>classRuntimeData.html</anchorfile>
      <anchor>a600d2c0d5aa8885c9a17889f776ba44e</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>RuntimeData &amp;</type>
      <name>swap</name>
      <anchorfile>classRuntimeData.html</anchorfile>
      <anchor>a55611e93b6b90cd995fd7f064f35fe2d</anchor>
      <arglist>(RuntimeData &amp;that)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isNull</name>
      <anchorfile>classRuntimeData.html</anchorfile>
      <anchor>a30ce7ecb5e6da502c9ec43f25979d7cb</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>long</type>
      <name>hashCode</name>
      <anchorfile>classRuntimeData.html</anchorfile>
      <anchor>a38f8e954575fa8f7cefd969b4cb57a72</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>toString</name>
      <anchorfile>classRuntimeData.html</anchorfile>
      <anchor>aed4111e8de3e9888d02c7b741aab451b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>equals</name>
      <anchorfile>classRuntimeData.html</anchorfile>
      <anchor>a3aebe6c667b309a3e2d73586a3312cf1</anchor>
      <arglist>(RuntimeData &amp;that)</arglist>
    </member>
    <member kind="function">
      <type>RuntimeData &amp;</type>
      <name>operator=</name>
      <anchorfile>classRuntimeData.html</anchorfile>
      <anchor>a8f685fe27c96eb67c876f34cb7da87d2</anchor>
      <arglist>(const RuntimeData &amp;that)</arglist>
    </member>
    <member kind="function">
      <type>RuntimeData &amp;</type>
      <name>operator=</name>
      <anchorfile>classRuntimeData.html</anchorfile>
      <anchor>a6f10d5ae0065ab5d73e15b459d5e4072</anchor>
      <arglist>(const T &amp;val)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>classRuntimeData.html</anchorfile>
      <anchor>a33b904f9298ee6e447aa71aa5f85dad5</anchor>
      <arglist>(const RuntimeData &amp;that) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>classRuntimeData.html</anchorfile>
      <anchor>af3aeea813ac55943ee15dc8c51536b94</anchor>
      <arglist>(const T val) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>classRuntimeData.html</anchorfile>
      <anchor>a0cc0e9bef27d354249213f0b09bc8590</anchor>
      <arglist>(const RuntimeData &amp;that) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>classRuntimeData.html</anchorfile>
      <anchor>aec0d5f8378d402c172548f0fb5cae02e</anchor>
      <arglist>(const T val) const </arglist>
    </member>
    <member kind="variable" protection="private">
      <type>ValueHolder *</type>
      <name>_holder</name>
      <anchorfile>classRuntimeData.html</anchorfile>
      <anchor>a21b9ecdd65ce2ad9a1a30971da25c963</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RuntimeStack</name>
    <filename>classRuntimeStack.html</filename>
    <member kind="function">
      <type></type>
      <name>RuntimeStack</name>
      <anchorfile>classRuntimeStack.html</anchorfile>
      <anchor>a6effad5e405343e54f697c7595cfeeac</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~RuntimeStack</name>
      <anchorfile>classRuntimeStack.html</anchorfile>
      <anchor>a75ace2b329dbd110782ef4947c5f305c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>pop</name>
      <anchorfile>classRuntimeStack.html</anchorfile>
      <anchor>aa0fef76079923a64a70fa8d628b1e754</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>RuntimeData &amp;</type>
      <name>top</name>
      <anchorfile>classRuntimeStack.html</anchorfile>
      <anchor>a8b6e80ccca40a8445d1c7329248d19e8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>push</name>
      <anchorfile>classRuntimeStack.html</anchorfile>
      <anchor>a6319e59126409898d8929d83c8eafd41</anchor>
      <arglist>(RuntimeData &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isEmpty</name>
      <anchorfile>classRuntimeStack.html</anchorfile>
      <anchor>a636235a9101ca313cc231f5fb5567096</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>size_t</type>
      <name>size</name>
      <anchorfile>classRuntimeStack.html</anchorfile>
      <anchor>a628f9bc8c22a66ddcdf75ef424c50253</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>RuntimeData &amp;</type>
      <name>operator[]</name>
      <anchorfile>classRuntimeStack.html</anchorfile>
      <anchor>a3542c00623773c05f18273835e011a77</anchor>
      <arglist>(std::size_t index)</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>toString</name>
      <anchorfile>classRuntimeStack.html</anchorfile>
      <anchor>a6495bebbe9cdd605575f9e0b88a017bf</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::vector&lt; RuntimeData &gt;</type>
      <name>_stack</name>
      <anchorfile>classRuntimeStack.html</anchorfile>
      <anchor>ac6276386fda9f53fdf6ac1da31f27698</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ScopedSymbolTable</name>
    <filename>classScopedSymbolTable.html</filename>
    <base>SymbolRepository</base>
    <member kind="function">
      <type></type>
      <name>ScopedSymbolTable</name>
      <anchorfile>classScopedSymbolTable.html</anchorfile>
      <anchor>aabc0e24d4ad5cf5b5574f990f771044a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ScopedSymbolTable</name>
      <anchorfile>classScopedSymbolTable.html</anchorfile>
      <anchor>af271d9e5ca37b6938703f98670ed1dd9</anchor>
      <arglist>(SymbolScope scope)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>remove</name>
      <anchorfile>classScopedSymbolTable.html</anchorfile>
      <anchor>aacb3ce09f105db1d3c39a8e7b74adbd5</anchor>
      <arglist>(const std::string &amp;name)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual SymbolPtr</type>
      <name>lookup</name>
      <anchorfile>classScopedSymbolTable.html</anchorfile>
      <anchor>aa005744ff64fd5639486e0af4d27b23b</anchor>
      <arglist>(const std::string &amp;name)=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setScope</name>
      <anchorfile>classScopedSymbolTable.html</anchorfile>
      <anchor>a687841b518c3b2d0aaa141352db22a2c</anchor>
      <arglist>(SymbolScope scope)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual SymbolScope</type>
      <name>getScope</name>
      <anchorfile>classScopedSymbolTable.html</anchorfile>
      <anchor>a9d1b97529c738261cdc57474cf7359e6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>add</name>
      <anchorfile>classSymbolRepository.html</anchorfile>
      <anchor>a25403e537c60aff789440593b14bb081</anchor>
      <arglist>(SymbolPtr ptr)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>remove</name>
      <anchorfile>classSymbolRepository.html</anchorfile>
      <anchor>ab0342a2dd053bc0dc281e742b0be15ff</anchor>
      <arglist>(SymbolPtr ptr)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual bool</type>
      <name>isEmpty</name>
      <anchorfile>classSymbolRepository.html</anchorfile>
      <anchor>ad08a8b39180878d7d908c5f729eef9ae</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual std::string</type>
      <name>toString</name>
      <anchorfile>classSymbolRepository.html</anchorfile>
      <anchor>a7a0fe23b5145248833981f3cbebefc57</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>SymbolScope</type>
      <name>_scope</name>
      <anchorfile>classScopedSymbolTable.html</anchorfile>
      <anchor>a163d22c5d72c0f77e6ba80370d618435</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SimpleSymbolTable</name>
    <filename>classSimpleSymbolTable.html</filename>
    <base>VisitedSymbolTable</base>
    <member kind="function">
      <type></type>
      <name>SimpleSymbolTable</name>
      <anchorfile>classSimpleSymbolTable.html</anchorfile>
      <anchor>a2d03ed04c4618aad5edccab13130b306</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>SimpleSymbolTable</name>
      <anchorfile>classSimpleSymbolTable.html</anchorfile>
      <anchor>af8549997ae0780cb6f6bce3edd04b863</anchor>
      <arglist>(SymbolScope lvl)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~SimpleSymbolTable</name>
      <anchorfile>classSimpleSymbolTable.html</anchorfile>
      <anchor>abfb72274536108e2ee57e17fb97a8417</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>add</name>
      <anchorfile>classSimpleSymbolTable.html</anchorfile>
      <anchor>a9c3ecc63b89d91b5bbb06fec365dd2f2</anchor>
      <arglist>(SymbolPtr ptr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>remove</name>
      <anchorfile>classSimpleSymbolTable.html</anchorfile>
      <anchor>a8723494a5e606c1d7e4b26ad76366b78</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>remove</name>
      <anchorfile>classSimpleSymbolTable.html</anchorfile>
      <anchor>af0e0f777979286a3ea86d31856787771</anchor>
      <arglist>(SymbolPtr ptr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual SymbolPtr</type>
      <name>lookup</name>
      <anchorfile>classSimpleSymbolTable.html</anchorfile>
      <anchor>aebab5c212b028e69981f6cfa8e96bab9</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::string</type>
      <name>toString</name>
      <anchorfile>classSimpleSymbolTable.html</anchorfile>
      <anchor>aa48bc3bb567a5b314db523f2a9513e32</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isEmpty</name>
      <anchorfile>classSimpleSymbolTable.html</anchorfile>
      <anchor>a143480b05f14692a9ae5c8010c610351</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>accept</name>
      <anchorfile>classSimpleSymbolTable.html</anchorfile>
      <anchor>af5cf2c420ea19f7befacb1f6b3b6a805</anchor>
      <arglist>(VisitorPtr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setScope</name>
      <anchorfile>classScopedSymbolTable.html</anchorfile>
      <anchor>a687841b518c3b2d0aaa141352db22a2c</anchor>
      <arglist>(SymbolScope scope)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual SymbolScope</type>
      <name>getScope</name>
      <anchorfile>classScopedSymbolTable.html</anchorfile>
      <anchor>a9d1b97529c738261cdc57474cf7359e6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>std::map&lt; std::string, SymbolPtr &gt;</type>
      <name>symbol_map</name>
      <anchorfile>classSimpleSymbolTable.html</anchorfile>
      <anchor>a16c427de6121e03a53283474a5ff9301</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>SymbolScope</type>
      <name>_scope</name>
      <anchorfile>classScopedSymbolTable.html</anchorfile>
      <anchor>a163d22c5d72c0f77e6ba80370d618435</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SimpleSymbolTableVisitor</name>
    <filename>classSimpleSymbolTableVisitor.html</filename>
    <base>SymbolTableVisitor</base>
    <member kind="function">
      <type></type>
      <name>SimpleSymbolTableVisitor</name>
      <anchorfile>classSimpleSymbolTableVisitor.html</anchorfile>
      <anchor>a940c1df12f9d2bb2f58eb42a7fcbacb0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~SimpleSymbolTableVisitor</name>
      <anchorfile>classSimpleSymbolTableVisitor.html</anchorfile>
      <anchor>a8fc35e876a592e935de67f34845ac482</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual SymbolPtr</type>
      <name>lookup</name>
      <anchorfile>classSimpleSymbolTableVisitor.html</anchorfile>
      <anchor>a1854d363f79d7d77167399de9772707a</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>visit</name>
      <anchorfile>classSimpleSymbolTableVisitor.html</anchorfile>
      <anchor>a8f7709b1d2565df696356498aab62a18</anchor>
      <arglist>(SymbolTablePtr)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual int</type>
      <name>startVisit</name>
      <anchorfile>classSimpleSymbolTableVisitor.html</anchorfile>
      <anchor>a1dd63f65efa36789dcb02ad8475e85be</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual int</type>
      <name>stopVisit</name>
      <anchorfile>classSimpleSymbolTableVisitor.html</anchorfile>
      <anchor>a7ef036e3a701e55427e12b4b5f027e9b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual int</type>
      <name>visit</name>
      <anchorfile>classSymbolTableVisitor.html</anchorfile>
      <anchor>a8cace10ecbb0dc365a8e1e7b7ebeb833</anchor>
      <arglist>(VisitedObjectPtr ptr)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>SymbolTablePtr</type>
      <name>_current</name>
      <anchorfile>classSimpleSymbolTableVisitor.html</anchorfile>
      <anchor>ae78f455d96b5d86366c3f0a70c1a3017</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SourceCodePosition</name>
    <filename>classSourceCodePosition.html</filename>
    <member kind="function">
      <type></type>
      <name>SourceCodePosition</name>
      <anchorfile>classSourceCodePosition.html</anchorfile>
      <anchor>a297a866b150bb0011e8fb113512b5ef6</anchor>
      <arglist>(int row, int col)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>SourceCodePosition</name>
      <anchorfile>classSourceCodePosition.html</anchorfile>
      <anchor>a3ef013b79ecd2f492742c5e4eaeaa91d</anchor>
      <arglist>(int col)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>SourceCodePosition</name>
      <anchorfile>classSourceCodePosition.html</anchorfile>
      <anchor>a2b1216cf6671c77b22b8cc6b7041f46b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~SourceCodePosition</name>
      <anchorfile>classSourceCodePosition.html</anchorfile>
      <anchor>ae6f21ac58dd4017b9bc69699b3b4f8d5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>getRow</name>
      <anchorfile>classSourceCodePosition.html</anchorfile>
      <anchor>a3805c7b522b2e408abac0d9a4fcddb62</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>getCol</name>
      <anchorfile>classSourceCodePosition.html</anchorfile>
      <anchor>a810b20dbf52b88e2e84a6b41be8b3274</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::string</type>
      <name>toString</name>
      <anchorfile>classSourceCodePosition.html</anchorfile>
      <anchor>a82d00605164d12ec3a8c192157e48e10</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>int</type>
      <name>_col</name>
      <anchorfile>classSourceCodePosition.html</anchorfile>
      <anchor>a1c4fdf72a2fc1e4e334dac5863a41072</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>int</type>
      <name>_row</name>
      <anchorfile>classSourceCodePosition.html</anchorfile>
      <anchor>aa3113c8f838dd1f8d367bd45690456b4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>StringAppender</name>
    <filename>classStringAppender.html</filename>
    <base>Appender</base>
    <member kind="function">
      <type></type>
      <name>StringAppender</name>
      <anchorfile>classStringAppender.html</anchorfile>
      <anchor>a9bf3be83d702d6c19ad0c4d3487155da</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>StringAppender</name>
      <anchorfile>classStringAppender.html</anchorfile>
      <anchor>af67b504b4fac875977c2d01beb983e53</anchor>
      <arglist>(const StringAppender &amp;that)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~StringAppender</name>
      <anchorfile>classStringAppender.html</anchorfile>
      <anchor>a7e3ee1c2218289fbb9768db6b5cdb5a8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::string</type>
      <name>toString</name>
      <anchorfile>classStringAppender.html</anchorfile>
      <anchor>aea5101e39f24292ab60bf4e42e10452b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>close</name>
      <anchorfile>classStringAppender.html</anchorfile>
      <anchor>af619e7c0201950319401195e8ee60c99</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>append</name>
      <anchorfile>classAppender.html</anchorfile>
      <anchor>a53919c10a1c7583eb5c099a13b8ebd49</anchor>
      <arglist>(const std::string &amp;msg)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>internalWrite</name>
      <anchorfile>classStringAppender.html</anchorfile>
      <anchor>aa614fb15a26de8c140e7ad82fc2b0f0b</anchor>
      <arglist>(const std::string &amp;msg)</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::stringstream</type>
      <name>_ss</name>
      <anchorfile>classStringAppender.html</anchorfile>
      <anchor>a00bf0f0c3297a7cc139a1183bee6c939</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Symbol</name>
    <filename>classSymbol.html</filename>
    <member kind="function">
      <type></type>
      <name>Symbol</name>
      <anchorfile>classSymbol.html</anchorfile>
      <anchor>a3519e65dc6ef2fdaea56df01d48b20ba</anchor>
      <arglist>(std::string name)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Symbol</name>
      <anchorfile>classSymbol.html</anchorfile>
      <anchor>ac51449f58f2ad9a323df0601573a0a98</anchor>
      <arglist>(std::string name, RuntimeData val)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Symbol</name>
      <anchorfile>classSymbol.html</anchorfile>
      <anchor>a505360ad4bd2e0bd1e3954eca1b05723</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::string &amp;</type>
      <name>getName</name>
      <anchorfile>classSymbol.html</anchorfile>
      <anchor>acadfeecce5b0bbceb63613c5c8c8c59d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual RuntimeData &amp;</type>
      <name>getValue</name>
      <anchorfile>classSymbol.html</anchorfile>
      <anchor>ae84e0e0c6b5ad48cc5664bfd87cdb0ae</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setValue</name>
      <anchorfile>classSymbol.html</anchorfile>
      <anchor>abe88f9e4c3cf058a1c88df220663dcfa</anchor>
      <arglist>(RuntimeData val)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::string</type>
      <name>toString</name>
      <anchorfile>classSymbol.html</anchorfile>
      <anchor>af5ccb3fb3201fd88ab6ce0e495416c82</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>std::string</type>
      <name>_name</name>
      <anchorfile>classSymbol.html</anchorfile>
      <anchor>a0a9fd28800188734d6a5d46dfeb0883c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>RuntimeData</type>
      <name>_value</name>
      <anchorfile>classSymbol.html</anchorfile>
      <anchor>a5c592e97d2d80158b47b40c622bb9754</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SymbolBindingEvent</name>
    <filename>classSymbolBindingEvent.html</filename>
    <base>InternalEvent</base>
    <member kind="function">
      <type></type>
      <name>SymbolBindingEvent</name>
      <anchorfile>classSymbolBindingEvent.html</anchorfile>
      <anchor>a729883c155ea10f6e72d0b975d6b0069</anchor>
      <arglist>(std::string summary, std::string msg)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~SymbolBindingEvent</name>
      <anchorfile>classSymbolBindingEvent.html</anchorfile>
      <anchor>ab98047feaf07def9a04bde533f8038df</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ComponentType</type>
      <name>getComponent</name>
      <anchorfile>classInternalEvent.html</anchorfile>
      <anchor>a4b0ea581d3cb441ed0d63c5b996aada6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ComponentType</type>
      <name>_component</name>
      <anchorfile>classInternalEvent.html</anchorfile>
      <anchor>a60ecc9e27d72c7be4eda3f51ffc03644</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SymbolRepository</name>
    <filename>classSymbolRepository.html</filename>
    <member kind="function">
      <type></type>
      <name>SymbolRepository</name>
      <anchorfile>classSymbolRepository.html</anchorfile>
      <anchor>acd9920db09d36188aa9375ce9a407766</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~SymbolRepository</name>
      <anchorfile>classSymbolRepository.html</anchorfile>
      <anchor>ac3b7f9c3247be9f694be4d96a71bbb0a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>add</name>
      <anchorfile>classSymbolRepository.html</anchorfile>
      <anchor>a25403e537c60aff789440593b14bb081</anchor>
      <arglist>(SymbolPtr ptr)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>remove</name>
      <anchorfile>classSymbolRepository.html</anchorfile>
      <anchor>ab0342a2dd053bc0dc281e742b0be15ff</anchor>
      <arglist>(SymbolPtr ptr)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual bool</type>
      <name>isEmpty</name>
      <anchorfile>classSymbolRepository.html</anchorfile>
      <anchor>ad08a8b39180878d7d908c5f729eef9ae</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual std::string</type>
      <name>toString</name>
      <anchorfile>classSymbolRepository.html</anchorfile>
      <anchor>a7a0fe23b5145248833981f3cbebefc57</anchor>
      <arglist>()=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SymbolTableFactory</name>
    <filename>classSymbolTableFactory.html</filename>
    <member kind="function" static="yes">
      <type>static SymbolTablePtr</type>
      <name>getSymbolTable</name>
      <anchorfile>classSymbolTableFactory.html</anchorfile>
      <anchor>aaf37cbd8ef20f403e7a91bda1251d194</anchor>
      <arglist>(SymbolTableStrategy)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static SymbolTablePtr</type>
      <name>getSymbolTable</name>
      <anchorfile>classSymbolTableFactory.html</anchorfile>
      <anchor>ae150efd3ee61e06ad640ab9532421ec4</anchor>
      <arglist>(SymbolTableStrategy, SymbolScope)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SymbolTableStack</name>
    <filename>classSymbolTableStack.html</filename>
    <base>VisitedObject</base>
    <base>SymbolRepository</base>
    <member kind="function">
      <type></type>
      <name>SymbolTableStack</name>
      <anchorfile>classSymbolTableStack.html</anchorfile>
      <anchor>a0abf0e3e33946a1823e7a3c533bc0a0c</anchor>
      <arglist>(SymbolTableStrategy strategy)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~SymbolTableStack</name>
      <anchorfile>classSymbolTableStack.html</anchorfile>
      <anchor>a65c05cdfe00dc74c69fe8bac32503fb4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>add</name>
      <anchorfile>classSymbolTableStack.html</anchorfile>
      <anchor>ac093cdc7b886a11361f46628c998a5e1</anchor>
      <arglist>(SymbolPtr ptr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>remove</name>
      <anchorfile>classSymbolTableStack.html</anchorfile>
      <anchor>aa8c26cf0ea220bbeeaf8755b874f98db</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>remove</name>
      <anchorfile>classSymbolTableStack.html</anchorfile>
      <anchor>aac11ff5412ec013793ce297212fcf9ef</anchor>
      <arglist>(SymbolPtr ptr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual SymbolPtr</type>
      <name>lookup</name>
      <anchorfile>classSymbolTableStack.html</anchorfile>
      <anchor>a97a3e74ac9c09cac5ac2f91f8cb63d2b</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::string</type>
      <name>toString</name>
      <anchorfile>classSymbolTableStack.html</anchorfile>
      <anchor>a887e1e24dee78cd25ca941a85e3e39f5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isEmpty</name>
      <anchorfile>classSymbolTableStack.html</anchorfile>
      <anchor>a882bd175bc711a77becdf65f72493560</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>accept</name>
      <anchorfile>classSymbolTableStack.html</anchorfile>
      <anchor>a97bcc18ddaac4dab55a8702aae3eb042</anchor>
      <arglist>(VisitorPtr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>openScope</name>
      <anchorfile>classSymbolTableStack.html</anchorfile>
      <anchor>a1f5d73f60a365182db78b2d89cb56dfb</anchor>
      <arglist>(SymbolScope scope)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>openScope</name>
      <anchorfile>classSymbolTableStack.html</anchorfile>
      <anchor>a0a1a941849c67f3880dc70ccb93a3a29</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>closeScope</name>
      <anchorfile>classSymbolTableStack.html</anchorfile>
      <anchor>a6d1ba8ee68afac356a63ceab170eaba8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>size</name>
      <anchorfile>classSymbolTableStack.html</anchorfile>
      <anchor>a87b6529074b68c12c67c3883da3d82f4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual SymbolScope</type>
      <name>getScope</name>
      <anchorfile>classSymbolTableStack.html</anchorfile>
      <anchor>a0d7a996dbda0cbbce4ccae8fe88a7f50</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::vector&lt; SymbolTablePtr &gt;</type>
      <name>_stack</name>
      <anchorfile>classSymbolTableStack.html</anchorfile>
      <anchor>a3ad075d77dd57b6216a12871d8470818</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>SymbolTablePtr</type>
      <name>_current</name>
      <anchorfile>classSymbolTableStack.html</anchorfile>
      <anchor>a5a0c9ef0507caa43e2aa78468a871af7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>SymbolTableStrategy</type>
      <name>_strategy</name>
      <anchorfile>classSymbolTableStack.html</anchorfile>
      <anchor>a06dadf34b498c9ab1444796b988f3e88</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SymbolTableVisitor</name>
    <filename>classSymbolTableVisitor.html</filename>
    <base>Visitor</base>
    <member kind="function">
      <type></type>
      <name>SymbolTableVisitor</name>
      <anchorfile>classSymbolTableVisitor.html</anchorfile>
      <anchor>a700efe3a0a2d96ba745b6ef38b21e62b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~SymbolTableVisitor</name>
      <anchorfile>classSymbolTableVisitor.html</anchorfile>
      <anchor>a13371a212be9426ef9c0a277b5002fee</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual SymbolPtr</type>
      <name>lookup</name>
      <anchorfile>classSymbolTableVisitor.html</anchorfile>
      <anchor>ab7ca7f0dbce5f7314bfc43c594f13078</anchor>
      <arglist>(const std::string &amp;name)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>visit</name>
      <anchorfile>classSymbolTableVisitor.html</anchorfile>
      <anchor>a49d7fc0237d05bb89b35b39acc720101</anchor>
      <arglist>(SymbolTablePtr)=0</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual int</type>
      <name>visit</name>
      <anchorfile>classSymbolTableVisitor.html</anchorfile>
      <anchor>a8cace10ecbb0dc365a8e1e7b7ebeb833</anchor>
      <arglist>(VisitedObjectPtr ptr)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="pure">
      <type>virtual int</type>
      <name>startVisit</name>
      <anchorfile>classSymbolTableVisitor.html</anchorfile>
      <anchor>a86068e9cf8bab3bbdbd8ec0c2762d33d</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="pure">
      <type>virtual int</type>
      <name>stopVisit</name>
      <anchorfile>classSymbolTableVisitor.html</anchorfile>
      <anchor>a760e1c268241b4b9b4a00850105752ee</anchor>
      <arglist>()=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SyntaxError</name>
    <filename>classSyntaxError.html</filename>
    <base>ParseException</base>
    <member kind="function">
      <type></type>
      <name>SyntaxError</name>
      <anchorfile>classSyntaxError.html</anchorfile>
      <anchor>a95a39044feb3a788f3960f3c05ecdde4</anchor>
      <arglist>(const std::string &amp;msg)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ValueHolder</name>
    <filename>classValueHolder.html</filename>
    <member kind="function">
      <type></type>
      <name>ValueHolder</name>
      <anchorfile>classValueHolder.html</anchorfile>
      <anchor>ad7d05df1aba8e391546e253aab762525</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ValueHolder</name>
      <anchorfile>classValueHolder.html</anchorfile>
      <anchor>a08e1dcf58fad30b9eca9696ab37fd962</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual const std::type_info &amp;</type>
      <name>getType</name>
      <anchorfile>classValueHolder.html</anchorfile>
      <anchor>a7b351357ae2d1869ce687a48b955aff9</anchor>
      <arglist>() const =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual ValueHolder *</type>
      <name>clone</name>
      <anchorfile>classValueHolder.html</anchorfile>
      <anchor>aa75fb63a8653ddbfc31e81cfba366fd8</anchor>
      <arglist>() const =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual bool</type>
      <name>equal</name>
      <anchorfile>classValueHolder.html</anchorfile>
      <anchor>af3f6c1c19406ffc6009c7f719715575a</anchor>
      <arglist>(RuntimeData)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual const size_t</type>
      <name>getSizeof</name>
      <anchorfile>classValueHolder.html</anchorfile>
      <anchor>acc9960f624caf54e09310d2abc718c30</anchor>
      <arglist>() const =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual bool</type>
      <name>isInit</name>
      <anchorfile>classValueHolder.html</anchorfile>
      <anchor>ad224388601910281f55d77142d38e2c2</anchor>
      <arglist>() const =0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>VisitedSymbolTable</name>
    <filename>classVisitedSymbolTable.html</filename>
    <base>ScopedSymbolTable</base>
    <base>VisitedObject</base>
    <member kind="function">
      <type></type>
      <name>VisitedSymbolTable</name>
      <anchorfile>classVisitedSymbolTable.html</anchorfile>
      <anchor>a98aa488e03c3817e52640effd9a0d8be</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>VisitedSymbolTable</name>
      <anchorfile>classVisitedSymbolTable.html</anchorfile>
      <anchor>ab475e3c91e3c0043f03865a5524e0cf9</anchor>
      <arglist>(SymbolScope lvl)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~VisitedSymbolTable</name>
      <anchorfile>classVisitedSymbolTable.html</anchorfile>
      <anchor>af7c9321ee3029579e7db1db963303db0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>remove</name>
      <anchorfile>classScopedSymbolTable.html</anchorfile>
      <anchor>aacb3ce09f105db1d3c39a8e7b74adbd5</anchor>
      <arglist>(const std::string &amp;name)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>remove</name>
      <anchorfile>classSymbolRepository.html</anchorfile>
      <anchor>ab0342a2dd053bc0dc281e742b0be15ff</anchor>
      <arglist>(SymbolPtr ptr)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual SymbolPtr</type>
      <name>lookup</name>
      <anchorfile>classScopedSymbolTable.html</anchorfile>
      <anchor>aa005744ff64fd5639486e0af4d27b23b</anchor>
      <arglist>(const std::string &amp;name)=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setScope</name>
      <anchorfile>classScopedSymbolTable.html</anchorfile>
      <anchor>a687841b518c3b2d0aaa141352db22a2c</anchor>
      <arglist>(SymbolScope scope)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual SymbolScope</type>
      <name>getScope</name>
      <anchorfile>classScopedSymbolTable.html</anchorfile>
      <anchor>a9d1b97529c738261cdc57474cf7359e6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>add</name>
      <anchorfile>classSymbolRepository.html</anchorfile>
      <anchor>a25403e537c60aff789440593b14bb081</anchor>
      <arglist>(SymbolPtr ptr)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual bool</type>
      <name>isEmpty</name>
      <anchorfile>classSymbolRepository.html</anchorfile>
      <anchor>ad08a8b39180878d7d908c5f729eef9ae</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual std::string</type>
      <name>toString</name>
      <anchorfile>classSymbolRepository.html</anchorfile>
      <anchor>a7a0fe23b5145248833981f3cbebefc57</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>SymbolScope</type>
      <name>_scope</name>
      <anchorfile>classScopedSymbolTable.html</anchorfile>
      <anchor>a163d22c5d72c0f77e6ba80370d618435</anchor>
      <arglist></arglist>
    </member>
  </compound>
</tagfile>
