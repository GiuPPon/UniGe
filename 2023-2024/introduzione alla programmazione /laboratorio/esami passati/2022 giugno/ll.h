struct elem {
  char c;
  struct elem * next;
};

typedef elem * ll;

void addhead(ll &s, char & c);
bool removehead(ll &s, char & c);
int size(ll s);
