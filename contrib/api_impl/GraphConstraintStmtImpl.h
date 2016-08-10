/*
 *  GraphConstraintStmtImplImpl.h
 *  Date: 9th July, 2016
 *  Author: biswajit
 */

#ifndef __GRAPH_CONSTRAINT_STMT_IMPL_H__
#define __GRAPH_CONSTRAINT_STMT_IMPL_H__

#include "api/IGraphConstraintStmt.h"

using namespace psi_api;

namespace psi {
  class GraphConstraintStmtImpl : public IGraphConstraintStmt
  {
    public:
    IGraphStmt::GraphStmtType getStmtType() const override;
    void add(IConstraint* c) override;
    const std::vector<IConstraint*> &getConstraints() const override;

    private:
    std::vector<IConstraint*> m_constraints;
  };
}

#endif //__GRAPH_CONSTRAINT_STMT_IMPL_H__
