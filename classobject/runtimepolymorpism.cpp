#include <iostream>
#include <string>

using namespace std;

const string JPEG = "200";
const string MPEG = "300";
const string QUICK  ="400";

//Runtime polymorphism allows you to assign
//any subclass object to a super class reference
//or pointer and get the overriden method of
//the subclass get executed although you call
//the method through superclass reference or pointer.
//The binding between the method name and the its code
//happens at run time.
//Runtime binding binds the method name with the code
//of the class from which the actual object is made of.
//Runtime polymorphism in a concrete class.
class Codec {
public:
  //In order to enable runtime polymorphism
  //you need to make a function virtual
  //in the base/super class
  virtual int encode(int raw) {
    cout<<raw<<" encoded by Codec..."<<endl;
    return raw;
  }

  //In order to enable runtime polymorphism
  //you need to make a function virtual
  //in the base/super class
  virtual int decode(int encoded) {
    cout<<encoded<<" decoded by Codec..."<<endl;
    return encoded;
  }
};

class CodecJPEG : public Codec {
public:
  int encode (int raw) {
    cout<<raw<<" encoded by CodecJPEG..."<<endl;
    int jpeg = stoi(JPEG);
    return raw + jpeg/8;
  }

  int decode (int encoded) {
    cout<<encoded<<" decoded by CodecJPEG..."<<endl;
    int jpeg = stoi(JPEG);
    return encoded - jpeg/8;
  }
};

class CodecMPEG : public Codec {
public:
  int encode (int raw) {
    cout<<raw<<" encoded by CodecMPEG..."<<endl;
    int mpeg = stoi(MPEG);
    return raw + mpeg/6;
  }

  int decode (int encoded) {
    cout<<encoded<<" decoded by CodecMPEG..."<<endl;
    int mpeg = stoi(MPEG);
    return encoded - mpeg/6;
  }
};

class CodecQuick : public Codec {
public:
  int encode (int raw) {
    cout<<raw<<" encoded by CodecQuick..."<<endl;
    int quick = stoi(QUICK);
    return raw + quick/10;
  }

  int decode (int encoded) {
    cout<<encoded<<" decoded by CodecQuick..."<<endl;
    int quick = stoi(QUICK);
    return encoded - quick/10;
  }
};

int main() {
  Codec codec;
  CodecJPEG codecJPEG;
  CodecMPEG codecMPEG;
  CodecQuick codecQuick;
  int raw = 100;
  cout<<codec.encode(raw)<<endl;
  cout<<codecJPEG.encode(raw)<<endl;
  cout<<codecMPEG.encode(raw)<<endl;
  cout<<codecQuick.encode(raw)<<endl;


  cout<<"Runtime polymorphism...."<<endl;
  // Codec& refToCodec = codec;
  //Calls encode() from Codec class
  //since the object is from Codec class
  // cout<<refToCodec.encode(raw)<<endl;
  Codec& refToCodec = codecJPEG;
  //Calls encode() from CodecJPEG class
  //since the object is from CodecJPEG class
  cout<<refToCodec.encode(raw)<<endl;
  // Codec& refToCodec = codecMPEG;
  //Calls encode() from CodecMPEG class
  //since the object is from CodecMPEG class
  // cout<<refToCodec.encode(raw)<<endl;
  // Codec& refToCodec = codecQuick;
  //Calls encode() from CodecQuick class
  //since the object is from CodecQuick class
  // cout<<refToCodec.encode(raw)<<endl;


  return 0;
}
