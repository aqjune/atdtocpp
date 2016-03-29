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
struct TyExpr{
public : 
  virtual void serialize(cereal::JSONOutputArchive& archive) const = 0;
};
struct TyFloatType{
public : 
  virtual void serialize(cereal::JSONOutputArchive& archive) const = 0;
};
struct TyInfrule{
public : 
  virtual void serialize(cereal::JSONOutputArchive& archive) const = 0;
};
struct TyIntType{
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
struct TyRegister{
public : 
  TyRegister(std::string _name, std::unique_ptr<TyTag> _tag);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::string name;
  std::unique_ptr<TyTag> tag;
};
struct TyScope{
public : 
  virtual void serialize(cereal::JSONOutputArchive& archive) const = 0;
};
struct TySize{
public : 
  virtual void serialize(cereal::JSONOutputArchive& archive) const = 0;
};
struct TyTag{
public : 
  virtual void serialize(cereal::JSONOutputArchive& archive) const = 0;
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
struct ConsConstInt : public TyConstant{
public : 
  ConsConstInt(std::unique_ptr<TyConstInt> _const_int);
  static std::unique_ptr<TyConstant> make(int _int_value, std::unique_ptr<TyIntType> _int_type);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyConstInt> const_int;
};
struct ConsConstFloat : public TyConstant{
public : 
  ConsConstFloat(std::unique_ptr<TyConstFloat> _const_float);
  static std::unique_ptr<TyConstant> make(double _float_value, std::unique_ptr<TyFloatType> _float_type);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyConstFloat> const_float;
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
struct ConsAddAssociative : public TyInfrule{
public : 
  ConsAddAssociative(std::unique_ptr<TyAddAssociative> _add_associative);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyRegister> _x, std::unique_ptr<TyRegister> _y, std::unique_ptr<TyRegister> _z, std::unique_ptr<TyConstInt> _c1, std::unique_ptr<TyConstInt> _c2, std::unique_ptr<TyConstInt> _c3, std::unique_ptr<TySize> _sz);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyAddAssociative> add_associative;
};
struct ConsId : public TyValue{
public : 
  ConsId(std::unique_ptr<TyRegister> _register);
  static std::unique_ptr<TyValue> make(std::string _name, std::unique_ptr<TyTag> _tag);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyRegister> register;
};
struct ConsConstVal : public TyValue{
public : 
  ConsConstVal(std::unique_ptr<TyConstant> _constant);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyConstant> constant;
};
struct ConsTransitivityPointersLhs : public TyInfrule{
public : 
  ConsTransitivityPointersLhs(std::unique_ptr<TyTransitivityPointerLhs> _transitivity_pointer_lhs);
  static std::unique_ptr<TyInfrule> make(std::unique_ptr<TyValue> _p, std::unique_ptr<TyValue> _q, std::unique_ptr<TyValue> _v, std::unique_ptr<TyExpr> _loadq);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::unique_ptr<TyTransitivityPointerLhs> transitivity_pointer_lhs;
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
