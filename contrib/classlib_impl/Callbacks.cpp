
// Class library implementation of PSS-tool build-model callback
#include "api/IModel.h"
#include "Elaborator.h"
#include "classlib/Action.h"
#include "ModelImp.h"
#include <iostream>

using namespace pss;

static Elaborator elab;

void psi_build_model(psi_api::IModel *model) {
    elab.elaborate(ModelImp::global(), model);
}

#include <map>

static std::map<psi_api::insthandle_t,BaseItem*> handle2inst_map;

void psi_post_solve(psi_api::insthandle_t handle) {
    BaseItem* inst = handle2inst_map[handle];
    if (inst == 0) {
        BaseItem* type_decl = elab.getTypeDecl(handle);
        if (type_decl  == 0) {
            // some kind of error?
        }
        inst = type_decl->impl()->Clone();
        if(inst == nullptr)
        {
        	std::cout << "inst is null" << std::endl;
          return;
        }
        inst->impl()->setTypeData(type_decl);
        inst->impl()->setHandle(handle);
        handle2inst_map[handle] = inst;

        if (inst->impl()->getObjectType() == BaseItemImp::TypeStruct) 
        {
        	static_cast<Struct*>(inst)->post_solve();
        } 
        else if (inst->impl()->getObjectType() == BaseItemImp::TypeAction) 
        {
        	static_cast<Action*>(inst)->post_solve();
        }
    }
}
