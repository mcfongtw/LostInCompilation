#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <string>
#include <exception>

/**
 * A base exception class that inherits from C++ std::exception. This should be used as a wrapper of an error cause and detailed message.
 *
 * @since 0.1
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
 *
 * @since 0.1
 */
class NullPointerException : public Exception {

public:
	NullPointerException(const std::string& msg);

	virtual ~NullPointerException() throw ();
};

// ////////////////////////////////////////////////////////////////////////////

/**
 * An exception dedicated for out of memory error
 *
 * @since 0.1
 */
class OutOfMemoryException : public Exception {

public:
	OutOfMemoryException(const std::string& msg);

	virtual ~OutOfMemoryException() throw ();
};

// ////////////////////////////////////////////////////////////////////////////

/**
 * An exception dedicated for undefined symbol or functionality
 *
 * @since 0.1
 */
class UndefinedSymbolException : public Exception {

public:
	UndefinedSymbolException(const std::string& msg);

	virtual ~UndefinedSymbolException() throw ();
};

// ////////////////////////////////////////////////////////////////////////////
/**
 * An exception dedicated for when program enters a wrong state.
 *
 * @since 0.1
 */
class IllegalStateException : public Exception {

public:
	IllegalStateException(const std::string& msg);

	virtual ~IllegalStateException() throw ();
};

// ////////////////////////////////////////////////////////////////////////////
/**
 * An exception dedicated for receiving a wrong argument (parameter)
 *
 * @since 0.1
 */
class IllegalArgumentException : public Exception {

public:
	IllegalArgumentException(const std::string& msg);

	virtual ~IllegalArgumentException() throw ();
};

// ////////////////////////////////////////////////////////////////////////////
/**
 * An exception dedicated for casting a lvalue to a wrong type
 *
 * @since 0.1
 */
class TypeCastException : public Exception {

public:
	TypeCastException(const std::string& msg);

	virtual ~TypeCastException() throw ();
};

// ////////////////////////////////////////////////////////////////////////////

#endif /* EXCEPTION_H_ */
