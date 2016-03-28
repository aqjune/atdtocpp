class TyAddAssociative{
public : 
  TyAddAssociative(std::unique_ptr<Register> _x, std::unique_ptr<Register> _y, std::unique_ptr<Register> _z, std::unique_ptr<ConstInt> _c1, std::unique_ptr<ConstInt> _c2, std::unique_ptr<ConstInt> _c3, std::unique_ptr<Size> _sz);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Register> x;
  std::unique_ptr<Register> y;
  std::unique_ptr<Register> z;
  std::unique_ptr<ConstInt> c1;
  std::unique_ptr<ConstInt> c2;
  std::unique_ptr<ConstInt> c3;
  std::unique_ptr<Size> sz;

};
class TyAddCommutative{
public : 
  TyAddCommutative(std::unique_ptr<Register> _z, std::unique_ptr<Value> _x, std::unique_ptr<Value> _y, std::unique_ptr<Size> _sz);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Register> z;
  std::unique_ptr<Value> x;
  std::unique_ptr<Value> y;
  std::unique_ptr<Size> sz;

};
class TyAddConstNot{
public : 
  TyAddConstNot(std::unique_ptr<Register> _z, std::unique_ptr<Register> _y);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Register> z;
  std::unique_ptr<Register> y;

};
class TyAddDistSub{
public : 
  TyAddDistSub(std::unique_ptr<Register> _z, std::unique_ptr<Register> _minusx, std::unique_ptr<Register> _minusy, std::unique_ptr<Register> _w);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Register> z;
  std::unique_ptr<Register> minusx;
  std::unique_ptr<Register> minusy;
  std::unique_ptr<Register> w;

};
class TyAddMask{
public : 
  TyAddMask(std::unique_ptr<Register> _z, std::unique_ptr<Register> _y, std::unique_ptr<Register> _yp);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Register> z;
  std::unique_ptr<Register> y;
  std::unique_ptr<Register> yp;

};
class TyAddOnebit{
public : 
  TyAddOnebit(std::unique_ptr<Register> _z, std::unique_ptr<Value> _x, std::unique_ptr<Value> _y);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Register> z;
  std::unique_ptr<Value> x;
  std::unique_ptr<Value> y;

};
class TyAddSelectZero{
public : 
  TyAddSelectZero(std::unique_ptr<Register> _z, std::unique_ptr<Register> _x, std::unique_ptr<Register> _y);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Register> z;
  std::unique_ptr<Register> x;
  std::unique_ptr<Register> y;

};
class TyAddSelectZero2{
public : 
  TyAddSelectZero2(std::unique_ptr<Register> _z, std::unique_ptr<Register> _x, std::unique_ptr<Register> _y);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Register> z;
  std::unique_ptr<Register> x;
  std::unique_ptr<Register> y;

};
class TyAddShift{
public : 
  TyAddShift(std::unique_ptr<Register> _y, std::unique_ptr<Value> _v, std::unique_ptr<Size> _sz);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Register> y;
  std::unique_ptr<Value> v;
  std::unique_ptr<Size> sz;

};
class TyAddSignbit{
public : 
  TyAddSignbit(std::unique_ptr<Register> _x, std::unique_ptr<Value> _e1, std::unique_ptr<Value> _e2, std::unique_ptr<Size> _sz);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Register> x;
  std::unique_ptr<Value> e1;
  std::unique_ptr<Value> e2;
  std::unique_ptr<Size> sz;

};
class TyAddSub{
public : 
  TyAddSub(std::unique_ptr<Register> _minusy, std::unique_ptr<Register> _z, std::unique_ptr<Value> _x, std::unique_ptr<Value> _y, std::unique_ptr<Size> _sz);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Register> minusy;
  std::unique_ptr<Register> z;
  std::unique_ptr<Value> x;
  std::unique_ptr<Value> y;
  std::unique_ptr<Size> sz;

};
class TyAddZextBool{
public : 
  TyAddZextBool(std::unique_ptr<Register> _x, std::unique_ptr<Register> _y, std::unique_ptr<Value> _b, std::unique_ptr<ConstInt> _c, std::unique_ptr<ConstInt> _c', std::unique_ptr<Size> _sz);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Register> x;
  std::unique_ptr<Register> y;
  std::unique_ptr<Value> b;
  std::unique_ptr<ConstInt> c;
  std::unique_ptr<ConstInt> c';
  std::unique_ptr<Size> sz;

};
class TyAndDeMorgan{
public : 
  TyAndDeMorgan(std::unique_ptr<Register> _z, std::unique_ptr<Register> _x, std::unique_ptr<Register> _y, std::unique_ptr<Register> _z2);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Register> z;
  std::unique_ptr<Register> x;
  std::unique_ptr<Register> y;
  std::unique_ptr<Register> z2;

};
class TyCommand{
public : 
  virtual void serialize(JSONOutputArchive& archive) const = 0;

};
class TyConstFloat{
public : 
  TyConstFloat(double _float_value, std::unique_ptr<FloatType> _float_type);
  void serialize(JSONOutputArchive& archive) const;

private : 
  double float_value;
  std::unique_ptr<FloatType> float_type;

};
class TyConstInt{
public : 
  TyConstInt(int _int_value, std::unique_ptr<IntType> _int_type);
  void serialize(JSONOutputArchive& archive) const;

private : 
  int int_value;
  std::unique_ptr<IntType> int_type;

};
class TyConstant{
public : 
  virtual void serialize(JSONOutputArchive& archive) const = 0;

};
class TyDivMone{
public : 
  TyDivMone(std::unique_ptr<Register> _z);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Register> z;

};
class TyDivSubSrem{
public : 
  TyDivSubSrem(std::unique_ptr<Register> _z, std::unique_ptr<Register> _b, std::unique_ptr<Register> _a);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Register> z;
  std::unique_ptr<Register> b;
  std::unique_ptr<Register> a;

};
class TyDivSubUrem{
public : 
  TyDivSubUrem(std::unique_ptr<Register> _z, std::unique_ptr<Register> _b, std::unique_ptr<Register> _a);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Register> z;
  std::unique_ptr<Register> b;
  std::unique_ptr<Register> a;

};
class TyExpr{
public : 
  virtual void serialize(JSONOutputArchive& archive) const = 0;

};
class TyFloatType{
public : 
  virtual void serialize(JSONOutputArchive& archive) const = 0;

};
class TyHints{
public : 
  TyHints(std::string _module_id, std::string _function_id, std::string _opt_name, std::vector<std::unique_ptr<NopPosition>> _src_nop_positions, std::vector<std::unique_ptr<NopPosition>> _tgt_nop_positions, std::vector<std::unique_ptr<Command>> _commands);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::string module_id;
  std::string function_id;
  std::string opt_name;
  std::vector<std::unique_ptr<NopPosition>> src_nop_positions;
  std::vector<std::unique_ptr<NopPosition>> tgt_nop_positions;
  std::vector<std::unique_ptr<Command>> commands;

};
class TyInfrule{
public : 
  virtual void serialize(JSONOutputArchive& archive) const = 0;

};
class TyIntType{
public : 
  virtual void serialize(JSONOutputArchive& archive) const = 0;

};
class TyMulAddDistributive{
public : 
  TyMulAddDistributive(std::unique_ptr<Register> _z, std::unique_ptr<Register> _x, std::unique_ptr<Register> _y, std::unique_ptr<Register> _w);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Register> z;
  std::unique_ptr<Register> x;
  std::unique_ptr<Register> y;
  std::unique_ptr<Register> w;

};
class TyMulBool{
public : 
  TyMulBool(std::unique_ptr<Register> _z, std::unique_ptr<Register> _x, std::unique_ptr<Register> _y);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Register> z;
  std::unique_ptr<Register> x;
  std::unique_ptr<Register> y;

};
class TyMulCommutative{
public : 
  TyMulCommutative(std::unique_ptr<Register> _z);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Register> z;

};
class TyMulMone{
public : 
  TyMulMone(std::unique_ptr<Register> _z);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Register> z;

};
class TyMulNeg{
public : 
  TyMulNeg(std::unique_ptr<Register> _z, std::unique_ptr<Register> _mx, std::unique_ptr<Register> _my);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Register> z;
  std::unique_ptr<Register> mx;
  std::unique_ptr<Register> my;

};
class TyMulShl{
public : 
  TyMulShl(std::unique_ptr<Register> _z, std::unique_ptr<Register> _y);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Register> z;
  std::unique_ptr<Register> y;

};
class TyNegVal{
public : 
  TyNegVal(std::unique_ptr<ConstInt> _c1, std::unique_ptr<ConstInt> _c2, std::unique_ptr<Size> _sz);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<ConstInt> c1;
  std::unique_ptr<ConstInt> c2;
  std::unique_ptr<Size> sz;

};
class TyNopPosition{
public : 
  virtual void serialize(JSONOutputArchive& archive) const = 0;

};
class TyPosition{
public : 
  virtual void serialize(JSONOutputArchive& archive) const = 0;

};
class TyPositionCommand{
public : 
  TyPositionCommand(std::unique_ptr<Scope> _scope, std::string _register_name);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Scope> scope;
  std::string register_name;

};
class TyPositionPhinode{
public : 
  TyPositionPhinode(std::string _block_name, std::string _prev_block_name);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::string block_name;
  std::string prev_block_name;

};
class TyPropagate{
public : 
  TyPropagate(std::unique_ptr<PropagateObject> _propagate, std::unique_ptr<PropagateRange> _propagate_range);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<PropagateObject> propagate;
  std::unique_ptr<PropagateRange> propagate_range;

};
class TyPropagateLessdef{
public : 
  TyPropagateLessdef(std::unique_ptr<Expr> _lhs, std::unique_ptr<Expr> _rhs, std::unique_ptr<Scope> _scope);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Expr> lhs;
  std::unique_ptr<Expr> rhs;
  std::unique_ptr<Scope> scope;

};
class TyPropagateNoalias{
public : 
  TyPropagateNoalias(std::unique_ptr<Register> _lhs, std::unique_ptr<Register> _rhs, std::unique_ptr<Scope> _scope);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Register> lhs;
  std::unique_ptr<Register> rhs;
  std::unique_ptr<Scope> scope;

};
class TyPropagateObject{
public : 
  virtual void serialize(JSONOutputArchive& archive) const = 0;

};
class TyPropagateRange{
public : 
  virtual void serialize(JSONOutputArchive& archive) const = 0;

};
class TyRegister{
public : 
  TyRegister(std::string _name, std::unique_ptr<Tag> _tag);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::string name;
  std::unique_ptr<Tag> tag;

};
class TyRemNeg{
public : 
  TyRemNeg(std::unique_ptr<Register> _z, std::unique_ptr<Register> _my);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Register> z;
  std::unique_ptr<Register> my;

};
class TyScope{
public : 
  virtual void serialize(JSONOutputArchive& archive) const = 0;

};
class TySize{
public : 
  virtual void serialize(JSONOutputArchive& archive) const = 0;

};
class TySubAdd{
public : 
  TySubAdd(std::unique_ptr<Register> _z, std::unique_ptr<Value> _my, std::unique_ptr<Register> _x, std::unique_ptr<Value> _y, std::unique_ptr<Size> _sz);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Register> z;
  std::unique_ptr<Value> my;
  std::unique_ptr<Register> x;
  std::unique_ptr<Value> y;
  std::unique_ptr<Size> sz;

};
class TySubConstAdd{
public : 
  TySubConstAdd(std::unique_ptr<Register> _y, std::unique_ptr<Register> _z);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Register> y;
  std::unique_ptr<Register> z;

};
class TySubConstNot{
public : 
  TySubConstNot(std::unique_ptr<Register> _y, std::unique_ptr<Register> _z);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Register> y;
  std::unique_ptr<Register> z;

};
class TySubMone{
public : 
  TySubMone(std::unique_ptr<Register> _z);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Register> z;

};
class TySubOnebit{
public : 
  TySubOnebit(std::unique_ptr<Register> _z);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Register> z;

};
class TySubRemove{
public : 
  TySubRemove(std::unique_ptr<Register> _z, std::unique_ptr<Register> _y, std::unique_ptr<Value> _a, std::unique_ptr<Value> _b, std::unique_ptr<Size> _sz);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Register> z;
  std::unique_ptr<Register> y;
  std::unique_ptr<Value> a;
  std::unique_ptr<Value> b;
  std::unique_ptr<Size> sz;

};
class TySubRemove2{
public : 
  TySubRemove2(std::unique_ptr<Register> _y, std::unique_ptr<Register> _z);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Register> y;
  std::unique_ptr<Register> z;

};
class TySubSdiv{
public : 
  TySubSdiv(std::unique_ptr<Register> _y, std::unique_ptr<Register> _z);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Register> y;
  std::unique_ptr<Register> z;

};
class TySubShl{
public : 
  TySubShl(std::unique_ptr<Register> _x, std::unique_ptr<Register> _y, std::unique_ptr<Register> _z);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Register> x;
  std::unique_ptr<Register> y;
  std::unique_ptr<Register> z;

};
class TyTag{
public : 
  virtual void serialize(JSONOutputArchive& archive) const = 0;

};
class TyValue{
public : 
  virtual void serialize(JSONOutputArchive& archive) const = 0;

};
class ConsPropagate : public TyCommand{
public : 
  ConsPropagate(std::unique_ptr<Propagate> _propagate);
  static std::unique_ptr<TyCommand> make(std::unique_ptr<PropagateObject> _propagate, std::unique_ptr<PropagateRange> _propagate_range) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Propagate> propagate;

};
class ConsInfrule : public TyCommand{
public : 
  ConsInfrule(std::unique_ptr<Position> _position, std::unique_ptr<Infrule> _infrule);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Position> position;
  std::unique_ptr<Infrule> infrule;

};
class ConsConstInt : public TyConstant{
public : 
  ConsConstInt(std::unique_ptr<ConstInt> _const_int);
  static std::unique_ptr<TyConstant> make(int _int_value, std::unique_ptr<IntType> _int_type) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<ConstInt> const_int;

};
class ConsConstFloat : public TyConstant{
public : 
  ConsConstFloat(std::unique_ptr<ConstFloat> _const_float);
  static std::unique_ptr<TyConstant> make(double _float_value, std::unique_ptr<FloatType> _float_type) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<ConstFloat> const_float;

};
class ConsVar : public TyExpr{
public : 
  ConsVar(std::unique_ptr<Register> _register);
  static std::unique_ptr<TyExpr> make(std::string _name, std::unique_ptr<Tag> _tag) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Register> register;

};
class ConsRhs : public TyExpr{
public : 
  ConsRhs(std::unique_ptr<Register> _register, std::unique_ptr<Scope> _scope);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Register> register;
  std::unique_ptr<Scope> scope;

};
class ConsConst : public TyExpr{
public : 
  ConsConst(std::unique_ptr<Constant> _constant);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Constant> constant;

};
class ConsHalfType : public TyFloatType{
public : 
  ConsHalfType();
  void serialize(JSONOutputArchive& archive) const;

};
class ConsFloatType : public TyFloatType{
public : 
  ConsFloatType();
  void serialize(JSONOutputArchive& archive) const;

};
class ConsDoubleType : public TyFloatType{
public : 
  ConsDoubleType();
  void serialize(JSONOutputArchive& archive) const;

};
class ConsFP128Type : public TyFloatType{
public : 
  ConsFP128Type();
  void serialize(JSONOutputArchive& archive) const;

};
class ConsPPCFP128Type : public TyFloatType{
public : 
  ConsPPCFP128Type();
  void serialize(JSONOutputArchive& archive) const;

};
class ConsX86FP80Type : public TyFloatType{
public : 
  ConsX86FP80Type();
  void serialize(JSONOutputArchive& archive) const;

};
class ConsAddAssociative : public TyInfrule{
public : 
  ConsAddAssociative(std::unique_ptr<AddAssociative> _add_associative);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<Register> _x, std::unique_ptr<Register> _y, std::unique_ptr<Register> _z, std::unique_ptr<ConstInt> _c1, std::unique_ptr<ConstInt> _c2, std::unique_ptr<ConstInt> _c3, std::unique_ptr<Size> _sz) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<AddAssociative> add_associative;

};
class ConsAddSub : public TyInfrule{
public : 
  ConsAddSub(std::unique_ptr<AddSub> _add_sub);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<Register> _minusy, std::unique_ptr<Register> _z, std::unique_ptr<Value> _x, std::unique_ptr<Value> _y, std::unique_ptr<Size> _sz) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<AddSub> add_sub;

};
class ConsAddCommutative : public TyInfrule{
public : 
  ConsAddCommutative(std::unique_ptr<AddCommutative> _add_commutative);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<Register> _z, std::unique_ptr<Value> _x, std::unique_ptr<Value> _y, std::unique_ptr<Size> _sz) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<AddCommutative> add_commutative;

};
class ConsAddShift : public TyInfrule{
public : 
  ConsAddShift(std::unique_ptr<AddShift> _add_shift);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<Register> _y, std::unique_ptr<Value> _v, std::unique_ptr<Size> _sz) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<AddShift> add_shift;

};
class ConsAddSignbit : public TyInfrule{
public : 
  ConsAddSignbit(std::unique_ptr<AddSignbit> _add_signbit);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<Register> _x, std::unique_ptr<Value> _e1, std::unique_ptr<Value> _e2, std::unique_ptr<Size> _sz) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<AddSignbit> add_signbit;

};
class ConsAddOnebit : public TyInfrule{
public : 
  ConsAddOnebit(std::unique_ptr<AddOnebit> _add_onebit);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<Register> _z, std::unique_ptr<Value> _x, std::unique_ptr<Value> _y) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<AddOnebit> add_onebit;

};
class ConsAddZextBool : public TyInfrule{
public : 
  ConsAddZextBool(std::unique_ptr<AddZextBool> _add_zext_bool);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<Register> _x, std::unique_ptr<Register> _y, std::unique_ptr<Value> _b, std::unique_ptr<ConstInt> _c, std::unique_ptr<ConstInt> _c', std::unique_ptr<Size> _sz) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<AddZextBool> add_zext_bool;

};
class ConsAddConstNot : public TyInfrule{
public : 
  ConsAddConstNot(std::unique_ptr<AddConstNot> _add_const_not);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<Register> _z, std::unique_ptr<Register> _y) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<AddConstNot> add_const_not;

};
class ConsAddMask : public TyInfrule{
public : 
  ConsAddMask(std::unique_ptr<AddMask> _add_mask);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<Register> _z, std::unique_ptr<Register> _y, std::unique_ptr<Register> _yp) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<AddMask> add_mask;

};
class ConsAddSelectZero : public TyInfrule{
public : 
  ConsAddSelectZero(std::unique_ptr<AddSelectZero> _add_select_zero);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<Register> _z, std::unique_ptr<Register> _x, std::unique_ptr<Register> _y) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<AddSelectZero> add_select_zero;

};
class ConsAddSelectZero2 : public TyInfrule{
public : 
  ConsAddSelectZero2(std::unique_ptr<AddSelectZero2> _add_select_zero2);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<Register> _z, std::unique_ptr<Register> _x, std::unique_ptr<Register> _y) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<AddSelectZero2> add_select_zero2;

};
class ConsAddDistSub : public TyInfrule{
public : 
  ConsAddDistSub(std::unique_ptr<AddDistSub> _add_dist_sub);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<Register> _z, std::unique_ptr<Register> _minusx, std::unique_ptr<Register> _minusy, std::unique_ptr<Register> _w) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<AddDistSub> add_dist_sub;

};
class ConsMulAddDistributive : public TyInfrule{
public : 
  ConsMulAddDistributive(std::unique_ptr<MulAddDistributive> _mul_add_distributive);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<Register> _z, std::unique_ptr<Register> _x, std::unique_ptr<Register> _y, std::unique_ptr<Register> _w) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<MulAddDistributive> mul_add_distributive;

};
class ConsSubMone : public TyInfrule{
public : 
  ConsSubMone(std::unique_ptr<SubMone> _sub_mone);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<Register> _z) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<SubMone> sub_mone;

};
class ConsSubAdd : public TyInfrule{
public : 
  ConsSubAdd(std::unique_ptr<SubAdd> _sub_add);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<Register> _z, std::unique_ptr<Value> _my, std::unique_ptr<Register> _x, std::unique_ptr<Value> _y, std::unique_ptr<Size> _sz) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<SubAdd> sub_add;

};
class ConsSubConstNot : public TyInfrule{
public : 
  ConsSubConstNot(std::unique_ptr<SubConstNot> _sub_const_not);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<Register> _y, std::unique_ptr<Register> _z) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<SubConstNot> sub_const_not;

};
class ConsSubRemove : public TyInfrule{
public : 
  ConsSubRemove(std::unique_ptr<SubRemove> _sub_remove);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<Register> _z, std::unique_ptr<Register> _y, std::unique_ptr<Value> _a, std::unique_ptr<Value> _b, std::unique_ptr<Size> _sz) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<SubRemove> sub_remove;

};
class ConsSubRemove2 : public TyInfrule{
public : 
  ConsSubRemove2(std::unique_ptr<SubRemove2> _sub_remove2);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<Register> _y, std::unique_ptr<Register> _z) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<SubRemove2> sub_remove2;

};
class ConsSubOnebit : public TyInfrule{
public : 
  ConsSubOnebit(std::unique_ptr<SubOnebit> _sub_onebit);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<Register> _z) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<SubOnebit> sub_onebit;

};
class ConsSubConstAdd : public TyInfrule{
public : 
  ConsSubConstAdd(std::unique_ptr<SubConstAdd> _sub_const_add);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<Register> _y, std::unique_ptr<Register> _z) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<SubConstAdd> sub_const_add;

};
class ConsSubSdiv : public TyInfrule{
public : 
  ConsSubSdiv(std::unique_ptr<SubSdiv> _sub_sdiv);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<Register> _y, std::unique_ptr<Register> _z) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<SubSdiv> sub_sdiv;

};
class ConsSubShl : public TyInfrule{
public : 
  ConsSubShl(std::unique_ptr<SubShl> _sub_shl);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<Register> _x, std::unique_ptr<Register> _y, std::unique_ptr<Register> _z) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<SubShl> sub_shl;

};
class ConsMulBool : public TyInfrule{
public : 
  ConsMulBool(std::unique_ptr<MulBool> _mul_bool);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<Register> _z, std::unique_ptr<Register> _x, std::unique_ptr<Register> _y) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<MulBool> mul_bool;

};
class ConsMulMone : public TyInfrule{
public : 
  ConsMulMone(std::unique_ptr<MulMone> _mul_mone);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<Register> _z) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<MulMone> mul_mone;

};
class ConsMulNeg : public TyInfrule{
public : 
  ConsMulNeg(std::unique_ptr<MulNeg> _mul_neg);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<Register> _z, std::unique_ptr<Register> _mx, std::unique_ptr<Register> _my) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<MulNeg> mul_neg;

};
class ConsMulCommutative : public TyInfrule{
public : 
  ConsMulCommutative(std::unique_ptr<MulCommutative> _mul_commutative);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<Register> _z) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<MulCommutative> mul_commutative;

};
class ConsMulShl : public TyInfrule{
public : 
  ConsMulShl(std::unique_ptr<MulShl> _mul_shl);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<Register> _z, std::unique_ptr<Register> _y) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<MulShl> mul_shl;

};
class ConsDivMone : public TyInfrule{
public : 
  ConsDivMone(std::unique_ptr<DivMone> _div_mone);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<Register> _z) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<DivMone> div_mone;

};
class ConsRemNeg : public TyInfrule{
public : 
  ConsRemNeg(std::unique_ptr<RemNeg> _rem_neg);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<Register> _z, std::unique_ptr<Register> _my) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<RemNeg> rem_neg;

};
class ConsDivSubSrem : public TyInfrule{
public : 
  ConsDivSubSrem(std::unique_ptr<DivSubSrem> _div_sub_srem);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<Register> _z, std::unique_ptr<Register> _b, std::unique_ptr<Register> _a) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<DivSubSrem> div_sub_srem;

};
class ConsDivSubUrem : public TyInfrule{
public : 
  ConsDivSubUrem(std::unique_ptr<DivSubUrem> _div_sub_urem);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<Register> _z, std::unique_ptr<Register> _b, std::unique_ptr<Register> _a) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<DivSubUrem> div_sub_urem;

};
class ConsAndDeMorgan : public TyInfrule{
public : 
  ConsAndDeMorgan(std::unique_ptr<AndDeMorgan> _and_de_morgan);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<Register> _z, std::unique_ptr<Register> _x, std::unique_ptr<Register> _y, std::unique_ptr<Register> _z2) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<AndDeMorgan> and_de_morgan;

};
class ConsNegVal : public TyInfrule{
public : 
  ConsNegVal(std::unique_ptr<NegVal> _neg_val);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<ConstInt> _c1, std::unique_ptr<ConstInt> _c2, std::unique_ptr<Size> _sz) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<NegVal> neg_val;

};
class ConsIntType : public TyIntType{
public : 
  ConsIntType(int _i);
  void serialize(JSONOutputArchive& archive) const;

private : 
  int i;

};
class ConsPhinodeCurrentBlockName : public TyNopPosition{
public : 
  ConsPhinodeCurrentBlockName(std::string _s);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::string s;

};
class ConsCommandRegisterName : public TyNopPosition{
public : 
  ConsCommandRegisterName(std::string _s);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::string s;

};
class ConsPhinode : public TyPosition{
public : 
  ConsPhinode(std::unique_ptr<PositionPhinode> _position_phinode);
  static std::unique_ptr<TyPosition> make(std::string _block_name, std::string _prev_block_name) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<PositionPhinode> position_phinode;

};
class ConsCommand : public TyPosition{
public : 
  ConsCommand(std::unique_ptr<PositionCommand> _position_command);
  static std::unique_ptr<TyPosition> make(std::unique_ptr<Scope> _scope, std::string _register_name) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<PositionCommand> position_command;

};
class ConsLessdef : public TyPropagateObject{
public : 
  ConsLessdef(std::unique_ptr<PropagateLessdef> _propagate_lessdef);
  static std::unique_ptr<TyPropagateObject> make(std::unique_ptr<Expr> _lhs, std::unique_ptr<Expr> _rhs, std::unique_ptr<Scope> _scope) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<PropagateLessdef> propagate_lessdef;

};
class ConsNoalias : public TyPropagateObject{
public : 
  ConsNoalias(std::unique_ptr<PropagateNoalias> _propagate_noalias);
  static std::unique_ptr<TyPropagateObject> make(std::unique_ptr<Register> _lhs, std::unique_ptr<Register> _rhs, std::unique_ptr<Scope> _scope) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<PropagateNoalias> propagate_noalias;

};
class ConsMaydiff : public TyPropagateObject{
public : 
  ConsMaydiff(std::unique_ptr<Register> _register);
  static std::unique_ptr<TyPropagateObject> make(std::string _name, std::unique_ptr<Tag> _tag) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Register> register;

};
class ConsBounds : public TyPropagateRange{
public : 
  ConsBounds(std::unique_ptr<Position> _position, std::unique_ptr<Position> _position);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Position> position;
  std::unique_ptr<Position> position;

};
class ConsGlobal : public TyPropagateRange{
public : 
  ConsGlobal();
  void serialize(JSONOutputArchive& archive) const;

};
class ConsSource : public TyScope{
public : 
  ConsSource();
  void serialize(JSONOutputArchive& archive) const;

};
class ConsTarget : public TyScope{
public : 
  ConsTarget();
  void serialize(JSONOutputArchive& archive) const;

};
class ConsSize : public TySize{
public : 
  ConsSize(int _i);
  void serialize(JSONOutputArchive& archive) const;

private : 
  int i;

};
class ConsPhysical : public TyTag{
public : 
  ConsPhysical();
  void serialize(JSONOutputArchive& archive) const;

};
class ConsPrevious : public TyTag{
public : 
  ConsPrevious();
  void serialize(JSONOutputArchive& archive) const;

};
class ConsGhost : public TyTag{
public : 
  ConsGhost();
  void serialize(JSONOutputArchive& archive) const;

};
class ConsId : public TyValue{
public : 
  ConsId(std::unique_ptr<Register> _register);
  static std::unique_ptr<TyValue> make(std::string _name, std::unique_ptr<Tag> _tag) const;
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Register> register;

};
class ConsConstVal : public TyValue{
public : 
  ConsConstVal(std::unique_ptr<Constant> _constant);
  void serialize(JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<Constant> constant;

};
