cthis
=====

This C library is not meant to be used in real life project ! This Hack will allow you to simulate the "this" mechanism.
Well known in object oriented-languages this lib bring it to the C languages.
  + Create a class using struct
  + Add a function pointer in it
  + Call the cthis_bind0p function to bind the struct pointer and the function

Exemple
-------

    struct Foo
    {
      void (*bar)();
    }

    static void foo_bar(Foo* this)
    {
      //Have fun with `this`
    }

    int main()
    {
      Foo foo;
      foo.bar = cthis_bind0p(&foo, &Foo_bar);
      foo.bar();
    }
