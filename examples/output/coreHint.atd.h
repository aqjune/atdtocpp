struct TyAddAssociative{
public : 
  TyAddAssociative(std::shared_ptr<TyRegister> _x, std::shared_ptr<TyRegister> _y, std::shared_ptr<TyRegister> _z, std::shared_ptr<TyConstInt> _c1, std::shared_ptr<TyConstInt> _c2, std::shared_ptr<TyConstInt> _c3, std::shared_ptr<TySize> _sz);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRegister> x;
  std::shared_ptr<TyRegister> y;
  std::shared_ptr<TyRegister> z;
  std::shared_ptr<TyConstInt> c1;
  std::shared_ptr<TyConstInt> c2;
  std::shared_ptr<TyConstInt> c3;
  std::shared_ptr<TySize> sz;
};

struct TyAddCommutative{
public : 
  TyAddCommutative(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyValue> _x, std::shared_ptr<TyValue> _y, std::shared_ptr<TySize> _sz);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRegister> z;
  std::shared_ptr<TyValue> x;
  std::shared_ptr<TyValue> y;
  std::shared_ptr<TySize> sz;
};

struct TyAddConstNot{
public : 
  TyAddConstNot(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _y);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRegister> z;
  std::shared_ptr<TyRegister> y;
};

struct TyAddDistSub{
public : 
  TyAddDistSub(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _minusx, std::shared_ptr<TyRegister> _minusy, std::shared_ptr<TyRegister> _w);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRegister> z;
  std::shared_ptr<TyRegister> minusx;
  std::shared_ptr<TyRegister> minusy;
  std::shared_ptr<TyRegister> w;
};

struct TyAddMask{
public : 
  TyAddMask(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _y, std::shared_ptr<TyRegister> _yp);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRegister> z;
  std::shared_ptr<TyRegister> y;
  std::shared_ptr<TyRegister> yp;
};

struct TyAddOnebit{
public : 
  TyAddOnebit(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyValue> _x, std::shared_ptr<TyValue> _y);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRegister> z;
  std::shared_ptr<TyValue> x;
  std::shared_ptr<TyValue> y;
};

struct TyAddSelectZero{
public : 
  TyAddSelectZero(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _x, std::shared_ptr<TyRegister> _y);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRegister> z;
  std::shared_ptr<TyRegister> x;
  std::shared_ptr<TyRegister> y;
};

struct TyAddSelectZero2{
public : 
  TyAddSelectZero2(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _x, std::shared_ptr<TyRegister> _y);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRegister> z;
  std::shared_ptr<TyRegister> x;
  std::shared_ptr<TyRegister> y;
};

struct TyAddShift{
public : 
  TyAddShift(std::shared_ptr<TyRegister> _y, std::shared_ptr<TyValue> _v, std::shared_ptr<TySize> _sz);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRegister> y;
  std::shared_ptr<TyValue> v;
  std::shared_ptr<TySize> sz;
};

struct TyAddSignbit{
public : 
  TyAddSignbit(std::shared_ptr<TyRegister> _x, std::shared_ptr<TyValue> _e1, std::shared_ptr<TyValue> _e2, std::shared_ptr<TySize> _sz);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRegister> x;
  std::shared_ptr<TyValue> e1;
  std::shared_ptr<TyValue> e2;
  std::shared_ptr<TySize> sz;
};

struct TyAddSub{
public : 
  TyAddSub(std::shared_ptr<TyRegister> _minusy, std::shared_ptr<TyRegister> _z, std::shared_ptr<TyValue> _x, std::shared_ptr<TyValue> _y, std::shared_ptr<TySize> _sz);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRegister> minusy;
  std::shared_ptr<TyRegister> z;
  std::shared_ptr<TyValue> x;
  std::shared_ptr<TyValue> y;
  std::shared_ptr<TySize> sz;
};

struct TyAddZextBool{
public : 
  TyAddZextBool(std::shared_ptr<TyRegister> _x, std::shared_ptr<TyRegister> _y, std::shared_ptr<TyValue> _b, std::shared_ptr<TyConstInt> _c, std::shared_ptr<TyConstInt> _cprime, std::shared_ptr<TySize> _sz);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRegister> x;
  std::shared_ptr<TyRegister> y;
  std::shared_ptr<TyValue> b;
  std::shared_ptr<TyConstInt> c;
  std::shared_ptr<TyConstInt> cprime;
  std::shared_ptr<TySize> sz;
};

struct TyAndDeMorgan{
public : 
  TyAndDeMorgan(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _x, std::shared_ptr<TyRegister> _y, std::shared_ptr<TyRegister> _z2);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRegister> z;
  std::shared_ptr<TyRegister> x;
  std::shared_ptr<TyRegister> y;
  std::shared_ptr<TyRegister> z2;
};

struct TyCommand{
public : 
  virtual void serialize(cereal::JSONOutputArchive& archive) const = 0;
};

struct TyConstFloat{
public : 
  TyConstFloat(double _float_value, std::shared_ptr<TyFloatType> _float_type);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  double float_value;
  std::shared_ptr<TyFloatType> float_type;
};

struct TyConstInt{
public : 
  TyConstInt(int _int_value, std::shared_ptr<TyIntType> _int_type);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  int int_value;
  std::shared_ptr<TyIntType> int_type;
};

struct TyConstant{
public : 
  virtual void serialize(cereal::JSONOutputArchive& archive) const = 0;
};

struct TyDivMone{
public : 
  TyDivMone(std::shared_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRegister> z;
};

struct TyDivSubSrem{
public : 
  TyDivSubSrem(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _b, std::shared_ptr<TyRegister> _a);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRegister> z;
  std::shared_ptr<TyRegister> b;
  std::shared_ptr<TyRegister> a;
};

struct TyDivSubUrem{
public : 
  TyDivSubUrem(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _b, std::shared_ptr<TyRegister> _a);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRegister> z;
  std::shared_ptr<TyRegister> b;
  std::shared_ptr<TyRegister> a;
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
  TyHints(std::string _module_id, std::string _function_id, std::string _opt_name, std::vector<std::shared_ptr<TyNopPosition>> _src_nop_positions, std::vector<std::shared_ptr<TyNopPosition>> _tgt_nop_positions, std::vector<std::shared_ptr<TyCommand>> _commands);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::string module_id;
  std::string function_id;
  std::string opt_name;
  std::vector<std::shared_ptr<TyNopPosition>> src_nop_positions;
  std::vector<std::shared_ptr<TyNopPosition>> tgt_nop_positions;
  std::vector<std::shared_ptr<TyCommand>> commands;
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
  TyMulAddDistributive(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _x, std::shared_ptr<TyRegister> _y, std::shared_ptr<TyRegister> _w);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRegister> z;
  std::shared_ptr<TyRegister> x;
  std::shared_ptr<TyRegister> y;
  std::shared_ptr<TyRegister> w;
};

struct TyMulBool{
public : 
  TyMulBool(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _x, std::shared_ptr<TyRegister> _y);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRegister> z;
  std::shared_ptr<TyRegister> x;
  std::shared_ptr<TyRegister> y;
};

struct TyMulCommutative{
public : 
  TyMulCommutative(std::shared_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRegister> z;
};

struct TyMulMone{
public : 
  TyMulMone(std::shared_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRegister> z;
};

struct TyMulNeg{
public : 
  TyMulNeg(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _mx, std::shared_ptr<TyRegister> _my);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRegister> z;
  std::shared_ptr<TyRegister> mx;
  std::shared_ptr<TyRegister> my;
};

struct TyMulShl{
public : 
  TyMulShl(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _y);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRegister> z;
  std::shared_ptr<TyRegister> y;
};

struct TyNegVal{
public : 
  TyNegVal(std::shared_ptr<TyConstInt> _c1, std::shared_ptr<TyConstInt> _c2, std::shared_ptr<TySize> _sz);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyConstInt> c1;
  std::shared_ptr<TyConstInt> c2;
  std::shared_ptr<TySize> sz;
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
  TyPositionCommand(std::shared_ptr<TyScope> _scope, std::string _register_name);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyScope> scope;
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
  TyPropagate(std::shared_ptr<TyPropagateObject> _propagate, std::shared_ptr<TyPropagateRange> _propagate_range);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyPropagateObject> propagate;
  std::shared_ptr<TyPropagateRange> propagate_range;
};

struct TyPropagateLessdef{
public : 
  TyPropagateLessdef(std::shared_ptr<TyExpr> _lhs, std::shared_ptr<TyExpr> _rhs, std::shared_ptr<TyScope> _scope);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyExpr> lhs;
  std::shared_ptr<TyExpr> rhs;
  std::shared_ptr<TyScope> scope;
};

struct TyPropagateNoalias{
public : 
  TyPropagateNoalias(std::shared_ptr<TyRegister> _lhs, std::shared_ptr<TyRegister> _rhs, std::shared_ptr<TyScope> _scope);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRegister> lhs;
  std::shared_ptr<TyRegister> rhs;
  std::shared_ptr<TyScope> scope;
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
  TyRegister(std::string _name, std::shared_ptr<TyTag> _tag);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::string name;
  std::shared_ptr<TyTag> tag;
};

struct TyRemNeg{
public : 
  TyRemNeg(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _my);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRegister> z;
  std::shared_ptr<TyRegister> my;
};

struct TyScope{
public : 
  virtual void serialize(cereal::JSONOutputArchive& archive) const = 0;
};

struct TySize{
public : 
  virtual void serialize(cereal::JSONOutputArchive& archive) const = 0;
};

struct TySubAdd{
public : 
  TySubAdd(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyValue> _my, std::shared_ptr<TyRegister> _x, std::shared_ptr<TyValue> _y, std::shared_ptr<TySize> _sz);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRegister> z;
  std::shared_ptr<TyValue> my;
  std::shared_ptr<TyRegister> x;
  std::shared_ptr<TyValue> y;
  std::shared_ptr<TySize> sz;
};

struct TySubConstAdd{
public : 
  TySubConstAdd(std::shared_ptr<TyRegister> _y, std::shared_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRegister> y;
  std::shared_ptr<TyRegister> z;
};

struct TySubConstNot{
public : 
  TySubConstNot(std::shared_ptr<TyRegister> _y, std::shared_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRegister> y;
  std::shared_ptr<TyRegister> z;
};

struct TySubMone{
public : 
  TySubMone(std::shared_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRegister> z;
};

struct TySubOnebit{
public : 
  TySubOnebit(std::shared_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRegister> z;
};

struct TySubRemove{
public : 
  TySubRemove(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _y, std::shared_ptr<TyValue> _a, std::shared_ptr<TyValue> _b, std::shared_ptr<TySize> _sz);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRegister> z;
  std::shared_ptr<TyRegister> y;
  std::shared_ptr<TyValue> a;
  std::shared_ptr<TyValue> b;
  std::shared_ptr<TySize> sz;
};

struct TySubRemove2{
public : 
  TySubRemove2(std::shared_ptr<TyRegister> _y, std::shared_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRegister> y;
  std::shared_ptr<TyRegister> z;
};

struct TySubSdiv{
public : 
  TySubSdiv(std::shared_ptr<TyRegister> _y, std::shared_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRegister> y;
  std::shared_ptr<TyRegister> z;
};

struct TySubShl{
public : 
  TySubShl(std::shared_ptr<TyRegister> _x, std::shared_ptr<TyRegister> _y, std::shared_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRegister> x;
  std::shared_ptr<TyRegister> y;
  std::shared_ptr<TyRegister> z;
};

struct TyTag{
public : 
  virtual void serialize(cereal::JSONOutputArchive& archive) const = 0;
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
  ConsId(std::shared_ptr<TyRegister> _register);
  static std::shared_ptr<TyValue> make(std::string _name, std::shared_ptr<TyTag> _tag);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRegister> register;
};

struct ConsConstInt : public TyConstant{
public : 
  ConsConstInt(std::shared_ptr<TyConstInt> _const_int);
  static std::shared_ptr<TyConstant> make(int _int_value, std::shared_ptr<TyIntType> _int_type);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyConstInt> const_int;
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
  ConsConstFloat(std::shared_ptr<TyConstFloat> _const_float);
  static std::shared_ptr<TyConstant> make(double _float_value, std::shared_ptr<TyFloatType> _float_type);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyConstFloat> const_float;
};

struct ConsConstVal : public TyValue{
public : 
  ConsConstVal(std::shared_ptr<TyConstant> _constant);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyConstant> constant;
};

struct ConsVar : public TyExpr{
public : 
  ConsVar(std::shared_ptr<TyRegister> _register);
  static std::shared_ptr<TyExpr> make(std::string _name, std::shared_ptr<TyTag> _tag);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRegister> register;
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
  ConsRhs(std::shared_ptr<TyRegister> _register, std::shared_ptr<TyScope> _scope);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRegister> register;
  std::shared_ptr<TyScope> scope;
};

struct ConsConst : public TyExpr{
public : 
  ConsConst(std::shared_ptr<TyConstant> _constant);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyConstant> constant;
};

struct ConsLessdef : public TyPropagateObject{
public : 
  ConsLessdef(std::shared_ptr<TyPropagateLessdef> _propagate_lessdef);
  static std::shared_ptr<TyPropagateObject> make(std::shared_ptr<TyExpr> _lhs, std::shared_ptr<TyExpr> _rhs, std::shared_ptr<TyScope> _scope);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyPropagateLessdef> propagate_lessdef;
};

struct ConsNoalias : public TyPropagateObject{
public : 
  ConsNoalias(std::shared_ptr<TyPropagateNoalias> _propagate_noalias);
  static std::shared_ptr<TyPropagateObject> make(std::shared_ptr<TyRegister> _lhs, std::shared_ptr<TyRegister> _rhs, std::shared_ptr<TyScope> _scope);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyPropagateNoalias> propagate_noalias;
};

struct ConsMaydiff : public TyPropagateObject{
public : 
  ConsMaydiff(std::shared_ptr<TyRegister> _register);
  static std::shared_ptr<TyPropagateObject> make(std::string _name, std::shared_ptr<TyTag> _tag);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRegister> register;
};

struct ConsPhinode : public TyPosition{
public : 
  ConsPhinode(std::shared_ptr<TyPositionPhinode> _position_phinode);
  static std::shared_ptr<TyPosition> make(std::string _block_name, std::string _prev_block_name);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyPositionPhinode> position_phinode;
};

struct ConsCommand : public TyPosition{
public : 
  ConsCommand(std::shared_ptr<TyPositionCommand> _position_command);
  static std::shared_ptr<TyPosition> make(std::shared_ptr<TyScope> _scope, std::string _register_name);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyPositionCommand> position_command;
};

struct ConsBounds : public TyPropagateRange{
public : 
  ConsBounds(std::shared_ptr<TyPosition> _position, std::shared_ptr<TyPosition> _position);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyPosition> position;
  std::shared_ptr<TyPosition> position;
};

struct ConsGlobal : public TyPropagateRange{
public : 
  ConsGlobal();
  void serialize(cereal::JSONOutputArchive& archive) const;
};

struct ConsPropagate : public TyCommand{
public : 
  ConsPropagate(std::shared_ptr<TyPropagate> _propagate);
  static std::shared_ptr<TyCommand> make(std::shared_ptr<TyPropagateObject> _propagate, std::shared_ptr<TyPropagateRange> _propagate_range);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyPropagate> propagate;
};

struct ConsAddAssociative : public TyInfrule{
public : 
  ConsAddAssociative(std::shared_ptr<TyAddAssociative> _add_associative);
  static std::shared_ptr<TyInfrule> make(std::shared_ptr<TyRegister> _x, std::shared_ptr<TyRegister> _y, std::shared_ptr<TyRegister> _z, std::shared_ptr<TyConstInt> _c1, std::shared_ptr<TyConstInt> _c2, std::shared_ptr<TyConstInt> _c3, std::shared_ptr<TySize> _sz);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyAddAssociative> add_associative;
};

struct ConsAddSub : public TyInfrule{
public : 
  ConsAddSub(std::shared_ptr<TyAddSub> _add_sub);
  static std::shared_ptr<TyInfrule> make(std::shared_ptr<TyRegister> _minusy, std::shared_ptr<TyRegister> _z, std::shared_ptr<TyValue> _x, std::shared_ptr<TyValue> _y, std::shared_ptr<TySize> _sz);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyAddSub> add_sub;
};

struct ConsAddCommutative : public TyInfrule{
public : 
  ConsAddCommutative(std::shared_ptr<TyAddCommutative> _add_commutative);
  static std::shared_ptr<TyInfrule> make(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyValue> _x, std::shared_ptr<TyValue> _y, std::shared_ptr<TySize> _sz);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyAddCommutative> add_commutative;
};

struct ConsAddShift : public TyInfrule{
public : 
  ConsAddShift(std::shared_ptr<TyAddShift> _add_shift);
  static std::shared_ptr<TyInfrule> make(std::shared_ptr<TyRegister> _y, std::shared_ptr<TyValue> _v, std::shared_ptr<TySize> _sz);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyAddShift> add_shift;
};

struct ConsAddSignbit : public TyInfrule{
public : 
  ConsAddSignbit(std::shared_ptr<TyAddSignbit> _add_signbit);
  static std::shared_ptr<TyInfrule> make(std::shared_ptr<TyRegister> _x, std::shared_ptr<TyValue> _e1, std::shared_ptr<TyValue> _e2, std::shared_ptr<TySize> _sz);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyAddSignbit> add_signbit;
};

struct ConsAddOnebit : public TyInfrule{
public : 
  ConsAddOnebit(std::shared_ptr<TyAddOnebit> _add_onebit);
  static std::shared_ptr<TyInfrule> make(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyValue> _x, std::shared_ptr<TyValue> _y);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyAddOnebit> add_onebit;
};

struct ConsAddZextBool : public TyInfrule{
public : 
  ConsAddZextBool(std::shared_ptr<TyAddZextBool> _add_zext_bool);
  static std::shared_ptr<TyInfrule> make(std::shared_ptr<TyRegister> _x, std::shared_ptr<TyRegister> _y, std::shared_ptr<TyValue> _b, std::shared_ptr<TyConstInt> _c, std::shared_ptr<TyConstInt> _cprime, std::shared_ptr<TySize> _sz);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyAddZextBool> add_zext_bool;
};

struct ConsAddConstNot : public TyInfrule{
public : 
  ConsAddConstNot(std::shared_ptr<TyAddConstNot> _add_const_not);
  static std::shared_ptr<TyInfrule> make(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _y);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyAddConstNot> add_const_not;
};

struct ConsAddMask : public TyInfrule{
public : 
  ConsAddMask(std::shared_ptr<TyAddMask> _add_mask);
  static std::shared_ptr<TyInfrule> make(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _y, std::shared_ptr<TyRegister> _yp);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyAddMask> add_mask;
};

struct ConsAddSelectZero : public TyInfrule{
public : 
  ConsAddSelectZero(std::shared_ptr<TyAddSelectZero> _add_select_zero);
  static std::shared_ptr<TyInfrule> make(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _x, std::shared_ptr<TyRegister> _y);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyAddSelectZero> add_select_zero;
};

struct ConsAddSelectZero2 : public TyInfrule{
public : 
  ConsAddSelectZero2(std::shared_ptr<TyAddSelectZero2> _add_select_zero2);
  static std::shared_ptr<TyInfrule> make(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _x, std::shared_ptr<TyRegister> _y);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyAddSelectZero2> add_select_zero2;
};

struct ConsAddDistSub : public TyInfrule{
public : 
  ConsAddDistSub(std::shared_ptr<TyAddDistSub> _add_dist_sub);
  static std::shared_ptr<TyInfrule> make(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _minusx, std::shared_ptr<TyRegister> _minusy, std::shared_ptr<TyRegister> _w);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyAddDistSub> add_dist_sub;
};

struct ConsMulAddDistributive : public TyInfrule{
public : 
  ConsMulAddDistributive(std::shared_ptr<TyMulAddDistributive> _mul_add_distributive);
  static std::shared_ptr<TyInfrule> make(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _x, std::shared_ptr<TyRegister> _y, std::shared_ptr<TyRegister> _w);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyMulAddDistributive> mul_add_distributive;
};

struct ConsSubMone : public TyInfrule{
public : 
  ConsSubMone(std::shared_ptr<TySubMone> _sub_mone);
  static std::shared_ptr<TyInfrule> make(std::shared_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TySubMone> sub_mone;
};

struct ConsSubAdd : public TyInfrule{
public : 
  ConsSubAdd(std::shared_ptr<TySubAdd> _sub_add);
  static std::shared_ptr<TyInfrule> make(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyValue> _my, std::shared_ptr<TyRegister> _x, std::shared_ptr<TyValue> _y, std::shared_ptr<TySize> _sz);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TySubAdd> sub_add;
};

struct ConsSubConstNot : public TyInfrule{
public : 
  ConsSubConstNot(std::shared_ptr<TySubConstNot> _sub_const_not);
  static std::shared_ptr<TyInfrule> make(std::shared_ptr<TyRegister> _y, std::shared_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TySubConstNot> sub_const_not;
};

struct ConsSubRemove : public TyInfrule{
public : 
  ConsSubRemove(std::shared_ptr<TySubRemove> _sub_remove);
  static std::shared_ptr<TyInfrule> make(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _y, std::shared_ptr<TyValue> _a, std::shared_ptr<TyValue> _b, std::shared_ptr<TySize> _sz);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TySubRemove> sub_remove;
};

struct ConsSubRemove2 : public TyInfrule{
public : 
  ConsSubRemove2(std::shared_ptr<TySubRemove2> _sub_remove2);
  static std::shared_ptr<TyInfrule> make(std::shared_ptr<TyRegister> _y, std::shared_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TySubRemove2> sub_remove2;
};

struct ConsSubOnebit : public TyInfrule{
public : 
  ConsSubOnebit(std::shared_ptr<TySubOnebit> _sub_onebit);
  static std::shared_ptr<TyInfrule> make(std::shared_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TySubOnebit> sub_onebit;
};

struct ConsSubConstAdd : public TyInfrule{
public : 
  ConsSubConstAdd(std::shared_ptr<TySubConstAdd> _sub_const_add);
  static std::shared_ptr<TyInfrule> make(std::shared_ptr<TyRegister> _y, std::shared_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TySubConstAdd> sub_const_add;
};

struct ConsSubSdiv : public TyInfrule{
public : 
  ConsSubSdiv(std::shared_ptr<TySubSdiv> _sub_sdiv);
  static std::shared_ptr<TyInfrule> make(std::shared_ptr<TyRegister> _y, std::shared_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TySubSdiv> sub_sdiv;
};

struct ConsSubShl : public TyInfrule{
public : 
  ConsSubShl(std::shared_ptr<TySubShl> _sub_shl);
  static std::shared_ptr<TyInfrule> make(std::shared_ptr<TyRegister> _x, std::shared_ptr<TyRegister> _y, std::shared_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TySubShl> sub_shl;
};

struct ConsMulBool : public TyInfrule{
public : 
  ConsMulBool(std::shared_ptr<TyMulBool> _mul_bool);
  static std::shared_ptr<TyInfrule> make(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _x, std::shared_ptr<TyRegister> _y);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyMulBool> mul_bool;
};

struct ConsMulMone : public TyInfrule{
public : 
  ConsMulMone(std::shared_ptr<TyMulMone> _mul_mone);
  static std::shared_ptr<TyInfrule> make(std::shared_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyMulMone> mul_mone;
};

struct ConsMulNeg : public TyInfrule{
public : 
  ConsMulNeg(std::shared_ptr<TyMulNeg> _mul_neg);
  static std::shared_ptr<TyInfrule> make(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _mx, std::shared_ptr<TyRegister> _my);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyMulNeg> mul_neg;
};

struct ConsMulCommutative : public TyInfrule{
public : 
  ConsMulCommutative(std::shared_ptr<TyMulCommutative> _mul_commutative);
  static std::shared_ptr<TyInfrule> make(std::shared_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyMulCommutative> mul_commutative;
};

struct ConsMulShl : public TyInfrule{
public : 
  ConsMulShl(std::shared_ptr<TyMulShl> _mul_shl);
  static std::shared_ptr<TyInfrule> make(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _y);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyMulShl> mul_shl;
};

struct ConsDivMone : public TyInfrule{
public : 
  ConsDivMone(std::shared_ptr<TyDivMone> _div_mone);
  static std::shared_ptr<TyInfrule> make(std::shared_ptr<TyRegister> _z);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyDivMone> div_mone;
};

struct ConsRemNeg : public TyInfrule{
public : 
  ConsRemNeg(std::shared_ptr<TyRemNeg> _rem_neg);
  static std::shared_ptr<TyInfrule> make(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _my);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyRemNeg> rem_neg;
};

struct ConsDivSubSrem : public TyInfrule{
public : 
  ConsDivSubSrem(std::shared_ptr<TyDivSubSrem> _div_sub_srem);
  static std::shared_ptr<TyInfrule> make(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _b, std::shared_ptr<TyRegister> _a);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyDivSubSrem> div_sub_srem;
};

struct ConsDivSubUrem : public TyInfrule{
public : 
  ConsDivSubUrem(std::shared_ptr<TyDivSubUrem> _div_sub_urem);
  static std::shared_ptr<TyInfrule> make(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _b, std::shared_ptr<TyRegister> _a);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyDivSubUrem> div_sub_urem;
};

struct ConsAndDeMorgan : public TyInfrule{
public : 
  ConsAndDeMorgan(std::shared_ptr<TyAndDeMorgan> _and_de_morgan);
  static std::shared_ptr<TyInfrule> make(std::shared_ptr<TyRegister> _z, std::shared_ptr<TyRegister> _x, std::shared_ptr<TyRegister> _y, std::shared_ptr<TyRegister> _z2);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyAndDeMorgan> and_de_morgan;
};

struct ConsNegVal : public TyInfrule{
public : 
  ConsNegVal(std::shared_ptr<TyNegVal> _neg_val);
  static std::shared_ptr<TyInfrule> make(std::shared_ptr<TyConstInt> _c1, std::shared_ptr<TyConstInt> _c2, std::shared_ptr<TySize> _sz);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyNegVal> neg_val;
};

struct ConsInfrule : public TyCommand{
public : 
  ConsInfrule(std::shared_ptr<TyPosition> _position, std::shared_ptr<TyInfrule> _infrule);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyPosition> position;
  std::shared_ptr<TyInfrule> infrule;
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

