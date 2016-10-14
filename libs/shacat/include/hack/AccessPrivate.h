/*
 * AccessPrivate.h
 *
 *  Created on: Jun 13, 2014
 *      Author: Michael Fong
 */

#ifndef ACCESSPRIVATE_H_
#define ACCESSPRIVATE_H_

/**
 * Inspired by 'http://bloglitb.blogspot.tw/2010/07/access-to-private-members-thats-easy.html'
 * Usage:
 *
 * Assume a class:
 *
 * Class A {
 * 	private:
 * 	int func() {}
 * }
 *
 * struct APrivate_func { typedef int(A::*type)(); };
 * template class HackPrivate<APrivate_func, &A::func>;
 *
 * A a;
 * (a.*HackProxy<APrivate_func>::privateFuncPtr)();
 */

template<typename ProxyName>
struct HackProxy {
  /* export it ... */
  typedef typename ProxyName::type type;
  static type privateFuncPtr;
};

template<typename ProxyName>
typename HackProxy<ProxyName>::type HackProxy<ProxyName>::privateFuncPtr;

template<typename ProxyName, typename ProxyName::type funcPtr>
struct HackPrivate : HackProxy<ProxyName> {
  struct privateFuncPtrHolder {
    privateFuncPtrHolder() { HackProxy<ProxyName>::privateFuncPtr = funcPtr; }
  };
  static privateFuncPtrHolder funcPtrObj;
};

template<typename ProxyName, typename ProxyName::type funcPtr>
typename HackPrivate<ProxyName, funcPtr>::privateFuncPtrHolder HackPrivate<ProxyName, funcPtr>::funcPtrObj;

#endif /* ACCESSPRIVATE_H_ */
