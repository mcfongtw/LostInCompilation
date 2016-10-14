#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <string>
#include <exception>

/**
 * A generic exception inherits from C++ std::exception
 */
class Exception : public std::exception {

public:
	Exception();

	Exception(const std::string& prefix);

	Exception(const std::string& prefix, const std::string& msg);

	virtual ~Exception() throw ();

	virtual const char* what() const throw ();

protected:
	std::string _message;
};

// /////////////////////////////////////////////////////////////////////

/**
 * An exception dedicated for accessing an object which is a null pointer
 */
class NullPointerException : public Exception {

public:
	NullPointerException(const std::string& msg);

	virtual ~NullPointerException() throw ();
};

// ////////////////////////////////////////////////////////////////////////////

/**
 * An exception dedicated for out of memory error
 */
class OutOfMemoryException : public Exception {

public:
	OutOfMemoryException(const std::string& msg);

	virtual ~OutOfMemoryException() throw ();
};

// ////////////////////////////////////////////////////////////////////////////

/**
 * An exception dedicated for undefined symbol or functionality
 */
class UndefinedSymbolException : public Exception {

public:
	UndefinedSymbolException(const std::string& msg);

	virtual ~UndefinedSymbolException() throw ();
};

// ////////////////////////////////////////////////////////////////////////////
/**
 * An exception dedicated for when program enters a wrong state.
 */
class IllegalStateException : public Exception {

public:
	IllegalStateException(const std::string& msg);

	virtual ~IllegalStateException() throw ();
};

// ////////////////////////////////////////////////////////////////////////////
/**
 * An exception dedicated for receiving a wrong argument (parameter)
 */
class IllegalArgumentException : public Exception {

public:
	IllegalArgumentException(const std::string& msg);

	virtual ~IllegalArgumentException() throw ();
};

// ////////////////////////////////////////////////////////////////////////////
/**
 * An exception dedicated for casting a lvalue to a wrong type
 */
class TypeCastException : public Exception {

public:
	TypeCastException(const std::string& msg);

	virtual ~TypeCastException() throw ();
};

// ////////////////////////////////////////////////////////////////////////////

#endif /* EXCEPTION_H_ */
