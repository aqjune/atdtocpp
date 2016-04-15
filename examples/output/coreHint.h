struct TyAddAssociative{
public : 
  TyAddAssociative(std::unique_ptr<TyRegister> _x, std::unique_ptr<TyRegister> _y, std::unique_ptr<TyRegister> _z, std::unique_ptr<TyConstInt> _c1, std::unique_ptr<TyConstInt> _c2, std::unique_ptr<TyConstInt> _c3, std::unique_ptr<TySize> _sz);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> x;
  std::unique_ptr<TyRegister> y;
  std::unique_ptr<TyRegister> z;
  std::unique_ptr<TyConstInt> c1;
  std::unique_ptr<TyConstInt> c2;
  std::unique_ptr<TyConstInt> c3;
  std::unique_ptr<TySize> sz;
};
struct TyAddCommutative{
public : 
  TyAddCommutative(std::unique_ptr<TyRegister> _z, std::unique_ptr<TyValue> _x, std::unique_ptr<TyValue> _y, std::unique_ptr<TySize> _sz);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> z;
  std::unique_ptr<TyValue> x;
  std::unique_ptr<TyValue> y;
  std::unique_ptr<TySize> sz;
};
struct TyAddConstNot{
public : 
  TyAddConstNot(std::unique_ptr<TyRegister> _z, std::unique_ptr<TyRegister> _y);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> z;
  std::unique_ptr<TyRegister> y;
};
struct TyAddDistSub{
public : 
  TyAddDistSub(std::unique_ptr<TyRegister> _z, std::unique_ptr<TyRegister> _minusx, std::unique_ptr<TyRegister> _minusy, std::unique_ptr<TyRegister> _w);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> z;
  std::unique_ptr<TyRegister> minusx;
  std::unique_ptr<TyRegister> minusy;
  std::unique_ptr<TyRegister> w;
};
struct TyAddMask{
public : 
  TyAddMask(std::unique_ptr<TyRegister> _z, std::unique_ptr<TyRegister> _y, std::unique_ptr<TyRegister> _yp);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> z;
  std::unique_ptr<TyRegister> y;
  std::unique_ptr<TyRegister> yp;
};
struct TyAddOnebit{
public : 
  TyAddOnebit(std::unique_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> z;
};
struct TyAddSelectZero{
public : 
  TyAddSelectZero(std::unique_ptr<TyRegister> _z, std::unique_ptr<TyRegister> _x, std::unique_ptr<TyRegister> _y);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> z;
  std::unique_ptr<TyRegister> x;
  std::unique_ptr<TyRegister> y;
};
struct TyAddSelectZero2{
public : 
  TyAddSelectZero2(std::unique_ptr<TyRegister> _z, std::unique_ptr<TyRegister> _x, std::unique_ptr<TyRegister> _y);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> z;
  std::unique_ptr<TyRegister> x;
  std::unique_ptr<TyRegister> y;
};
struct TyAddShift{
public : 
  TyAddShift(std::unique_ptr<TyRegister> _y, std::unique_ptr<TyValue> _v, std::unique_ptr<TySize> _sz);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> y;
  std::unique_ptr<TyValue> v;
  std::unique_ptr<TySize> sz;
};
struct TyAddSignbit{
public : 
  TyAddSignbit(std::unique_ptr<TyRegister> _x, std::unique_ptr<TyValue> _e1, std::unique_ptr<TyValue> _e2, std::unique_ptr<TySize> _sz);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> x;
  std::unique_ptr<TyValue> e1;
  std::unique_ptr<TyValue> e2;
  std::unique_ptr<TySize> sz;
};
struct TyAddSub{
public : 
  TyAddSub(std::unique_ptr<TyRegister> _minusy, std::unique_ptr<TyRegister> _z, std::unique_ptr<TyValue> _x, std::unique_ptr<TyValue> _y, std::unique_ptr<TySize> _sz);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> minusy;
  std::unique_ptr<TyRegister> z;
  std::unique_ptr<TyValue> x;
  std::unique_ptr<TyValue> y;
  std::unique_ptr<TySize> sz;
};
struct TyAddZextBool{
public : 
  TyAddZextBool(std::unique_ptr<TyRegister> _x, std::unique_ptr<TyRegister> _y);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> x;
  std::unique_ptr<TyRegister> y;
};
struct TyAndDeMorgan{
public : 
  TyAndDeMorgan(std::unique_ptr<TyRegister> _z, std::unique_ptr<TyRegister> _x, std::unique_ptr<TyRegister> _y, std::unique_ptr<TyRegister> _z2);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> z;
  std::unique_ptr<TyRegister> x;
  std::unique_ptr<TyRegister> y;
  std::unique_ptr<TyRegister> z2;
};
struct TyCommand{
public : 
  virtual void serialize(cereal::JSONOutputArchive& archive) const = 0;
};
struct TyConstFloat{
public : 
  TyConstFloat(double _float_value, std::unique_ptr<TyFloatType> _float_type);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  double float_value;
  std::unique_ptr<TyFloatType> float_type;
};
struct TyConstInt{
public : 
  TyConstInt(int _int_value, std::unique_ptr<TyIntType> _int_type);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  int int_value;
  std::unique_ptr<TyIntType> int_type;
};
struct TyConstant{
public : 
  virtual void serialize(cereal::JSONOutputArchive& archive) const = 0;
};
struct TyDivMone{
public : 
  TyDivMone(std::unique_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> z;
};
struct TyDivSubSrem{
public : 
  TyDivSubSrem(std::unique_ptr<TyRegister> _z, std::unique_ptr<TyRegister> _b, std::unique_ptr<TyRegister> _a);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> z;
  std::unique_ptr<TyRegister> b;
  std::unique_ptr<TyRegister> a;
};
struct TyDivSubUrem{
public : 
  TyDivSubUrem(std::unique_ptr<TyRegister> _z, std::unique_ptr<TyRegister> _b, std::unique_ptr<TyRegister> _a);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> z;
  std::unique_ptr<TyRegister> b;
  std::unique_ptr<TyRegister> a;
};
struct TyExpr{
public : 
  virtual void serialize(cereal::JSONOutputArchive& archive) const = 0;
};
struct TyFloatType{
public : 
  virtual void serialize(cereal::JSONOutputArchive& archive) const = 0;
};
struct TyHints{
public : 
  TyHints(std::string _module_id, std::string _function_id, std::string _opt_name, std::vector<std::unique_ptr<TyNopPosition>> _src_nop_positions, std::vector<std::unique_ptr<TyNopPosition>> _tgt_nop_positions, std::vector<std::unique_ptr<TyCommand>> _commands);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::string module_id;
  std::string function_id;
  std::string opt_name;
  std::vector<std::unique_ptr<TyNopPosition>> src_nop_positions;
  std::vector<std::unique_ptr<TyNopPosition>> tgt_nop_positions;
  std::vector<std::unique_ptr<TyCommand>> commands;
};
struct TyInfrule{
public : 
  virtual void serialize(cereal::JSONOutputArchive& archive) const = 0;
};
struct TyIntType{
public : 
  virtual void serialize(cereal::JSONOutputArchive& archive) const = 0;
};
struct TyMulAddDistributive{
public : 
  TyMulAddDistributive(std::unique_ptr<TyRegister> _z, std::unique_ptr<TyRegister> _x, std::unique_ptr<TyRegister> _y, std::unique_ptr<TyRegister> _w);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> z;
  std::unique_ptr<TyRegister> x;
  std::unique_ptr<TyRegister> y;
  std::unique_ptr<TyRegister> w;
};
struct TyMulBool{
public : 
  TyMulBool(std::unique_ptr<TyRegister> _z, std::unique_ptr<TyRegister> _x, std::unique_ptr<TyRegister> _y);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> z;
  std::unique_ptr<TyRegister> x;
  std::unique_ptr<TyRegister> y;
};
struct TyMulCommutative{
public : 
  TyMulCommutative(std::unique_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> z;
};
struct TyMulMone{
public : 
  TyMulMone(std::unique_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> z;
};
struct TyMulNeg{
public : 
  TyMulNeg(std::unique_ptr<TyRegister> _z, std::unique_ptr<TyValue> _mx, std::unique_ptr<TyValue> _my, std::unique_ptr<TyValue> _x, std::unique_ptr<TyValue> _y, std::unique_ptr<TySize> _sz);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> z;
  std::unique_ptr<TyValue> mx;
  std::unique_ptr<TyValue> my;
  std::unique_ptr<TyValue> x;
  std::unique_ptr<TyValue> y;
  std::unique_ptr<TySize> sz;
};
struct TyMulShl{
public : 
  TyMulShl(std::unique_ptr<TyRegister> _z, std::unique_ptr<TyRegister> _y);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> z;
  std::unique_ptr<TyRegister> y;
};
struct TyNegVal{
public : 
  TyNegVal(std::unique_ptr<TyConstInt> _c1, std::unique_ptr<TyConstInt> _c2, std::unique_ptr<TySize> _sz);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyConstInt> c1;
  std::unique_ptr<TyConstInt> c2;
  std::unique_ptr<TySize> sz;
};
struct TyNoaliasGlobalAlloca{
public : 
  TyNoaliasGlobalAlloca(std::unique_ptr<TyRegister> _x, std::unique_ptr<TyRegister> _y);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> x;
  std::unique_ptr<TyRegister> y;
};
struct TyNopPosition{
public : 
  virtual void serialize(cereal::JSONOutputArchive& archive) const = 0;
};
struct TyPosition{
public : 
  virtual void serialize(cereal::JSONOutputArchive& archive) const = 0;
};
struct TyPositionCommand{
public : 
  TyPositionCommand(std::unique_ptr<TyScope> _scope, std::string _register_name);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyScope> scope;
  std::string register_name;
};
struct TyPositionPhinode{
public : 
  TyPositionPhinode(std::string _block_name, std::string _prev_block_name);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::string block_name;
  std::string prev_block_name;
};
struct TyPropagate{
public : 
  TyPropagate(std::unique_ptr<TyPropagateObject> _propagate, std::unique_ptr<TyPropagateRange> _propagate_range);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyPropagateObject> propagate;
  std::unique_ptr<TyPropagateRange> propagate_range;
};
struct TyPropagateAlloca{
public : 
  TyPropagateAlloca(std::unique_ptr<TyRegister> _p, std::unique_ptr<TyScope> _scope);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> p;
  std::unique_ptr<TyScope> scope;
};
struct TyPropagateLessdef{
public : 
  TyPropagateLessdef(std::unique_ptr<TyExpr> _lhs, std::unique_ptr<TyExpr> _rhs, std::unique_ptr<TyScope> _scope);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyExpr> lhs;
  std::unique_ptr<TyExpr> rhs;
  std::unique_ptr<TyScope> scope;
};
struct TyPropagateNoalias{
public : 
  TyPropagateNoalias(std::unique_ptr<TyRegister> _lhs, std::unique_ptr<TyRegister> _rhs, std::unique_ptr<TyScope> _scope);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> lhs;
  std::unique_ptr<TyRegister> rhs;
  std::unique_ptr<TyScope> scope;
};
struct TyPropagateObject{
public : 
  virtual void serialize(cereal::JSONOutputArchive& archive) const = 0;
};
struct TyPropagateRange{
public : 
  virtual void serialize(cereal::JSONOutputArchive& archive) const = 0;
};
struct TyRegister{
public : 
  TyRegister(std::string _name, std::unique_ptr<TyTag> _tag);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::string name;
  std::unique_ptr<TyTag> tag;
};
struct TyRemNeg{
public : 
  TyRemNeg(std::unique_ptr<TyRegister> _z, std::unique_ptr<TyRegister> _my);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> z;
  std::unique_ptr<TyRegister> my;
};
struct TyReplaceRhs{
public : 
  TyReplaceRhs(std::unique_ptr<TyRegister> _x, std::unique_ptr<TyValue> _y, std::unique_ptr<TyExpr> _e1, std::unique_ptr<TyExpr> _e2, std::unique_ptr<TyExpr> _e2prime);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> x;
  std::unique_ptr<TyValue> y;
  std::unique_ptr<TyExpr> e1;
  std::unique_ptr<TyExpr> e2;
  std::unique_ptr<TyExpr> e2prime;
};
struct TyScope{
public : 
  virtual void serialize(cereal::JSONOutputArchive& archive) const = 0;
};
struct TySimplifyAndSame{
public : 
  TySimplifyAndSame(std::unique_ptr<TyRegister> _x, std::unique_ptr<TyValue> _a, std::unique_ptr<TySize> _s);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> x;
  std::unique_ptr<TyValue> a;
  std::unique_ptr<TySize> s;
};
struct TySize{
public : 
  virtual void serialize(cereal::JSONOutputArchive& archive) const = 0;
};
struct TySubAdd{
public : 
  TySubAdd(std::unique_ptr<TyRegister> _z, std::unique_ptr<TyValue> _my, std::unique_ptr<TyRegister> _x, std::unique_ptr<TyValue> _y, std::unique_ptr<TySize> _sz);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> z;
  std::unique_ptr<TyValue> my;
  std::unique_ptr<TyRegister> x;
  std::unique_ptr<TyValue> y;
  std::unique_ptr<TySize> sz;
};
struct TySubConstAdd{
public : 
  TySubConstAdd(std::unique_ptr<TyRegister> _y, std::unique_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> y;
  std::unique_ptr<TyRegister> z;
};
struct TySubConstNot{
public : 
  TySubConstNot(std::unique_ptr<TyRegister> _y, std::unique_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> y;
  std::unique_ptr<TyRegister> z;
};
struct TySubMone{
public : 
  TySubMone(std::unique_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> z;
};
struct TySubOnebit{
public : 
  TySubOnebit(std::unique_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> z;
};
struct TySubRemove{
public : 
  TySubRemove(std::unique_ptr<TyRegister> _z, std::unique_ptr<TyRegister> _y, std::unique_ptr<TyValue> _a, std::unique_ptr<TyValue> _b, std::unique_ptr<TySize> _sz);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> z;
  std::unique_ptr<TyRegister> y;
  std::unique_ptr<TyValue> a;
  std::unique_ptr<TyValue> b;
  std::unique_ptr<TySize> sz;
};
struct TySubRemove2{
public : 
  TySubRemove2(std::unique_ptr<TyRegister> _y, std::unique_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> y;
  std::unique_ptr<TyRegister> z;
};
struct TySubSdiv{
public : 
  TySubSdiv(std::unique_ptr<TyRegister> _y, std::unique_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> y;
  std::unique_ptr<TyRegister> z;
};
struct TySubShl{
public : 
  TySubShl(std::unique_ptr<TyRegister> _x, std::unique_ptr<TyRegister> _y, std::unique_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> x;
  std::unique_ptr<TyRegister> y;
  std::unique_ptr<TyRegister> z;
};
struct TyTag{
public : 
  virtual void serialize(cereal::JSONOutputArchive& archive) const = 0;
};
struct TyTransitivity{
public : 
  TyTransitivity(std::unique_ptr<TyExpr> _e1, std::unique_ptr<TyExpr> _e2, std::unique_ptr<TyExpr> _e3);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyExpr> e1;
  std::unique_ptr<TyExpr> e2;
  std::unique_ptr<TyExpr> e3;
};
struct TyTransitivityPointerLhs{
public : 
  TyTransitivityPointerLhs(std::unique_ptr<TyValue> _p, std::unique_ptr<TyValue> _q, std::unique_ptr<TyValue> _v, std::unique_ptr<TyExpr> _loadq);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyValue> p;
  std::unique_ptr<TyValue> q;
  std::unique_ptr<TyValue> v;
  std::unique_ptr<TyExpr> loadq;
};
struct TyTransitivityPointerRhs{
public : 
  TyTransitivityPointerRhs(std::unique_ptr<TyValue> _p, std::unique_ptr<TyValue> _q, std::unique_ptr<TyValue> _v, std::unique_ptr<TyExpr> _loadp);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyValue> p;
  std::unique_ptr<TyValue> q;
  std::unique_ptr<TyValue> v;
  std::unique_ptr<TyExpr> loadp;
};
struct TyValue{
public : 
  virtual void serialize(cereal::JSONOutputArchive& archive) const = 0;
};
struct ConsPhysical : public TyTag{
public : 
  ConsPhysical();
  void serialize(cereal::JSONOutputArchive& archive) const;
};
struct ConsPrevious : public TyTag{
public : 
  ConsPrevious();
  void serialize(cereal::JSONOutputArchive& archive) const;
};
struct ConsGhost : public TyTag{
public : 
  ConsGhost();
  void serialize(cereal::JSONOutputArchive& archive) const;
};
struct ConsIntType : public TyIntType{
public : 
  ConsIntType(int _i);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  int i;
};
struct ConsSize : public TySize{
public : 
  ConsSize(int _i);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  int i;
};
struct ConsId : public TyValue{
public : 
  ConsId(std::unique_ptr<TyRegister> _register);
  static std::unique_ptr<TyValue> make(std::string _name, std::unique_ptr<TyTag> _tag);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> register;
};
struct ConsConstInt : public TyConstant{
public : 
  ConsConstInt(std::unique_ptr<TyConstInt> _const_int);
  static std::unique_ptr<TyConstant> make(int _int_value, std::unique_ptr<TyIntType> _int_type);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyConstInt> const_int;
};
struct ConsHalfType : public TyFloatType{
public : 
  ConsHalfType();
  void serialize(cereal::JSONOutputArchive& archive) const;
};
struct ConsFloatType : public TyFloatType{
public : 
  ConsFloatType();
  void serialize(cereal::JSONOutputArchive& archive) const;
};
struct ConsDoubleType : public TyFloatType{
public : 
  ConsDoubleType();
  void serialize(cereal::JSONOutputArchive& archive) const;
};
struct ConsFP128Type : public TyFloatType{
public : 
  ConsFP128Type();
  void serialize(cereal::JSONOutputArchive& archive) const;
};
struct ConsPPCFP128Type : public TyFloatType{
public : 
  ConsPPCFP128Type();
  void serialize(cereal::JSONOutputArchive& archive) const;
};
struct ConsX86FP80Type : public TyFloatType{
public : 
  ConsX86FP80Type();
  void serialize(cereal::JSONOutputArchive& archive) const;
};
struct ConsConstFloat : public TyConstant{
public : 
  ConsConstFloat(std::unique_ptr<TyConstFloat> _const_float);
  static std::unique_ptr<TyConstant> make(double _float_value, std::unique_ptr<TyFloatType> _float_type);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyConstFloat> const_float;
};
struct ConsConstVal : public TyValue{
public : 
  ConsConstVal(std::unique_ptr<TyConstant> _constant);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyConstant> constant;
};
struct ConsVar : public TyExpr{
public : 
  ConsVar(std::unique_ptr<TyRegister> _register);
  static std::unique_ptr<TyExpr> make(std::string _name, std::unique_ptr<TyTag> _tag);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> register;
};
struct ConsSource : public TyScope{
public : 
  ConsSource();
  void serialize(cereal::JSONOutputArchive& archive) const;
};
struct ConsTarget : public TyScope{
public : 
  ConsTarget();
  void serialize(cereal::JSONOutputArchive& archive) const;
};
struct ConsRhs : public TyExpr{
public : 
  ConsRhs(std::unique_ptr<TyRegister> _register, std::unique_ptr<TyScope> _scope);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> register;
  std::unique_ptr<TyScope> scope;
};
struct ConsConst : public TyExpr{
public : 
  ConsConst(std::unique_ptr<TyConstant> _constant);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyConstant> constant;
};
struct ConsLessdef : public TyPropagateObject{
public : 
  ConsLessdef(std::unique_ptr<TyPropagateLessdef> _propagate_lessdef);
  static std::unique_ptr<TyPropagateObject> make(std::unique_ptr<TyExpr> _lhs, std::unique_ptr<TyExpr> _rhs, std::unique_ptr<TyScope> _scope);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyPropagateLessdef> propagate_lessdef;
};
struct ConsNoalias : public TyPropagateObject{
public : 
  ConsNoalias(std::unique_ptr<TyPropagateNoalias> _propagate_noalias);
  static std::unique_ptr<TyPropagateObject> make(std::unique_ptr<TyRegister> _lhs, std::unique_ptr<TyRegister> _rhs, std::unique_ptr<TyScope> _scope);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyPropagateNoalias> propagate_noalias;
};
struct ConsAlloca : public TyPropagateObject{
public : 
  ConsAlloca(std::unique_ptr<TyPropagateAlloca> _propagate_alloca);
  static std::unique_ptr<TyPropagateObject> make(std::unique_ptr<TyRegister> _p, std::unique_ptr<TyScope> _scope);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyPropagateAlloca> propagate_alloca;
};
struct ConsMaydiff : public TyPropagateObject{
public : 
  ConsMaydiff(std::unique_ptr<TyRegister> _register);
  static std::unique_ptr<TyPropagateObject> make(std::string _name, std::unique_ptr<TyTag> _tag);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> register;
};
struct ConsPhinode : public TyPosition{
public : 
  ConsPhinode(std::unique_ptr<TyPositionPhinode> _position_phinode);
  static std::unique_ptr<TyPosition> make(std::string _block_name, std::string _prev_block_name);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyPositionPhinode> position_phinode;
};
struct ConsCommand : public TyPosition{
public : 
  ConsCommand(std::unique_ptr<TyPositionCommand> _position_command);
  static std::unique_ptr<TyPosition> make(std::unique_ptr<TyScope> _scope, std::string _register_name);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyPositionCommand> position_command;
};
struct ConsBounds : public TyPropagateRange{
public : 
  ConsBounds(std::unique_ptr<TyPosition> _position, std::unique_ptr<TyPosition> _position);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyPosition> position;
  std::unique_ptr<TyPosition> position;
};
struct ConsGlobal : public TyPropagateRange{
public : 
  ConsGlobal();
  void serialize(cereal::JSONOutputArchive& archive) const;
};
struct ConsPropagate : public TyCommand{
public : 
  ConsPropagate(std::unique_ptr<TyPropagate> _propagate);
  static std::unique_ptr<TyCommand> make(std::unique_ptr<TyPropagateObject> _propagate, std::unique_ptr<TyPropagateRange> _propagate_range);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyPropagate> propagate;
};
struct ConsAddAssociative : public TyInfrule{
public : 
  ConsAddAssociative(std::unique_ptr<TyAddAssociative> _add_associative);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyRegister> _x, std::unique_ptr<TyRegister> _y, std::unique_ptr<TyRegister> _z, std::unique_ptr<TyConstInt> _c1, std::unique_ptr<TyConstInt> _c2, std::unique_ptr<TyConstInt> _c3, std::unique_ptr<TySize> _sz);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyAddAssociative> add_associative;
};
struct ConsAddSub : public TyInfrule{
public : 
  ConsAddSub(std::unique_ptr<TyAddSub> _add_sub);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyRegister> _minusy, std::unique_ptr<TyRegister> _z, std::unique_ptr<TyValue> _x, std::unique_ptr<TyValue> _y, std::unique_ptr<TySize> _sz);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyAddSub> add_sub;
};
struct ConsAddCommutative : public TyInfrule{
public : 
  ConsAddCommutative(std::unique_ptr<TyAddCommutative> _add_commutative);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyRegister> _z, std::unique_ptr<TyValue> _x, std::unique_ptr<TyValue> _y, std::unique_ptr<TySize> _sz);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyAddCommutative> add_commutative;
};
struct ConsAddShift : public TyInfrule{
public : 
  ConsAddShift(std::unique_ptr<TyAddShift> _add_shift);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyRegister> _y, std::unique_ptr<TyValue> _v, std::unique_ptr<TySize> _sz);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyAddShift> add_shift;
};
struct ConsAddSignbit : public TyInfrule{
public : 
  ConsAddSignbit(std::unique_ptr<TyAddSignbit> _add_signbit);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyRegister> _x, std::unique_ptr<TyValue> _e1, std::unique_ptr<TyValue> _e2, std::unique_ptr<TySize> _sz);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyAddSignbit> add_signbit;
};
struct ConsAddOnebit : public TyInfrule{
public : 
  ConsAddOnebit(std::unique_ptr<TyAddOnebit> _add_onebit);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyAddOnebit> add_onebit;
};
struct ConsAddZextBool : public TyInfrule{
public : 
  ConsAddZextBool(std::unique_ptr<TyAddZextBool> _add_zext_bool);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyRegister> _x, std::unique_ptr<TyRegister> _y);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyAddZextBool> add_zext_bool;
};
struct ConsAddConstNot : public TyInfrule{
public : 
  ConsAddConstNot(std::unique_ptr<TyAddConstNot> _add_const_not);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyRegister> _z, std::unique_ptr<TyRegister> _y);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyAddConstNot> add_const_not;
};
struct ConsAddMask : public TyInfrule{
public : 
  ConsAddMask(std::unique_ptr<TyAddMask> _add_mask);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyRegister> _z, std::unique_ptr<TyRegister> _y, std::unique_ptr<TyRegister> _yp);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyAddMask> add_mask;
};
struct ConsAddSelectZero : public TyInfrule{
public : 
  ConsAddSelectZero(std::unique_ptr<TyAddSelectZero> _add_select_zero);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyRegister> _z, std::unique_ptr<TyRegister> _x, std::unique_ptr<TyRegister> _y);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyAddSelectZero> add_select_zero;
};
struct ConsAddSelectZero2 : public TyInfrule{
public : 
  ConsAddSelectZero2(std::unique_ptr<TyAddSelectZero2> _add_select_zero2);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyRegister> _z, std::unique_ptr<TyRegister> _x, std::unique_ptr<TyRegister> _y);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyAddSelectZero2> add_select_zero2;
};
struct ConsAddDistSub : public TyInfrule{
public : 
  ConsAddDistSub(std::unique_ptr<TyAddDistSub> _add_dist_sub);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyRegister> _z, std::unique_ptr<TyRegister> _minusx, std::unique_ptr<TyRegister> _minusy, std::unique_ptr<TyRegister> _w);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyAddDistSub> add_dist_sub;
};
struct ConsMulAddDistributive : public TyInfrule{
public : 
  ConsMulAddDistributive(std::unique_ptr<TyMulAddDistributive> _mul_add_distributive);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyRegister> _z, std::unique_ptr<TyRegister> _x, std::unique_ptr<TyRegister> _y, std::unique_ptr<TyRegister> _w);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyMulAddDistributive> mul_add_distributive;
};
struct ConsSubMone : public TyInfrule{
public : 
  ConsSubMone(std::unique_ptr<TySubMone> _sub_mone);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TySubMone> sub_mone;
};
struct ConsSubAdd : public TyInfrule{
public : 
  ConsSubAdd(std::unique_ptr<TySubAdd> _sub_add);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyRegister> _z, std::unique_ptr<TyValue> _my, std::unique_ptr<TyRegister> _x, std::unique_ptr<TyValue> _y, std::unique_ptr<TySize> _sz);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TySubAdd> sub_add;
};
struct ConsSubConstNot : public TyInfrule{
public : 
  ConsSubConstNot(std::unique_ptr<TySubConstNot> _sub_const_not);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyRegister> _y, std::unique_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TySubConstNot> sub_const_not;
};
struct ConsSubRemove : public TyInfrule{
public : 
  ConsSubRemove(std::unique_ptr<TySubRemove> _sub_remove);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyRegister> _z, std::unique_ptr<TyRegister> _y, std::unique_ptr<TyValue> _a, std::unique_ptr<TyValue> _b, std::unique_ptr<TySize> _sz);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TySubRemove> sub_remove;
};
struct ConsSubRemove2 : public TyInfrule{
public : 
  ConsSubRemove2(std::unique_ptr<TySubRemove2> _sub_remove2);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyRegister> _y, std::unique_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TySubRemove2> sub_remove2;
};
struct ConsSubOnebit : public TyInfrule{
public : 
  ConsSubOnebit(std::unique_ptr<TySubOnebit> _sub_onebit);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TySubOnebit> sub_onebit;
};
struct ConsSubConstAdd : public TyInfrule{
public : 
  ConsSubConstAdd(std::unique_ptr<TySubConstAdd> _sub_const_add);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyRegister> _y, std::unique_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TySubConstAdd> sub_const_add;
};
struct ConsSubSdiv : public TyInfrule{
public : 
  ConsSubSdiv(std::unique_ptr<TySubSdiv> _sub_sdiv);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyRegister> _y, std::unique_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TySubSdiv> sub_sdiv;
};
struct ConsSubShl : public TyInfrule{
public : 
  ConsSubShl(std::unique_ptr<TySubShl> _sub_shl);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyRegister> _x, std::unique_ptr<TyRegister> _y, std::unique_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TySubShl> sub_shl;
};
struct ConsMulBool : public TyInfrule{
public : 
  ConsMulBool(std::unique_ptr<TyMulBool> _mul_bool);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyRegister> _z, std::unique_ptr<TyRegister> _x, std::unique_ptr<TyRegister> _y);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyMulBool> mul_bool;
};
struct ConsMulMone : public TyInfrule{
public : 
  ConsMulMone(std::unique_ptr<TyMulMone> _mul_mone);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyMulMone> mul_mone;
};
struct ConsMulNeg : public TyInfrule{
public : 
  ConsMulNeg(std::unique_ptr<TyMulNeg> _mul_neg);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyRegister> _z, std::unique_ptr<TyValue> _mx, std::unique_ptr<TyValue> _my, std::unique_ptr<TyValue> _x, std::unique_ptr<TyValue> _y, std::unique_ptr<TySize> _sz);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyMulNeg> mul_neg;
};
struct ConsMulCommutative : public TyInfrule{
public : 
  ConsMulCommutative(std::unique_ptr<TyMulCommutative> _mul_commutative);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyMulCommutative> mul_commutative;
};
struct ConsMulShl : public TyInfrule{
public : 
  ConsMulShl(std::unique_ptr<TyMulShl> _mul_shl);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyRegister> _z, std::unique_ptr<TyRegister> _y);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyMulShl> mul_shl;
};
struct ConsNoaliasGlobalAlloca : public TyInfrule{
public : 
  ConsNoaliasGlobalAlloca(std::unique_ptr<TyNoaliasGlobalAlloca> _noalias_global_alloca);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyRegister> _x, std::unique_ptr<TyRegister> _y);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyNoaliasGlobalAlloca> noalias_global_alloca;
};
struct ConsDivMone : public TyInfrule{
public : 
  ConsDivMone(std::unique_ptr<TyDivMone> _div_mone);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyDivMone> div_mone;
};
struct ConsRemNeg : public TyInfrule{
public : 
  ConsRemNeg(std::unique_ptr<TyRemNeg> _rem_neg);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyRegister> _z, std::unique_ptr<TyRegister> _my);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRemNeg> rem_neg;
};
struct ConsDivSubSrem : public TyInfrule{
public : 
  ConsDivSubSrem(std::unique_ptr<TyDivSubSrem> _div_sub_srem);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyRegister> _z, std::unique_ptr<TyRegister> _b, std::unique_ptr<TyRegister> _a);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyDivSubSrem> div_sub_srem;
};
struct ConsDivSubUrem : public TyInfrule{
public : 
  ConsDivSubUrem(std::unique_ptr<TyDivSubUrem> _div_sub_urem);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyRegister> _z, std::unique_ptr<TyRegister> _b, std::unique_ptr<TyRegister> _a);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyDivSubUrem> div_sub_urem;
};
struct ConsAndDeMorgan : public TyInfrule{
public : 
  ConsAndDeMorgan(std::unique_ptr<TyAndDeMorgan> _and_de_morgan);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyRegister> _z, std::unique_ptr<TyRegister> _x, std::unique_ptr<TyRegister> _y, std::unique_ptr<TyRegister> _z2);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyAndDeMorgan> and_de_morgan;
};
struct ConsNegVal : public TyInfrule{
public : 
  ConsNegVal(std::unique_ptr<TyNegVal> _neg_val);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyConstInt> _c1, std::unique_ptr<TyConstInt> _c2, std::unique_ptr<TySize> _sz);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyNegVal> neg_val;
};
struct ConsTransitivity : public TyInfrule{
public : 
  ConsTransitivity(std::unique_ptr<TyTransitivity> _transitivity);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyExpr> _e1, std::unique_ptr<TyExpr> _e2, std::unique_ptr<TyExpr> _e3);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyTransitivity> transitivity;
};
struct ConsTransitivityPointerLhs : public TyInfrule{
public : 
  ConsTransitivityPointerLhs(std::unique_ptr<TyTransitivityPointerLhs> _transitivity_pointer_lhs);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyValue> _p, std::unique_ptr<TyValue> _q, std::unique_ptr<TyValue> _v, std::unique_ptr<TyExpr> _loadq);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyTransitivityPointerLhs> transitivity_pointer_lhs;
};
struct ConsTransitivityPointerRhs : public TyInfrule{
public : 
  ConsTransitivityPointerRhs(std::unique_ptr<TyTransitivityPointerRhs> _transitivity_pointer_rhs);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyValue> _p, std::unique_ptr<TyValue> _q, std::unique_ptr<TyValue> _v, std::unique_ptr<TyExpr> _loadp);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyTransitivityPointerRhs> transitivity_pointer_rhs;
};
struct ConsReplaceRhs : public TyInfrule{
public : 
  ConsReplaceRhs(std::unique_ptr<TyReplaceRhs> _replace_rhs);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyRegister> _x, std::unique_ptr<TyValue> _y, std::unique_ptr<TyExpr> _e1, std::unique_ptr<TyExpr> _e2, std::unique_ptr<TyExpr> _e2prime);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyReplaceRhs> replace_rhs;
};
struct ConsSimplifyAndSame : public TyInfrule{
public : 
  ConsSimplifyAndSame(std::unique_ptr<TySimplifyAndSame> _simplify_and_same);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyRegister> _x, std::unique_ptr<TyValue> _a, std::unique_ptr<TySize> _s);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TySimplifyAndSame> simplify_and_same;
};
struct ConsInfrule : public TyCommand{
public : 
  ConsInfrule(std::unique_ptr<TyPosition> _position, std::unique_ptr<TyInfrule> _infrule);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyPosition> position;
  std::unique_ptr<TyInfrule> infrule;
};
struct ConsPhinodeCurrentBlockName : public TyNopPosition{
public : 
  ConsPhinodeCurrentBlockName(std::string _s);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::string s;
};
struct ConsCommandRegisterName : public TyNopPosition{
public : 
  ConsCommandRegisterName(std::string _s);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::string s;
};
