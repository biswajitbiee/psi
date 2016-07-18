#ifndef INCLUDED_PSI_MACROS_H
#define INCLUDED_PSI_MACROS_H

/**
 * Helper macro for declaring fields.
 */
#define psi_field(name) name { this, #name }

/**
 * Helper macro for declaring the constructor
 * and type registration for PSI-derived classes
 */
#define psi_ctor(_name, _super) \
	public: \
	_name (Type *p=0, psi_name name=#_name, \
			_super *super=TypeRgy<_super>::valid()?TypeRgy<_super>::type_id():0) : _super(p, name, super) { }

/**
 * Helper macro to register a global namespace type
 */
#define psi_global_type(_name) \
		TypeDecl<_name>		_##_name##_t

/**
 * Helper macro to register a non-global namespace type
 */
#define psi_type(_name) \
		TypeDecl<_name>		_##_name##_t {this}

#define psi_typeid(T) \
	(*TypeRgy<T>::type_id())

#endif /* INCLUDED_PSI_MACROS_H */
