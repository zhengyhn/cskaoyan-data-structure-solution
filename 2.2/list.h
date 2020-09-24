typedef int ElementType;

class List {
 public:
  int len;
  ElementType *data;
  List(ElementType data[], int len) : data(NULL), len(len) {
    this->data = new ElementType[len];
    for (int i = 0; i < len; ++i) {
      this->data[i] = data[i];
    }
  }
};