const MAX_CARD = 16;

enum Bool { false, true };
enum ErrCode { noErr, overflow };

class Set {
  int elements[MAX_CARD];
  int card;
public:
  void    EmptySet() { card = 0; }
  Bool    Member(int);
  ErrCode AddElem(int);
  void    RemoveElem(int);
  void    Copy(Set*);
  Bool    Equal(Set*);
  void    Print();
  void    Intersect(Set*, Set*);
  ErrCode Union(Set*, Set*);
};

Bool Set::Member(int value) {
  for (int i = 0; i < card; ++i)
    if (elements[i] == value) return true;
  return false;
}

ErrCode Set::AddElem(int value) {
  for (int i = 0; i < card; ++i)
    if (elements[i] == value) return noErr;
    
  if (card >= MAX_CARD) return overflow;

  elements[card++] = value;
  return noErr;
}

void Set::RemoveElem(int value) {
  for (int i = 0; i < card; ++i)
    if (elements[i] == value) {
      for(; i < card; ++i)
        elements[i] = elements[i+1];
      --card;
    }
}

void Set::Copy(Set* set) {
  for (int i = 0; i < card; ++i)
    set->elements[i] = elements[i];
  set->card = card;
}

Bool Set::Equal(Set* set) {
  if (card != set->card) return false;
  for (int i = 0; i < card; ++i)
    if (!set->Member(elements[i])) return false;
  return true;
}

void Set::Print() {
  cout << "{";
  for (int i = 0; i < card - 1; ++i)
    cout << elements[i] << ",";
  if (card > 0)
    cout << elements[card-1];
  cout << "}\n";
}

