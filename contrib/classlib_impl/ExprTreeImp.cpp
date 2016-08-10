#include "classlib/ExprTree.h"
#include "ExprCoreList.h"
#include "ExprImp.h"
#include <algorithm>
#include <iterator>

namespace pss {
  ExprTree::ExprTree() : Expr(ExprImp(new ExprCoreList()))
  {
    imp().ptr()->setOp(ExprImp::Tree);
  }

  ExprTree::ExprTree(const Expr& expr) : Expr(ExprImp(new ExprCoreList()))
  {
    imp().ptr()->setOp(ExprImp::Tree);

    ExprCoreList* plist = static_cast<ExprCoreList*>(m_core->ptr());
    plist->getExprList().emplace_back(expr.imp());
  }
      
  ExprTree::ExprTree(std::initializer_list<Expr> exprlist) : Expr(ExprImp(new ExprCoreList()))
  {
    imp().ptr()->setOp(ExprImp::Tree);

    ExprCoreList* plist = static_cast<ExprCoreList*>(m_core->ptr());

    auto& list = plist->getExprList();
    std::transform(exprlist.begin(), exprlist.end(), std::back_inserter(list),
                    [](const Expr& expr) { return expr.imp(); });
  }

  void ExprTree::add(const Expr& item)
  {
    ExprCoreList* plist = static_cast<ExprCoreList*>(m_core->ptr());
    plist->getExprList().emplace_back(item.imp());
  }
}
