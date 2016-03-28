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
class TyFloatType{
public : 
  virtual void serialize(JSONOutputArchive& archive) const = 0;

};
class TyIntType{
public : 
  virtual void serialize(JSONOutputArchive& archive) const = 0;

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
class ConsIntType : public TyIntType{
public : 
  ConsIntType(int _i);
  void serialize(JSONOutputArchive& archive) const;

private : 
  int i;

};
