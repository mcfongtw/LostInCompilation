Release History
===============

**0.1-alpha**
- Released on Apr. 2017
- This release focuses on designing a (simple) application to realize a compiler infrastructure. The project is 
modularized into 2 libraries and 1 example application. The libraries include lib-shacat for fundemental data structure and infrastructure components and lib-compiler shares common compiler comonent. There is an example application, calculator, namely to perform arthimetic evaluation. The infrastructure begins with lexical analysis (via flex), parser generation (via bison), and then AST intepretation and arithematic evaluation. A (non-interactive) console-based application is also implemented as executable. 
- Several feature concepts are introduced including symbol table to keep trace symbol states at runtime; a source code to improve debuggability in terms of exact location of a pice of source code; an event-listener approach  to collect runtime error statistics; built-in (C)math functions.

