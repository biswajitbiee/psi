
// Class library implementation of PSS-tool build-model callback
#include "api/IModel.h"
#include "classlib/TypeRegistry.h"
#include "classlib/Elaborator.h"
#include "classlib/Action.h"

using namespace psi;

static Elaborator elab;

void psi_build_model(psi_api::IModel *model) {
    elab.elaborate(TypeRegistry::global(), model);
}

#include <map>

static std::map<psi_api::insthandle_t,Type*> handle2inst_map;

void psi_post_solve(psi_api::insthandle_t handle) {
    Type* inst = handle2inst_map[handle];
    if (inst == 0) {
        Type* type_decl = elab.getTypeDecl(handle);
        if (type_decl  == 0) {
            // some kind of error?
        }
        inst = type_decl->createInstance(handle);
        handle2inst_map[handle] = inst;
        if (dynamic_cast<Struct*>(inst) != nullptr) {
        	static_cast<Struct*>(inst)->post_solve();
        } else if (dynamic_cast<Action*>(inst) != nullptr) {
        	static_cast<Action*>(inst)->post_solve();
        };
    }
}
