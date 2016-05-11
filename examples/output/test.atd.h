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

struct TyFloatType{
public : 
  virtual void serialize(cereal::JSONOutputArchive& archive) const = 0;
};

struct TyIntType{
public : 
  virtual void serialize(cereal::JSONOutputArchive& archive) const = 0;
};

struct ConsConstFloat : public TyConstant{
public : 
  ConsConstFloat(std::shared_ptr<TyConstFloat> _const_float);
  static std::shared_ptr<TyConstant> make(double _float_value, std::shared_ptr<TyFloatType> _float_type);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyConstFloat> const_float;
};

struct ConsConstInt : public TyConstant{
public : 
  ConsConstInt(std::shared_ptr<TyConstInt> _const_int);
  static std::shared_ptr<TyConstant> make(int _int_value, std::shared_ptr<TyIntType> _int_type);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  std::shared_ptr<TyConstInt> const_int;
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

struct ConsFloatType : public TyFloatType{
public : 
  ConsFloatType();
  void serialize(cereal::JSONOutputArchive& archive) const;
};

struct ConsHalfType : public TyFloatType{
public : 
  ConsHalfType();
  void serialize(cereal::JSONOutputArchive& archive) const;
};

struct ConsIntType : public TyIntType{
public : 
  ConsIntType(int _i);
  void serialize(cereal::JSONOutputArchive& archive) const;

private : 
  int i;
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

