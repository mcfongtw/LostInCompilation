<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>
<tagfile>
  <compound kind="file">
    <name>EventDispatcher.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/shacat/include/algorithm/event/dispatcher/</path>
    <filename>EventDispatcher_8h</filename>
    <includes id="Event_8h" name="Event.h" local="yes" imported="no">algorithm/event/Event.h</includes>
    <includes id="EventListener_8h" name="EventListener.h" local="yes" imported="no">algorithm/event/listener/EventListener.h</includes>
    <class kind="class">EventDispatcher</class>
  </compound>
  <compound kind="file">
    <name>Event.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/shacat/include/algorithm/event/</path>
    <filename>Event_8h</filename>
    <class kind="class">Event</class>
  </compound>
  <compound kind="file">
    <name>EventListener.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/shacat/include/algorithm/event/listener/</path>
    <filename>EventListener_8h</filename>
    <includes id="Event_8h" name="Event.h" local="yes" imported="no">algorithm/event/Event.h</includes>
    <class kind="class">EventListener</class>
    <class kind="class">EventReceivedListener</class>
    <class kind="class">EventSentListener</class>
    <member kind="typedef">
      <type>EventListener *</type>
      <name>EventListenerPtr</name>
      <anchorfile>EventListener_8h.html</anchorfile>
      <anchor>aa00bcda9123d0b7abe465e9c125b210a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>EventListenerType</name>
      <anchorfile>EventListener_8h.html</anchorfile>
      <anchor>a0fa812f40726abdb17ef8b98637b223b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>EVENT_RECEIVED</name>
      <anchorfile>EventListener_8h.html</anchorfile>
      <anchor>a0fa812f40726abdb17ef8b98637b223bae6bdcab2df697f8aa879999fe98170d8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>EVENT_SENT</name>
      <anchorfile>EventListener_8h.html</anchorfile>
      <anchor>a0fa812f40726abdb17ef8b98637b223bae469e9acb2cd1f3065079b893286ce0a</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>NodeStack.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/shacat/include/algorithm/tree/traditional/LIFO/</path>
    <filename>NodeStack_8h</filename>
    <includes id="TreeNode_8h" name="TreeNode.h" local="yes" imported="no">algorithm/tree/TreeNode.h</includes>
    <member kind="typedef">
      <type>std::vector&lt; TreeNodePtr &gt;</type>
      <name>TreeNodeStack</name>
      <anchorfile>NodeStack_8h.html</anchorfile>
      <anchor>ac9ed85d9736df57b5ee63ea0e9eb0744</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>TreeTraverse.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/shacat/include/algorithm/tree/traditional/LIFO/</path>
    <filename>TreeTraverse_8h</filename>
    <includes id="TreeNode_8h" name="TreeNode.h" local="yes" imported="no">algorithm/tree/TreeNode.h</includes>
    <includes id="TreeContext_8h" name="TreeContext.h" local="yes" imported="no">algorithm/tree/TreeContext.h</includes>
    <includes id="NodeStack_8h" name="NodeStack.h" local="yes" imported="no">algorithm/tree/traditional/LIFO/NodeStack.h</includes>
    <class kind="class">TreeTraverse</class>
  </compound>
  <compound kind="file">
    <name>TreeBuilder.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/shacat/include/algorithm/tree/</path>
    <filename>TreeBuilder_8h</filename>
    <includes id="TreeNode_8h" name="TreeNode.h" local="yes" imported="no">algorithm/tree/TreeNode.h</includes>
    <includes id="VisitedTreeNode_8h" name="VisitedTreeNode.h" local="yes" imported="no">algorithm/tree/visitor/VisitedTreeNode.h</includes>
    <class kind="class">TreeBuilder</class>
  </compound>
  <compound kind="file">
    <name>TreeContext.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/shacat/include/algorithm/tree/</path>
    <filename>TreeContext_8h</filename>
    <member kind="enumeration">
      <type></type>
      <name>TraverseStrategy</name>
      <anchorfile>TreeContext_8h.html</anchorfile>
      <anchor>a3e949626c34e09841138142d74f0d9c2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IN_ORDER</name>
      <anchorfile>TreeContext_8h.html</anchorfile>
      <anchor>a3e949626c34e09841138142d74f0d9c2a689aa9fa926510a42fc190e81c65e794</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>POST_ORDER</name>
      <anchorfile>TreeContext_8h.html</anchorfile>
      <anchor>a3e949626c34e09841138142d74f0d9c2adb0b29d4ea7b25dfccdef57ec4275e91</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>PRE_ORDER</name>
      <anchorfile>TreeContext_8h.html</anchorfile>
      <anchor>a3e949626c34e09841138142d74f0d9c2a165bf1eccc05929bf679fe6635bc1f2f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>DEPTH_FIRST</name>
      <anchorfile>TreeContext_8h.html</anchorfile>
      <anchor>a3e949626c34e09841138142d74f0d9c2ae6b0f1f7a7d66c50ac5c3edd178304ad</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>BREADTH_FIRST</name>
      <anchorfile>TreeContext_8h.html</anchorfile>
      <anchor>a3e949626c34e09841138142d74f0d9c2a94fd8b33020ef2b5210522e2c7b5da67</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>TraverseAction</name>
      <anchorfile>TreeContext_8h.html</anchorfile>
      <anchor>a7b3405ca174f96d6e9ca0dc0feaccb79</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TRAVERSE_IN</name>
      <anchorfile>TreeContext_8h.html</anchorfile>
      <anchor>a7b3405ca174f96d6e9ca0dc0feaccb79a1f60c5eae7190a5ab63c1105a0e4da58</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TRAVERSE_OUT</name>
      <anchorfile>TreeContext_8h.html</anchorfile>
      <anchor>a7b3405ca174f96d6e9ca0dc0feaccb79ae87dd3eac6f88249f99089d41ca8d40b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TRAVERSE_SECOND</name>
      <anchorfile>TreeContext_8h.html</anchorfile>
      <anchor>a7b3405ca174f96d6e9ca0dc0feaccb79aba93f5153a60a639378a6d0347d0b5b8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>NO_INTERNAL_ACTION</name>
      <anchorfile>TreeContext_8h.html</anchorfile>
      <anchor>a7b3405ca174f96d6e9ca0dc0feaccb79a39bb5a1acdb7a861c97bfbd86995e52a</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>TreeNode.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/shacat/include/algorithm/tree/</path>
    <filename>TreeNode_8h</filename>
    <includes id="TreeContext_8h" name="TreeContext.h" local="yes" imported="no">algorithm/tree/TreeContext.h</includes>
    <class kind="class">TreeNode</class>
    <member kind="typedef">
      <type>TreeNode *</type>
      <name>TreeNodePtr</name>
      <anchorfile>TreeNode_8h.html</anchorfile>
      <anchor>afe41b48fac23f337b78642812f4184f6</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>TreeNode *</type>
      <name>ParentNodePtr</name>
      <anchorfile>TreeNode_8h.html</anchorfile>
      <anchor>a417e9dea4453ec5054689167808670ea</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>TreeWalker.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/shacat/include/algorithm/tree/visitor/traversal/</path>
    <filename>TreeWalker_8h</filename>
    <includes id="VisitedTreeNode_8h" name="VisitedTreeNode.h" local="yes" imported="no">algorithm/tree/visitor/VisitedTreeNode.h</includes>
    <includes id="TreeContext_8h" name="TreeContext.h" local="yes" imported="no">algorithm/tree/TreeContext.h</includes>
    <includes id="Visitor_8h" name="Visitor.h" local="yes" imported="no">algorithm/visitor/Visitor.h</includes>
    <class kind="class">TreeWalker</class>
    <member kind="typedef">
      <type>VisitedTreeNode *</type>
      <name>VisitedTreeNodePtr</name>
      <anchorfile>TreeWalker_8h.html</anchorfile>
      <anchor>a5d73e74cc468881a16499feff0ac175b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>VisitedTreeNode.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/shacat/include/algorithm/tree/visitor/</path>
    <filename>VisitedTreeNode_8h</filename>
    <includes id="TreeNode_8h" name="TreeNode.h" local="yes" imported="no">algorithm/tree/TreeNode.h</includes>
    <includes id="TreeWalker_8h" name="TreeWalker.h" local="yes" imported="no">algorithm/tree/visitor/traversal/TreeWalker.h</includes>
    <includes id="TreeContext_8h" name="TreeContext.h" local="yes" imported="no">algorithm/tree/TreeContext.h</includes>
    <includes id="VisitedObject_8h" name="VisitedObject.h" local="yes" imported="no">algorithm/visitor/VisitedObject.h</includes>
    <class kind="class">VisitedTreeNode</class>
    <member kind="typedef">
      <type>VisitedTreeNode *</type>
      <name>VisitedTreeNodePtr</name>
      <anchorfile>VisitedTreeNode_8h.html</anchorfile>
      <anchor>a5d73e74cc468881a16499feff0ac175b</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>TreeWalker *</type>
      <name>TreeWalkerPtr</name>
      <anchorfile>VisitedTreeNode_8h.html</anchorfile>
      <anchor>a96b5cfb8de2aa17e629fb5a5dca8e039</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>VisitedObject.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/shacat/include/algorithm/visitor/</path>
    <filename>VisitedObject_8h</filename>
    <includes id="Visitor_8h" name="Visitor.h" local="yes" imported="no">algorithm/visitor/Visitor.h</includes>
    <class kind="class">VisitedObject</class>
    <member kind="typedef">
      <type>Visitor *</type>
      <name>VisitorPtr</name>
      <anchorfile>VisitedObject_8h.html</anchorfile>
      <anchor>a0c99074a28531b1a9399aaaefaec7801</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>Visitor.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/shacat/include/algorithm/visitor/</path>
    <filename>Visitor_8h</filename>
    <includes id="VisitedObject_8h" name="VisitedObject.h" local="yes" imported="no">algorithm/visitor/VisitedObject.h</includes>
    <class kind="class">Visitor</class>
    <member kind="typedef">
      <type>VisitedObject *</type>
      <name>VisitedObjectPtr</name>
      <anchorfile>Visitor_8h.html</anchorfile>
      <anchor>a92cea53991e4d4e96183766e2b23524a</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>Utils.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/shacat/include/common/</path>
    <filename>Utils_8h</filename>
    <includes id="Exception_8h" name="Exception.h" local="yes" imported="no">error/Exception.h</includes>
    <class kind="class">util::Strings</class>
    <class kind="class">util::Converts</class>
    <class kind="class">util::Conditions</class>
    <namespace>util</namespace>
  </compound>
  <compound kind="file">
    <name>Exception.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/shacat/include/error/</path>
    <filename>Exception_8h</filename>
    <class kind="class">Exception</class>
    <class kind="class">NullPointerException</class>
    <class kind="class">OutOfMemoryException</class>
    <class kind="class">UndefinedSymbolException</class>
    <class kind="class">IllegalStateException</class>
    <class kind="class">IllegalArgumentException</class>
    <class kind="class">TypeCastException</class>
  </compound>
  <compound kind="file">
    <name>StackTraceUtils.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/shacat/include/error/</path>
    <filename>StackTraceUtils_8h</filename>
    <class kind="struct">sig_ucontext_t</class>
    <class kind="class">StackTraceUtils</class>
  </compound>
  <compound kind="file">
    <name>AccessPrivate.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/shacat/include/hack/</path>
    <filename>AccessPrivate_8h</filename>
    <class kind="struct">HackProxy</class>
    <class kind="struct">HackPrivate</class>
    <class kind="struct">HackPrivate::privateFuncPtrHolder</class>
  </compound>
  <compound kind="file">
    <name>DebugLib.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/shacat/include/hack/</path>
    <filename>DebugLib_8h</filename>
  </compound>
  <compound kind="file">
    <name>Object.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/shacat/include/lang/</path>
    <filename>Object_8h</filename>
    <includes id="Utils_8h" name="Utils.h" local="yes" imported="no">common/Utils.h</includes>
    <includes id="Logger_8h" name="Logger.h" local="yes" imported="no">log/Logger.h</includes>
    <class kind="class">Object</class>
    <member kind="define">
      <type>#define</type>
      <name>CLASS_NAME</name>
      <anchorfile>Object_8h.html</anchorfile>
      <anchor>a79f2713d570c7065f61a160134ea765b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>Logger.h</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/shacat/include/log/</path>
    <filename>Logger_8h</filename>
    <includes id="Exception_8h" name="Exception.h" local="yes" imported="no">error/Exception.h</includes>
    <class kind="class">Logger</class>
    <member kind="define">
      <type>#define</type>
      <name>__FILE_NAME__</name>
      <anchorfile>Logger_8h.html</anchorfile>
      <anchor>a1f027784d7427e627ed2c94f0cc65b2d</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>LOG_CONF</name>
      <anchorfile>Logger_8h.html</anchorfile>
      <anchor>a0dc32710a01a4e4a5c1a59e7408e6408</anchor>
      <arglist>(outputFile, configuration, fileVerbosityLevel, screenVerbosityLevel)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>LOG</name>
      <anchorfile>Logger_8h.html</anchorfile>
      <anchor>a416c1b9337365a359dc3b3e27d31673b</anchor>
      <arglist>(log_level, msg)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>LOG_ERROR</name>
      <anchorfile>Logger_8h.html</anchorfile>
      <anchor>aca43d6e2afbfe34ed4ce4a175b0ba2f2</anchor>
      <arglist>(error_msg)</arglist>
    </member>
    <member kind="function">
      <type>Logger::LogConfigOption</type>
      <name>operator|</name>
      <anchorfile>Logger_8h.html</anchorfile>
      <anchor>aa4d775e7c82631088288b16ab5c32c03</anchor>
      <arglist>(Logger::LogConfigOption opt1, Logger::LogConfigOption opt2)</arglist>
    </member>
    <member kind="function">
      <type>Logger::LogConfigOption</type>
      <name>operator&amp;</name>
      <anchorfile>Logger_8h.html</anchorfile>
      <anchor>a2196f63e37821968dbfc9d7ac53ea8a3</anchor>
      <arglist>(Logger::LogConfigOption opt1, Logger::LogConfigOption opt2)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>EventDispatcher.cpp</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/shacat/src/algorithm/event/dispatcher/</path>
    <filename>EventDispatcher_8cpp</filename>
    <includes id="EventDispatcher_8h" name="EventDispatcher.h" local="yes" imported="no">algorithm/event/dispatcher/EventDispatcher.h</includes>
    <includes id="Utils_8h" name="Utils.h" local="yes" imported="no">common/Utils.h</includes>
    <includes id="Logger_8h" name="Logger.h" local="yes" imported="no">log/Logger.h</includes>
  </compound>
  <compound kind="file">
    <name>Event.cpp</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/shacat/src/algorithm/event/</path>
    <filename>Event_8cpp</filename>
    <includes id="Event_8h" name="Event.h" local="yes" imported="no">algorithm/event/Event.h</includes>
  </compound>
  <compound kind="file">
    <name>TreeTraverse.cpp</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/shacat/src/algorithm/tree/traditional/LIFO/</path>
    <filename>TreeTraverse_8cpp</filename>
    <includes id="TreeTraverse_8h" name="TreeTraverse.h" local="yes" imported="no">algorithm/tree/traditional/LIFO/TreeTraverse.h</includes>
    <includes id="NodeStack_8h" name="NodeStack.h" local="yes" imported="no">algorithm/tree/traditional/LIFO/NodeStack.h</includes>
    <includes id="Logger_8h" name="Logger.h" local="yes" imported="no">log/Logger.h</includes>
    <includes id="Utils_8h" name="Utils.h" local="yes" imported="no">common/Utils.h</includes>
  </compound>
  <compound kind="file">
    <name>TreeBuilder.cpp</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/shacat/src/algorithm/tree/</path>
    <filename>TreeBuilder_8cpp</filename>
    <includes id="TreeBuilder_8h" name="TreeBuilder.h" local="yes" imported="no">algorithm/tree/TreeBuilder.h</includes>
  </compound>
  <compound kind="file">
    <name>TreeNode.cpp</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/shacat/src/algorithm/tree/</path>
    <filename>TreeNode_8cpp</filename>
    <includes id="TreeNode_8h" name="TreeNode.h" local="yes" imported="no">algorithm/tree/TreeNode.h</includes>
    <includes id="Utils_8h" name="Utils.h" local="yes" imported="no">common/Utils.h</includes>
    <includes id="Logger_8h" name="Logger.h" local="yes" imported="no">log/Logger.h</includes>
  </compound>
  <compound kind="file">
    <name>VisitedTreeNode.cpp</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/shacat/src/algorithm/tree/visitor/</path>
    <filename>VisitedTreeNode_8cpp</filename>
    <includes id="VisitedTreeNode_8h" name="VisitedTreeNode.h" local="yes" imported="no">algorithm/tree/visitor/VisitedTreeNode.h</includes>
    <includes id="Utils_8h" name="Utils.h" local="yes" imported="no">common/Utils.h</includes>
    <includes id="Logger_8h" name="Logger.h" local="yes" imported="no">log/Logger.h</includes>
  </compound>
  <compound kind="file">
    <name>Conditions.cpp</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/shacat/src/common/</path>
    <filename>Conditions_8cpp</filename>
    <includes id="Utils_8h" name="Utils.h" local="yes" imported="no">common/Utils.h</includes>
  </compound>
  <compound kind="file">
    <name>Conversions.cpp</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/shacat/src/common/</path>
    <filename>Conversions_8cpp</filename>
    <includes id="Utils_8h" name="Utils.h" local="yes" imported="no">common/Utils.h</includes>
    <includes id="Exception_8h" name="Exception.h" local="yes" imported="no">error/Exception.h</includes>
  </compound>
  <compound kind="file">
    <name>Strings.cpp</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/shacat/src/common/</path>
    <filename>Strings_8cpp</filename>
    <includes id="Utils_8h" name="Utils.h" local="yes" imported="no">common/Utils.h</includes>
  </compound>
  <compound kind="file">
    <name>Exception.cpp</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/shacat/src/error/</path>
    <filename>Exception_8cpp</filename>
    <includes id="Exception_8h" name="Exception.h" local="yes" imported="no">error/Exception.h</includes>
    <includes id="StackTraceUtils_8h" name="StackTraceUtils.h" local="yes" imported="no">error/StackTraceUtils.h</includes>
  </compound>
  <compound kind="file">
    <name>StackTraceUtils.cpp</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/shacat/src/error/</path>
    <filename>StackTraceUtils_8cpp</filename>
    <includes id="StackTraceUtils_8h" name="StackTraceUtils.h" local="yes" imported="no">error/StackTraceUtils.h</includes>
  </compound>
  <compound kind="file">
    <name>Object.cpp</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/shacat/src/lang/</path>
    <filename>Object_8cpp</filename>
    <includes id="Object_8h" name="Object.h" local="yes" imported="no">lang/Object.h</includes>
    <includes id="Utils_8h" name="Utils.h" local="yes" imported="no">common/Utils.h</includes>
    <includes id="Logger_8h" name="Logger.h" local="yes" imported="no">log/Logger.h</includes>
  </compound>
  <compound kind="file">
    <name>Logger.cpp</name>
    <path>/home/shannaracat/dev/gitlab/workspace_oss/LostInCompilation/libs/shacat/src/log/</path>
    <filename>Logger_8cpp</filename>
    <includes id="Logger_8h" name="Logger.h" local="yes" imported="no">log/Logger.h</includes>
    <includes id="Utils_8h" name="Utils.h" local="yes" imported="no">common/Utils.h</includes>
    <includes id="Exception_8h" name="Exception.h" local="yes" imported="no">error/Exception.h</includes>
  </compound>
  <compound kind="class">
    <name>util::Conditions</name>
    <filename>classutil_1_1Conditions.html</filename>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>requireTrue</name>
      <anchorfile>classutil_1_1Conditions.html</anchorfile>
      <anchor>a27649a68e90aa41a18bbc16248c9579f</anchor>
      <arglist>(bool value, const std::string &amp;hint)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>requireNotNull</name>
      <anchorfile>classutil_1_1Conditions.html</anchorfile>
      <anchor>a06de3c351108aee6842f2d69eaf34185</anchor>
      <arglist>(const void *obj, const std::string &amp;hint)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>requireNotNull</name>
      <anchorfile>classutil_1_1Conditions.html</anchorfile>
      <anchor>ae7bc3b901b1b049cff879d6fd561aacb</anchor>
      <arglist>(T *ptr, const std::string &amp;hint)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>requireNotNull</name>
      <anchorfile>classutil_1_1Conditions.html</anchorfile>
      <anchor>a197aa953183d523c31ab1ae9fc31cd3b</anchor>
      <arglist>(std::unique_ptr&lt; T &gt; ptr, const std::string &amp;hint)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>requireGreaterThan</name>
      <anchorfile>classutil_1_1Conditions.html</anchorfile>
      <anchor>a5553ff0ce68349bc2e80871a323c09b7</anchor>
      <arglist>(const T &amp;val, const T &amp;low, const std::string &amp;hint)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>requireLessThan</name>
      <anchorfile>classutil_1_1Conditions.html</anchorfile>
      <anchor>a7006dac9b6a62082299e1cf57614a929</anchor>
      <arglist>(const T &amp;val, const T &amp;high, const std::string &amp;hint)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>requireEqualsTo</name>
      <anchorfile>classutil_1_1Conditions.html</anchorfile>
      <anchor>a713af481012604e1cd13a4d54f1e31a4</anchor>
      <arglist>(const T &amp;val, const T &amp;threshold, const std::string &amp;hint)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>requireBetween</name>
      <anchorfile>classutil_1_1Conditions.html</anchorfile>
      <anchor>aeea90a7200a5b1b17dff9472b9b60796</anchor>
      <arglist>(const T &amp;val, const T &amp;low, const T &amp;high, const std::string &amp;hint)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>requireNotEmpty</name>
      <anchorfile>classutil_1_1Conditions.html</anchorfile>
      <anchor>a6b62ee8f227bcf88474441eedb2bb486</anchor>
      <arglist>(const Container &amp;obj, const std::string &amp;hint)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>util::Converts</name>
    <filename>classutil_1_1Converts.html</filename>
    <member kind="function" static="yes">
      <type>static std::string</type>
      <name>boolToString</name>
      <anchorfile>classutil_1_1Converts.html</anchorfile>
      <anchor>a5d2848f2d4b0b62dd0353be0afd6c5b2</anchor>
      <arglist>(bool b)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static std::string</type>
      <name>numberToString</name>
      <anchorfile>classutil_1_1Converts.html</anchorfile>
      <anchor>ab0ad26965ceef36322d64aeb40e2a2e4</anchor>
      <arglist>(T num)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static std::string</type>
      <name>numberToHexString</name>
      <anchorfile>classutil_1_1Converts.html</anchorfile>
      <anchor>a72059bdbb0e8f826bb2a9b8f27ef789b</anchor>
      <arglist>(T num)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>stringToBool</name>
      <anchorfile>classutil_1_1Converts.html</anchorfile>
      <anchor>a07bba0386aafcee693462d4fb34c4187</anchor>
      <arglist>(const std::string &amp;str)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static T</type>
      <name>stringToNumber</name>
      <anchorfile>classutil_1_1Converts.html</anchorfile>
      <anchor>ab73a43f70bccb44a99a935ff8f55e6d4</anchor>
      <arglist>(const std::string &amp;str)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static T</type>
      <name>hexStringToNumber</name>
      <anchorfile>classutil_1_1Converts.html</anchorfile>
      <anchor>acf852ec2aaab5efbf5d121a949e884a2</anchor>
      <arglist>(const std::string &amp;str)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Event</name>
    <filename>classEvent.html</filename>
    <member kind="function">
      <type></type>
      <name>Event</name>
      <anchorfile>classEvent.html</anchorfile>
      <anchor>a5f5655e55a48b0b2d8c6d9da6f3076a6</anchor>
      <arglist>(std::string summary, std::string message)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Event</name>
      <anchorfile>classEvent.html</anchorfile>
      <anchor>a7704ec01ce91e673885792054214b3d2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::string</type>
      <name>getMessage</name>
      <anchorfile>classEvent.html</anchorfile>
      <anchor>ab9d3bbd943f2adec62d1cd7682dac27f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::string</type>
      <name>getSummary</name>
      <anchorfile>classEvent.html</anchorfile>
      <anchor>a52ff968a394c2aab3d791638798b9ddf</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>std::string</type>
      <name>_summary</name>
      <anchorfile>classEvent.html</anchorfile>
      <anchor>a6432d6ee7721b52f65279849b3f8d1cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>std::string</type>
      <name>_message</name>
      <anchorfile>classEvent.html</anchorfile>
      <anchor>ae527e5f3eca10eeb3e1c523313b95fc7</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>EventDispatcher</name>
    <filename>classEventDispatcher.html</filename>
    <member kind="function">
      <type></type>
      <name>EventDispatcher</name>
      <anchorfile>classEventDispatcher.html</anchorfile>
      <anchor>aec174a9e25796e5727e59f5452817cda</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~EventDispatcher</name>
      <anchorfile>classEventDispatcher.html</anchorfile>
      <anchor>abb5f401014e87f03027d6c4450964e55</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>addListener</name>
      <anchorfile>classEventDispatcher.html</anchorfile>
      <anchor>a749052718008aec2fd6731d199dd401d</anchor>
      <arglist>(EventListenerPtr listener)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>removeListener</name>
      <anchorfile>classEventDispatcher.html</anchorfile>
      <anchor>a1fdcb2ec27fc1741de72c242abb2d189</anchor>
      <arglist>(EventListenerPtr listener)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>sendMessage</name>
      <anchorfile>classEventDispatcher.html</anchorfile>
      <anchor>a05c7764d638359f3d30ec8b724b5c887</anchor>
      <arglist>(Event event, EventListenerType eventType)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::vector&lt; EventListenerPtr &gt;</type>
      <name>getEventListeners</name>
      <anchorfile>classEventDispatcher.html</anchorfile>
      <anchor>a8ee4bf2ac6d6b25b14d29a0876c8c0ca</anchor>
      <arglist>(EventListenerType eventType) const </arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>notifyListeners</name>
      <anchorfile>classEventDispatcher.html</anchorfile>
      <anchor>abef37afce6fdb8ce4bf093b343f4ee81</anchor>
      <arglist>(Event event, EventListenerType eventType)</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::map&lt; EventListenerType, std::vector&lt; EventListenerPtr &gt; &gt;</type>
      <name>_listenersMap</name>
      <anchorfile>classEventDispatcher.html</anchorfile>
      <anchor>a503f1955f3cb8f21fcf3b58fc050a82e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::vector&lt; EventListenerPtr &gt;</type>
      <name>_listeners</name>
      <anchorfile>classEventDispatcher.html</anchorfile>
      <anchor>a581f15cb1f90520dcc80757b2a35e2a8</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>EventListener</name>
    <filename>classEventListener.html</filename>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>onEvent</name>
      <anchorfile>classEventListener.html</anchorfile>
      <anchor>a6e5686b580d6eeba483166cf9074646e</anchor>
      <arglist>(Event event)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual EventListenerType</type>
      <name>getType</name>
      <anchorfile>classEventListener.html</anchorfile>
      <anchor>ae046530f80e058c99d2e3af7cac891c8</anchor>
      <arglist>()=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>EventReceivedListener</name>
    <filename>classEventReceivedListener.html</filename>
    <base>EventListener</base>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>onEvent</name>
      <anchorfile>classEventReceivedListener.html</anchorfile>
      <anchor>ade809bf3b3635985076a8e1f60f42335</anchor>
      <arglist>(Event event)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual EventListenerType</type>
      <name>getType</name>
      <anchorfile>classEventReceivedListener.html</anchorfile>
      <anchor>a9177fc8fb54209b578cc3f9a50a35ddf</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="pure">
      <type>virtual void</type>
      <name>onReceived</name>
      <anchorfile>classEventReceivedListener.html</anchorfile>
      <anchor>adeffca9237b8b8bc1dbda45c3393088d</anchor>
      <arglist>(Event event)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>EventSentListener</name>
    <filename>classEventSentListener.html</filename>
    <base>EventListener</base>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>onEvent</name>
      <anchorfile>classEventSentListener.html</anchorfile>
      <anchor>a2f6742b2c1ce5ba0f43ccbb5e9c59418</anchor>
      <arglist>(Event event)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual EventListenerType</type>
      <name>getType</name>
      <anchorfile>classEventSentListener.html</anchorfile>
      <anchor>aef6e5b12a829c7cf7972a52821086b6d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="pure">
      <type>virtual void</type>
      <name>onSent</name>
      <anchorfile>classEventSentListener.html</anchorfile>
      <anchor>a8015309d352fd55d61cf2cd98ef8e0f5</anchor>
      <arglist>(Event event)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Exception</name>
    <filename>classException.html</filename>
    <member kind="function">
      <type></type>
      <name>Exception</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>a1b78336bb26edf8e784783cc150c5801</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Exception</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>a0aa4d31928acbbe88a9d26b10be510bb</anchor>
      <arglist>(const std::string &amp;summary)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Exception</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>a00765d3f1514dc51df76da3bd1284332</anchor>
      <arglist>(const std::string &amp;summary, const std::string &amp;msg)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Exception</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>a5b9f18be88f8228d8c1af8c30d4f5d6b</anchor>
      <arglist>(const std::string &amp;summary, const std::string &amp;msg, const bool includeStackTrace)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Exception</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>a6b214cd8627d0968bdeebc1fbb9556b8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>what</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>a380f0477d9ef319911e7a8167bd47f1f</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::string</type>
      <name>getTrace</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>a82fcc8b1a3db2d25686ab87af5ae8048</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::string</type>
      <name>getShortDescrption</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>a059dfe1d84ff0f8cdd1f2e60a4411fe8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>std::string</type>
      <name>_shortDesc</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>a1f60ffc307534eadd3145f3e310c49cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>std::string</type>
      <name>_trace</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>ae1ff69c4cefeb0dbb5364e3e1bb57fd3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>std::string</type>
      <name>_message</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>aab929939472fd18508ce96c17469a834</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>HackPrivate</name>
    <filename>structHackPrivate.html</filename>
    <templarg></templarg>
    <templarg>funcPtr</templarg>
    <base>HackProxy</base>
    <class kind="struct">HackPrivate::privateFuncPtrHolder</class>
    <member kind="typedef">
      <type>ProxyName::type</type>
      <name>type</name>
      <anchorfile>structHackProxy.html</anchorfile>
      <anchor>a85aebaf9ad69c6a89a7e57434cc41bd9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static privateFuncPtrHolder</type>
      <name>funcPtrObj</name>
      <anchorfile>structHackPrivate.html</anchorfile>
      <anchor>af5d223aee618254bb26d1f03619ec513</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static type</type>
      <name>privateFuncPtr</name>
      <anchorfile>structHackProxy.html</anchorfile>
      <anchor>aee31a33e4df4d2c3ffb20a916cdd542a</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>HackProxy</name>
    <filename>structHackProxy.html</filename>
    <templarg>ProxyName</templarg>
    <member kind="typedef">
      <type>ProxyName::type</type>
      <name>type</name>
      <anchorfile>structHackProxy.html</anchorfile>
      <anchor>a85aebaf9ad69c6a89a7e57434cc41bd9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static type</type>
      <name>privateFuncPtr</name>
      <anchorfile>structHackProxy.html</anchorfile>
      <anchor>aee31a33e4df4d2c3ffb20a916cdd542a</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>IllegalArgumentException</name>
    <filename>classIllegalArgumentException.html</filename>
    <base>Exception</base>
    <member kind="function">
      <type></type>
      <name>IllegalArgumentException</name>
      <anchorfile>classIllegalArgumentException.html</anchorfile>
      <anchor>aea0ae4fb3c182f46be72d12a40a6be5e</anchor>
      <arglist>(const std::string &amp;msg)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~IllegalArgumentException</name>
      <anchorfile>classIllegalArgumentException.html</anchorfile>
      <anchor>afff2ef9ba7804e72671ff16f60cb123e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>what</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>a380f0477d9ef319911e7a8167bd47f1f</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::string</type>
      <name>getTrace</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>a82fcc8b1a3db2d25686ab87af5ae8048</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::string</type>
      <name>getShortDescrption</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>a059dfe1d84ff0f8cdd1f2e60a4411fe8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>std::string</type>
      <name>_shortDesc</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>a1f60ffc307534eadd3145f3e310c49cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>std::string</type>
      <name>_trace</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>ae1ff69c4cefeb0dbb5364e3e1bb57fd3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>std::string</type>
      <name>_message</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>aab929939472fd18508ce96c17469a834</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>IllegalStateException</name>
    <filename>classIllegalStateException.html</filename>
    <base>Exception</base>
    <member kind="function">
      <type></type>
      <name>IllegalStateException</name>
      <anchorfile>classIllegalStateException.html</anchorfile>
      <anchor>a022f74aa7c6190c29deb06f8c5993e87</anchor>
      <arglist>(const std::string &amp;msg)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~IllegalStateException</name>
      <anchorfile>classIllegalStateException.html</anchorfile>
      <anchor>a115a65e67b6778081373148c0c69aa72</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>what</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>a380f0477d9ef319911e7a8167bd47f1f</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::string</type>
      <name>getTrace</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>a82fcc8b1a3db2d25686ab87af5ae8048</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::string</type>
      <name>getShortDescrption</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>a059dfe1d84ff0f8cdd1f2e60a4411fe8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>std::string</type>
      <name>_shortDesc</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>a1f60ffc307534eadd3145f3e310c49cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>std::string</type>
      <name>_trace</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>ae1ff69c4cefeb0dbb5364e3e1bb57fd3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>std::string</type>
      <name>_message</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>aab929939472fd18508ce96c17469a834</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Logger</name>
    <filename>classLogger.html</filename>
    <member kind="typedef">
      <type>_LogLevel</type>
      <name>LogLevel</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>af6d4609508a03355b33f4958f1b511ae</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>_LogConfigOption</type>
      <name>LogConfigOption</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>a840a3e5e47d3b429060b1632195b8470</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Logger</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>acb668a9e186a25fbaad2e4af6d1ed00a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>configure</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>a74b345a0cac9d3c80670c8250cfb4df0</anchor>
      <arglist>(const std::string &amp;outputFile, LogConfigOption option, LogLevel fileVerbosityLevel, LogLevel screenVerbosityLevel)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>print</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>a80673a03670314b32bd25217e4851695</anchor>
      <arglist>(LogLevel verbosityLevel, const char *fileName, const int codeLineNum, const std::string &amp;message)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Logger *</type>
      <name>getInstance</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>afec28ae6d7bdf8f6a0734cb20756de10</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const LogLevel</type>
      <name>LEVEL_OFF</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>a47f5a8c6cd9f7231e1536da661cbb860</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const LogLevel</type>
      <name>LEVEL_ERROR</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>acb07381fcaeaabe3826fa885338ac7ae</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const LogLevel</type>
      <name>LEVEL_WARN</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>a25e702b332a08d10c1f7cc520d7bdac3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const LogLevel</type>
      <name>LEVEL_INFO</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>a70d62a752f8086cfe9c780067b88540e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const LogLevel</type>
      <name>LEVEL_DEBUG</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>a8907f17b0380b6f3cc191fdb201faedc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const LogLevel</type>
      <name>LEVEL_TRACE</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>a5c072cce87501d94a6cdcf33df0f5b3a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const LogLevel</type>
      <name>LEVEL_ALL</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>ae421b11988b95c6aa464c7f0b9d91314</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const LogConfigOption</type>
      <name>file_on</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>a8df8a715538b58b2883767bb212bc78f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const LogConfigOption</type>
      <name>file_off</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>ac1b6a28933f7207ba7ce29191044e346</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const LogConfigOption</type>
      <name>screen_on</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>abd0b1c1252e62219bd2c48b1faaca885</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const LogConfigOption</type>
      <name>screen_off</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>a6fafff80584fed1105a0b03374dcf5d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const LogConfigOption</type>
      <name>file_append</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>a09dc71d89f7d4e4b6a2ba17f982741ef</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration" protection="private">
      <type></type>
      <name>_LogLevel</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>ad0904b63afd46927ade298d78987a211</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue" protection="private">
      <name>_LEVEL_OFF</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>ad0904b63afd46927ade298d78987a211a04e420b958a32e1bb85e678a20c48752</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue" protection="private">
      <name>_LEVEL_ERROR</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>ad0904b63afd46927ade298d78987a211a13af457350bb3778b03a2d1b2a86505f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue" protection="private">
      <name>_LEVEL_WARN</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>ad0904b63afd46927ade298d78987a211a46a924bb43db63eec25fcb4e918463f6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue" protection="private">
      <name>_LEVEL_INFO</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>ad0904b63afd46927ade298d78987a211a06db4f21639643c294e742016a1bf69c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue" protection="private">
      <name>_LEVEL_DEBUG</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>ad0904b63afd46927ade298d78987a211a267b104dcb22e265e09fb97100729260</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue" protection="private">
      <name>_LEVEL_TRACE</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>ad0904b63afd46927ade298d78987a211a13a81b6f34e6189ccc4fcd81e6aea801</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue" protection="private">
      <name>_LEVEL_ALL</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>ad0904b63afd46927ade298d78987a211a07eee2edf445700ba5b7a526411c04fb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration" protection="private">
      <type></type>
      <name>_LogConfigOption</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>a2437086591d4c9d7123d5e9e13e81fc2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue" protection="private">
      <name>_file_on</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>a2437086591d4c9d7123d5e9e13e81fc2a3bfc8913f27328cc0784a5135154899a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue" protection="private">
      <name>_file_off</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>a2437086591d4c9d7123d5e9e13e81fc2ad4b72ef91c11d8b1ac5651412af8a069</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue" protection="private">
      <name>_screen_on</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>a2437086591d4c9d7123d5e9e13e81fc2ac82a0d4221a23ad7f71cdd6d9efb3234</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue" protection="private">
      <name>_screen_off</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>a2437086591d4c9d7123d5e9e13e81fc2acf55769c79f19395e7ddf9dc27b2795d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue" protection="private">
      <name>_file_append</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>a2437086591d4c9d7123d5e9e13e81fc2a555977f67ec7dad3b54ac245e0b69a6c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue" protection="private">
      <name>_LEVEL_OFF</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>ad0904b63afd46927ade298d78987a211a04e420b958a32e1bb85e678a20c48752</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue" protection="private">
      <name>_LEVEL_ERROR</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>ad0904b63afd46927ade298d78987a211a13af457350bb3778b03a2d1b2a86505f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue" protection="private">
      <name>_LEVEL_WARN</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>ad0904b63afd46927ade298d78987a211a46a924bb43db63eec25fcb4e918463f6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue" protection="private">
      <name>_LEVEL_INFO</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>ad0904b63afd46927ade298d78987a211a06db4f21639643c294e742016a1bf69c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue" protection="private">
      <name>_LEVEL_DEBUG</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>ad0904b63afd46927ade298d78987a211a267b104dcb22e265e09fb97100729260</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue" protection="private">
      <name>_LEVEL_TRACE</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>ad0904b63afd46927ade298d78987a211a13a81b6f34e6189ccc4fcd81e6aea801</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue" protection="private">
      <name>_LEVEL_ALL</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>ad0904b63afd46927ade298d78987a211a07eee2edf445700ba5b7a526411c04fb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue" protection="private">
      <name>_file_on</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>a2437086591d4c9d7123d5e9e13e81fc2a3bfc8913f27328cc0784a5135154899a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue" protection="private">
      <name>_file_off</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>a2437086591d4c9d7123d5e9e13e81fc2ad4b72ef91c11d8b1ac5651412af8a069</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue" protection="private">
      <name>_screen_on</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>a2437086591d4c9d7123d5e9e13e81fc2ac82a0d4221a23ad7f71cdd6d9efb3234</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue" protection="private">
      <name>_screen_off</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>a2437086591d4c9d7123d5e9e13e81fc2acf55769c79f19395e7ddf9dc27b2795d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue" protection="private">
      <name>_file_append</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>a2437086591d4c9d7123d5e9e13e81fc2a555977f67ec7dad3b54ac245e0b69a6c</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>Logger</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>abc41bfb031d896170c7675fa96a6b30c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>bool</type>
      <name>_isConfigured</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>a5a9384676647c3b8eb450a08230f09a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::string</type>
      <name>_logFileName</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>a0943d0571a698378d1eaa0fb570b9268</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>LogConfigOption</type>
      <name>_configOption</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>a6e1e0c76b9299ebcbd1a646cb9c6d534</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::ofstream</type>
      <name>_out</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>a398396d4db3ce8a1f256a58a3de3f1f8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>struct timeval</type>
      <name>_initTime</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>a498910e9cd5a8c3f132fe1cd2553883d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>size_t</type>
      <name>_fileVerbosityLevel</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>a0effc32b288a096ab8ed225874ffd2d5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>size_t</type>
      <name>_screenVerbosityLevel</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>ac4134bfd9253fd15fb1ed535e913d845</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static Logger *</type>
      <name>INSTANCE</name>
      <anchorfile>classLogger.html</anchorfile>
      <anchor>a0c5fb6d4d9b3bb61bdf40fa47a364813</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>NullPointerException</name>
    <filename>classNullPointerException.html</filename>
    <base>Exception</base>
    <member kind="function">
      <type></type>
      <name>NullPointerException</name>
      <anchorfile>classNullPointerException.html</anchorfile>
      <anchor>a95ee736301bc0591c52b015a0530f981</anchor>
      <arglist>(const std::string &amp;msg)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~NullPointerException</name>
      <anchorfile>classNullPointerException.html</anchorfile>
      <anchor>abcc14f47337fc020ec8d69fdf094c38f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>what</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>a380f0477d9ef319911e7a8167bd47f1f</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::string</type>
      <name>getTrace</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>a82fcc8b1a3db2d25686ab87af5ae8048</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::string</type>
      <name>getShortDescrption</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>a059dfe1d84ff0f8cdd1f2e60a4411fe8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>std::string</type>
      <name>_shortDesc</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>a1f60ffc307534eadd3145f3e310c49cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>std::string</type>
      <name>_trace</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>ae1ff69c4cefeb0dbb5364e3e1bb57fd3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>std::string</type>
      <name>_message</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>aab929939472fd18508ce96c17469a834</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Object</name>
    <filename>classObject.html</filename>
    <member kind="function">
      <type></type>
      <name>Object</name>
      <anchorfile>classObject.html</anchorfile>
      <anchor>a40860402e64d8008fb42329df7097cdb</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Object</name>
      <anchorfile>classObject.html</anchorfile>
      <anchor>aa61fd6047cec7062d253bb001170fcd0</anchor>
      <arglist>(const Object &amp;that)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Object</name>
      <anchorfile>classObject.html</anchorfile>
      <anchor>ae8f5483f459e46687bd01e6f9977afd3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>Object &amp;</type>
      <name>operator=</name>
      <anchorfile>classObject.html</anchorfile>
      <anchor>a1cd086efe7291439eae7726846757cc3</anchor>
      <arglist>(Object that)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::string</type>
      <name>toString</name>
      <anchorfile>classObject.html</anchorfile>
      <anchor>a2a71a6af528b14988cbf837b1d2861c6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual size_t</type>
      <name>hashCode</name>
      <anchorfile>classObject.html</anchorfile>
      <anchor>a8c2ef665852ef5d12a0e6c6915c0aedd</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>swap</name>
      <anchorfile>classObject.html</anchorfile>
      <anchor>a688510b2c367504f86d88bfefcedaa8d</anchor>
      <arglist>(Object &amp;that)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>uintptr_t</type>
      <name>_addr</name>
      <anchorfile>classObject.html</anchorfile>
      <anchor>adbe2a28d07ac98a38bc5c6b73257cfca</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>std::string</type>
      <name>_className</name>
      <anchorfile>classObject.html</anchorfile>
      <anchor>a13505c2761e727aebfc5b2d0df53938e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>OutOfMemoryException</name>
    <filename>classOutOfMemoryException.html</filename>
    <base>Exception</base>
    <member kind="function">
      <type></type>
      <name>OutOfMemoryException</name>
      <anchorfile>classOutOfMemoryException.html</anchorfile>
      <anchor>a1c047b177660d7a34ba3259922ca4a08</anchor>
      <arglist>(const std::string &amp;msg)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~OutOfMemoryException</name>
      <anchorfile>classOutOfMemoryException.html</anchorfile>
      <anchor>afee90eff07899faf6b28e09530dec310</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>what</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>a380f0477d9ef319911e7a8167bd47f1f</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::string</type>
      <name>getTrace</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>a82fcc8b1a3db2d25686ab87af5ae8048</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::string</type>
      <name>getShortDescrption</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>a059dfe1d84ff0f8cdd1f2e60a4411fe8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>std::string</type>
      <name>_shortDesc</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>a1f60ffc307534eadd3145f3e310c49cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>std::string</type>
      <name>_trace</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>ae1ff69c4cefeb0dbb5364e3e1bb57fd3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>std::string</type>
      <name>_message</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>aab929939472fd18508ce96c17469a834</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>HackPrivate::privateFuncPtrHolder</name>
    <filename>structHackPrivate_1_1privateFuncPtrHolder.html</filename>
    <member kind="function">
      <type></type>
      <name>privateFuncPtrHolder</name>
      <anchorfile>structHackPrivate_1_1privateFuncPtrHolder.html</anchorfile>
      <anchor>ab6af758d3c2e26fda546062f79d69827</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>sig_ucontext_t</name>
    <filename>structsig__ucontext__t.html</filename>
    <member kind="variable">
      <type>unsigned long</type>
      <name>uc_flags</name>
      <anchorfile>structsig__ucontext__t.html</anchorfile>
      <anchor>a5a23e836e8bc6947e4301e4071b6fb65</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>struct ucontext *</type>
      <name>uc_link</name>
      <anchorfile>structsig__ucontext__t.html</anchorfile>
      <anchor>a306cfb127dae40b521410babd23a1837</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>stack_t</type>
      <name>uc_stack</name>
      <anchorfile>structsig__ucontext__t.html</anchorfile>
      <anchor>a9e8d011952eee8d375d41808daff3e9a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>struct sigcontext</type>
      <name>uc_mcontext</name>
      <anchorfile>structsig__ucontext__t.html</anchorfile>
      <anchor>a851eb7a9e3c34999a321ae028fcdbc27</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>sigset_t</type>
      <name>uc_sigmask</name>
      <anchorfile>structsig__ucontext__t.html</anchorfile>
      <anchor>a5cbe3cadce6ddccf4fe8960fef9f81a7</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>StackTraceUtils</name>
    <filename>classStackTraceUtils.html</filename>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>setupStackTraceAgent</name>
      <anchorfile>classStackTraceUtils.html</anchorfile>
      <anchor>aaa4f7708f10e3ddee5c5003ad746f152</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static std::string</type>
      <name>getStackTraceMessage</name>
      <anchorfile>classStackTraceUtils.html</anchorfile>
      <anchor>a95b4b7629f97a151ac255ed88dbfd781</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>util::Strings</name>
    <filename>classutil_1_1Strings.html</filename>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>toUpperCase</name>
      <anchorfile>classutil_1_1Strings.html</anchorfile>
      <anchor>a650abf9821e56d30b505f52c56d6ad64</anchor>
      <arglist>(std::string &amp;str)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>toLowerCase</name>
      <anchorfile>classutil_1_1Strings.html</anchorfile>
      <anchor>a111a9ac8088ec56d3a109b95d43f654a</anchor>
      <arglist>(std::string &amp;str)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>equalsIgnoreCase</name>
      <anchorfile>classutil_1_1Strings.html</anchorfile>
      <anchor>a978c3a06958e94738edec8e88a620b00</anchor>
      <arglist>(const std::string &amp;str1, const std::string &amp;str2)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>endWith</name>
      <anchorfile>classutil_1_1Strings.html</anchorfile>
      <anchor>a801571d6906d02176172f51f9b04e313</anchor>
      <arglist>(const std::string &amp;srcStr, const std::string &amp;patternStr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>beginWith</name>
      <anchorfile>classutil_1_1Strings.html</anchorfile>
      <anchor>a262f4389fccd38b28e45d867d79f91e4</anchor>
      <arglist>(const std::string &amp;srcStr, const std::string &amp;patternStr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>contain</name>
      <anchorfile>classutil_1_1Strings.html</anchorfile>
      <anchor>a45c1063ec6440fd0762ee245d4a1ec22</anchor>
      <arglist>(const std::string &amp;srcStr, const std::string &amp;patternStr)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TreeBuilder</name>
    <filename>classTreeBuilder.html</filename>
    <templarg></templarg>
    <templarg></templarg>
    <member kind="function">
      <type></type>
      <name>TreeBuilder</name>
      <anchorfile>classTreeBuilder.html</anchorfile>
      <anchor>a0f9f3257a89f5c6c3d3223bd3f2983e1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TreeBuilder</name>
      <anchorfile>classTreeBuilder.html</anchorfile>
      <anchor>a20ebb04ed365ca584aafe48b9ae46369</anchor>
      <arglist>(NodePtrType that)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TreeBuilder</name>
      <anchorfile>classTreeBuilder.html</anchorfile>
      <anchor>ac1f6e06cc6f5ff168b7f0308e81093b0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TreeBuilder &amp;</type>
      <name>addChild</name>
      <anchorfile>classTreeBuilder.html</anchorfile>
      <anchor>a0af49df4562afd8f0ba1b51b5db979fc</anchor>
      <arglist>(NodePtrType child)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TreeBuilder &amp;</type>
      <name>addChildren</name>
      <anchorfile>classTreeBuilder.html</anchorfile>
      <anchor>a0e95529acc21ffc685a25e4ce38b89c8</anchor>
      <arglist>(std::vector&lt; NodePtrType &gt; children)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual NodePtrType</type>
      <name>toTree</name>
      <anchorfile>classTreeBuilder.html</anchorfile>
      <anchor>a4510e315708948c5234aee5e2248aa4b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>NodePtrType</type>
      <name>_current</name>
      <anchorfile>classTreeBuilder.html</anchorfile>
      <anchor>a2f1cd6e43c87a2943fea0fecbddc2ba7</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TreeNode</name>
    <filename>classTreeNode.html</filename>
    <member kind="function">
      <type></type>
      <name>TreeNode</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>a984a98d5ccf7ef1f5a18094c6821f35d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TreeNode</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>ae8502e25e5b5abb5b94cd62cd20a410c</anchor>
      <arglist>(TreeNode *const)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TreeNode</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>ad4b92345703cf72ea1f0f2f5351587c8</anchor>
      <arglist>(TreeNodePtr that)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TreeNode</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>a138449d182c342d032c78e7037afc151</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>insertChild</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>a8ef15b0f66720ff142b445007bc14546</anchor>
      <arglist>(TreeNodePtr childPtr, ParentNodePtr parentPtr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>insertChild</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>af7c03dc92e2912d7c4ce62bd5ef90685</anchor>
      <arglist>(TreeNodePtr childPtr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>insertChildren</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>a65e43cc7982fc28502793777a29a55dd</anchor>
      <arglist>(std::vector&lt; TreeNodePtr &gt; &amp;childrenPtr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual size_t</type>
      <name>getNumOfChildren</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>a0add7cbf0c98194fd6b3ba42dd79eb80</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual size_t</type>
      <name>getChildIndexOf</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>ac575d02736e030d030a742f871fad830</anchor>
      <arglist>(TreeNodePtr ptr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isChildAt</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>abef06530a053d061d0881812e9f1a094</anchor>
      <arglist>(size_t i)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TreeNodePtr</type>
      <name>getChildAt</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>af187913777d7dd465b65601cf8019216</anchor>
      <arglist>(size_t index)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>removeChildAt</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>ac45bf607c3f06556630068dab3f10ca6</anchor>
      <arglist>(size_t)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>replaceChildAt</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>ada1dd865827d890ebdfbeb29b21263e0</anchor>
      <arglist>(size_t, TreeNodePtr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>removeAllChildren</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>a2bcdcb3e4d1b244068bc05a7e059afee</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ParentNodePtr</type>
      <name>getParent</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>af3b90e5d3c528e9fd851ebfb37907e48</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isRoot</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>aa9fc2bc19c36ccb2b222fde4f530e988</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isLeaf</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>aa237aa34d056a4731f33e65d33a40584</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual size_t</type>
      <name>getDepth</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>a5f0878faad85d2336beda90c20a14bb1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setState</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>a1f19d84761a7bce22ea15c35ed847eef</anchor>
      <arglist>(TraverseAction action)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TraverseAction</type>
      <name>getState</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>a9e1b11b9e2d20f1c15efa80d7d4a0400</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setParent</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>ac39280b56824bfdb1b0abe0fb6ed4dac</anchor>
      <arglist>(ParentNodePtr ptr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>replace</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>a0fa9b537f271ac5f38a655bcc989b57d</anchor>
      <arglist>(TreeNodePtr that)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::string</type>
      <name>toString</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>a652d0e9aaa8872b23a243cd3c6f99364</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual TreeNodePtr</type>
      <name>getThisPtr</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>a75ff49aa8e26361513437b6a6e33b1a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>std::vector&lt; TreeNodePtr &gt;</type>
      <name>_children</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>a9b3d34db0b448ed488a51014696e5612</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>bool</type>
      <name>_isRoot</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>a742ef5e35f9ca2e1c87a5490198666d1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>size_t</type>
      <name>_depth</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>a1b388ad30605691e38a46ccab0fa971c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ParentNodePtr</type>
      <name>_parent</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>af5e9318ef2a7dc9103ed3ba88a73dbd3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TraverseAction</type>
      <name>_state</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>abb8396ab89c164c522e2e803f3937275</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="private">
      <type>TreeNodePtr</type>
      <name>searchParent</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>a5d1d0258c71a615d1922a40618355af9</anchor>
      <arglist>(TreeNodePtr target)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TreeTraverse</name>
    <filename>classTreeTraverse.html</filename>
    <member kind="function">
      <type></type>
      <name>TreeTraverse</name>
      <anchorfile>classTreeTraverse.html</anchorfile>
      <anchor>ae1d8d125ded83054c23fc7601f5bfdc0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TreeTraverse</name>
      <anchorfile>classTreeTraverse.html</anchorfile>
      <anchor>a75a60d5749f9825176eb5f94acda10e2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>apply</name>
      <anchorfile>classTreeTraverse.html</anchorfile>
      <anchor>a94ceec8285d6aec048891a1f7438336f</anchor>
      <arglist>(TreeNodePtr, TraverseStrategy)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TreeNodeStack &amp;</type>
      <name>getNodeStack</name>
      <anchorfile>classTreeTraverse.html</anchorfile>
      <anchor>a43adef79f7c47ef263d8ced13a396440</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>doInOrder</name>
      <anchorfile>classTreeTraverse.html</anchorfile>
      <anchor>a909db7c4d60429e2991a9ebeee5a66b5</anchor>
      <arglist>(TreeNodePtr node)</arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>doPostOrder</name>
      <anchorfile>classTreeTraverse.html</anchorfile>
      <anchor>ae56bb39ee4e7e086d3b1e977f503a883</anchor>
      <arglist>(TreeNodePtr node)</arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>doPreOrder</name>
      <anchorfile>classTreeTraverse.html</anchorfile>
      <anchor>a6024c5e5b66cf06114b86743f207b0ba</anchor>
      <arglist>(TreeNodePtr node)</arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>doBreadthFirst</name>
      <anchorfile>classTreeTraverse.html</anchorfile>
      <anchor>adb45d73dc2fedf17850f4aaa066f7b05</anchor>
      <arglist>(TreeNodePtr node)</arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>doDepthFirst</name>
      <anchorfile>classTreeTraverse.html</anchorfile>
      <anchor>a8e974542fd0c81701d3438a71c54fb9e</anchor>
      <arglist>(TreeNodePtr node)</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>TreeNodeStack</type>
      <name>_stack</name>
      <anchorfile>classTreeTraverse.html</anchorfile>
      <anchor>af719ad7786747855d49988cab5d3a8ee</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TreeWalker</name>
    <filename>classTreeWalker.html</filename>
    <base>Visitor</base>
    <member kind="function">
      <type></type>
      <name>TreeWalker</name>
      <anchorfile>classTreeWalker.html</anchorfile>
      <anchor>ae0ee9fa909d78735790a9cd721e1cb90</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TreeWalker</name>
      <anchorfile>classTreeWalker.html</anchorfile>
      <anchor>a149fbfeb561855e4ea2fb1ed29750baf</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>walk</name>
      <anchorfile>classTreeWalker.html</anchorfile>
      <anchor>ac961e29efd1cc6fa776f3cd2c40e048a</anchor>
      <arglist>(VisitedTreeNodePtr ptr)=0</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual int</type>
      <name>visit</name>
      <anchorfile>classTreeWalker.html</anchorfile>
      <anchor>ad42b3a79f21114d0275a94797b3292cf</anchor>
      <arglist>(VisitedObjectPtr ptr)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="pure">
      <type>virtual int</type>
      <name>startWalking</name>
      <anchorfile>classTreeWalker.html</anchorfile>
      <anchor>ab8bb2ca446b06f799e130efc0d754f9c</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="pure">
      <type>virtual int</type>
      <name>stopWalking</name>
      <anchorfile>classTreeWalker.html</anchorfile>
      <anchor>aac6bf1994be5bab51c3fbad3eb3bb7b7</anchor>
      <arglist>()=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TypeCastException</name>
    <filename>classTypeCastException.html</filename>
    <base>Exception</base>
    <member kind="function">
      <type></type>
      <name>TypeCastException</name>
      <anchorfile>classTypeCastException.html</anchorfile>
      <anchor>a575bd9dc0eda2a9bb98b56ce927894bd</anchor>
      <arglist>(const std::string &amp;msg)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TypeCastException</name>
      <anchorfile>classTypeCastException.html</anchorfile>
      <anchor>a6ac20d90c8058adf3535649b899eff53</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>what</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>a380f0477d9ef319911e7a8167bd47f1f</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::string</type>
      <name>getTrace</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>a82fcc8b1a3db2d25686ab87af5ae8048</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::string</type>
      <name>getShortDescrption</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>a059dfe1d84ff0f8cdd1f2e60a4411fe8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>std::string</type>
      <name>_shortDesc</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>a1f60ffc307534eadd3145f3e310c49cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>std::string</type>
      <name>_trace</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>ae1ff69c4cefeb0dbb5364e3e1bb57fd3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>std::string</type>
      <name>_message</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>aab929939472fd18508ce96c17469a834</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>UndefinedSymbolException</name>
    <filename>classUndefinedSymbolException.html</filename>
    <base>Exception</base>
    <member kind="function">
      <type></type>
      <name>UndefinedSymbolException</name>
      <anchorfile>classUndefinedSymbolException.html</anchorfile>
      <anchor>a7d4b17299561db2eaf008ddde5bd6757</anchor>
      <arglist>(const std::string &amp;msg)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~UndefinedSymbolException</name>
      <anchorfile>classUndefinedSymbolException.html</anchorfile>
      <anchor>a82f13914475f3e253ccff4b10bcf6a52</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>what</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>a380f0477d9ef319911e7a8167bd47f1f</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::string</type>
      <name>getTrace</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>a82fcc8b1a3db2d25686ab87af5ae8048</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::string</type>
      <name>getShortDescrption</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>a059dfe1d84ff0f8cdd1f2e60a4411fe8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>std::string</type>
      <name>_shortDesc</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>a1f60ffc307534eadd3145f3e310c49cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>std::string</type>
      <name>_trace</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>ae1ff69c4cefeb0dbb5364e3e1bb57fd3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>std::string</type>
      <name>_message</name>
      <anchorfile>classException.html</anchorfile>
      <anchor>aab929939472fd18508ce96c17469a834</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>VisitedObject</name>
    <filename>classVisitedObject.html</filename>
    <member kind="function">
      <type></type>
      <name>VisitedObject</name>
      <anchorfile>classVisitedObject.html</anchorfile>
      <anchor>a62a8bbe86b13cfae9d6cc1c4e4f180f5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~VisitedObject</name>
      <anchorfile>classVisitedObject.html</anchorfile>
      <anchor>a0d276bae03bb02fe240e16a1f06d2cce</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>accept</name>
      <anchorfile>classVisitedObject.html</anchorfile>
      <anchor>ae0693bc8a65a5df1b4dcaceb295d81f0</anchor>
      <arglist>(VisitorPtr visitor)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>VisitedTreeNode</name>
    <filename>classVisitedTreeNode.html</filename>
    <base>TreeNode</base>
    <base>VisitedObject</base>
    <member kind="function">
      <type></type>
      <name>VisitedTreeNode</name>
      <anchorfile>classVisitedTreeNode.html</anchorfile>
      <anchor>a03d34c4c0cf15919cc7dd245daca96a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~VisitedTreeNode</name>
      <anchorfile>classVisitedTreeNode.html</anchorfile>
      <anchor>aaa07e942c70095c1e5cc4a004e1da69a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>accept</name>
      <anchorfile>classVisitedTreeNode.html</anchorfile>
      <anchor>a23d80e8bc6f8edf1b7cac3ba9ce7b3a5</anchor>
      <arglist>(VisitorPtr visitor)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>apply</name>
      <anchorfile>classVisitedTreeNode.html</anchorfile>
      <anchor>a3a4934d090b02213c28e2780b646cb89</anchor>
      <arglist>(TreeWalkerPtr walker, TraverseStrategy strategy)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>insertChild</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>a8ef15b0f66720ff142b445007bc14546</anchor>
      <arglist>(TreeNodePtr childPtr, ParentNodePtr parentPtr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>insertChild</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>af7c03dc92e2912d7c4ce62bd5ef90685</anchor>
      <arglist>(TreeNodePtr childPtr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>insertChildren</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>a65e43cc7982fc28502793777a29a55dd</anchor>
      <arglist>(std::vector&lt; TreeNodePtr &gt; &amp;childrenPtr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual size_t</type>
      <name>getNumOfChildren</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>a0add7cbf0c98194fd6b3ba42dd79eb80</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual size_t</type>
      <name>getChildIndexOf</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>ac575d02736e030d030a742f871fad830</anchor>
      <arglist>(TreeNodePtr ptr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isChildAt</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>abef06530a053d061d0881812e9f1a094</anchor>
      <arglist>(size_t i)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TreeNodePtr</type>
      <name>getChildAt</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>af187913777d7dd465b65601cf8019216</anchor>
      <arglist>(size_t index)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>removeChildAt</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>ac45bf607c3f06556630068dab3f10ca6</anchor>
      <arglist>(size_t)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>replaceChildAt</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>ada1dd865827d890ebdfbeb29b21263e0</anchor>
      <arglist>(size_t, TreeNodePtr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>removeAllChildren</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>a2bcdcb3e4d1b244068bc05a7e059afee</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ParentNodePtr</type>
      <name>getParent</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>af3b90e5d3c528e9fd851ebfb37907e48</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isRoot</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>aa9fc2bc19c36ccb2b222fde4f530e988</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isLeaf</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>aa237aa34d056a4731f33e65d33a40584</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual size_t</type>
      <name>getDepth</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>a5f0878faad85d2336beda90c20a14bb1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setState</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>a1f19d84761a7bce22ea15c35ed847eef</anchor>
      <arglist>(TraverseAction action)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TraverseAction</type>
      <name>getState</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>a9e1b11b9e2d20f1c15efa80d7d4a0400</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setParent</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>ac39280b56824bfdb1b0abe0fb6ed4dac</anchor>
      <arglist>(ParentNodePtr ptr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>replace</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>a0fa9b537f271ac5f38a655bcc989b57d</anchor>
      <arglist>(TreeNodePtr that)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::string</type>
      <name>toString</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>a652d0e9aaa8872b23a243cd3c6f99364</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual TreeNodePtr</type>
      <name>getThisPtr</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>a75ff49aa8e26361513437b6a6e33b1a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>std::vector&lt; TreeNodePtr &gt;</type>
      <name>_children</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>a9b3d34db0b448ed488a51014696e5612</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>bool</type>
      <name>_isRoot</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>a742ef5e35f9ca2e1c87a5490198666d1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>size_t</type>
      <name>_depth</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>a1b388ad30605691e38a46ccab0fa971c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ParentNodePtr</type>
      <name>_parent</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>af5e9318ef2a7dc9103ed3ba88a73dbd3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TraverseAction</type>
      <name>_state</name>
      <anchorfile>classTreeNode.html</anchorfile>
      <anchor>abb8396ab89c164c522e2e803f3937275</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>doInOrder</name>
      <anchorfile>classVisitedTreeNode.html</anchorfile>
      <anchor>ad1783154d7fe63b9ce68e667873494a0</anchor>
      <arglist>(TreeWalkerPtr walker)</arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>doPostOrder</name>
      <anchorfile>classVisitedTreeNode.html</anchorfile>
      <anchor>aba777749bc6fc85a5cee4385118c06f0</anchor>
      <arglist>(TreeWalkerPtr walker)</arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>doPreOrder</name>
      <anchorfile>classVisitedTreeNode.html</anchorfile>
      <anchor>a25a4d1158349c72db499fbe3586be024</anchor>
      <arglist>(TreeWalkerPtr walker)</arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>doBreadthFirst</name>
      <anchorfile>classVisitedTreeNode.html</anchorfile>
      <anchor>af2815e6a1795e3cc9392746b0282a180</anchor>
      <arglist>(TreeWalkerPtr walker)</arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>doDepthFirst</name>
      <anchorfile>classVisitedTreeNode.html</anchorfile>
      <anchor>ab1baf65e2f12e9ccafd3480a9e1ea4fa</anchor>
      <arglist>(TreeWalkerPtr walker)</arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>visitChildren</name>
      <anchorfile>classVisitedTreeNode.html</anchorfile>
      <anchor>aa36846aa2aa81799cae0f01c26efdfed</anchor>
      <arglist>(TreeWalkerPtr walker)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Visitor</name>
    <filename>classVisitor.html</filename>
    <member kind="function">
      <type></type>
      <name>Visitor</name>
      <anchorfile>classVisitor.html</anchorfile>
      <anchor>a2a243fcf1a532722b2c0b857a327937c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Visitor</name>
      <anchorfile>classVisitor.html</anchorfile>
      <anchor>a2c9cc57ee3a518a193ea88384cbf3937</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="pure">
      <type>virtual int</type>
      <name>visit</name>
      <anchorfile>classVisitor.html</anchorfile>
      <anchor>a85c682bfe317df069af282f95e96b431</anchor>
      <arglist>(VisitedObjectPtr ptr)=0</arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>util</name>
    <filename>namespaceutil.html</filename>
    <class kind="class">util::Conditions</class>
    <class kind="class">util::Converts</class>
    <class kind="class">util::Strings</class>
  </compound>
</tagfile>
