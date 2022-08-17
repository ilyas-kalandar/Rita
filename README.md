# Rita - just programming language created from scratch!

## Motivation.
Every programmer must write at least one compiler/interpreter, I follow this idea :D

# What can Rita?
Currently interpreter can execute this program
```kotlin
fun main(){
    print("LOG: Main function loaded");

    var a = 1;
    var b = -1;
    var c = -20;

    print("LOG: Variables created");

    var d = (b * b) - (4 * a * c);

    print("LOG: Discriminant computed, value is", d.toString(d));

    print("LOG: Checking for D < 0");

    if(d < 0){
        print("No roots.");
        return;
    }

    print("LOG: Checking for D equals to 0");

    if(d == 0){
        print("One root.");
        print("Root", -b / (2 * a));

        return;
    }
    

    var x1 = (-b + sqr(d)) / (2 * a);
    var x2 = (-b - sqr(d)) / (2 * a);

    print("LOG: Roots computed.");

    print("Two roots.");
    print("First root:", x1.toString(x1));
    print("Second root:", x2.toString(x2));
}

main();

```

# Tutorial

## Variables
Rita is dynamically typed language, you don't need to provide a typename for creating a variable, just only use var-keyword provide name and value!

```kotlin
var varName = "Hello, Rita!";
```

## Functions
Rita support functions (fully), you can create, call, return values and provide arguments to your functions

```kotlin
// Create function with fun - keyword.

fun functionName(arg){
  anotherFunc(); // call another function.
  print(arg);
  return;
}
```

## If statements.

If statement in Rita is similiar to Rust, if keyword, expression and body.

```kotlin
if a > 0{
  print("Really, a is bigger than 0!");
}
```

## While statements

Rita support while statements, use while-keyword, provide expression and code-block.

```kotlin

var a = 100;

while a > 0 {
    print("working");
    a -= 1;
}

```

## Operators
Yes, you can use operators, priorities in Rita are fully correct.

```kotlin
var a = 2 + 2 * 3; // a equals to 8
```

## Standard-functions
```kotlin
sqr(); // Returns a square root of Int-object.
print(); // Prints string to terminal
input(); // EXPERIMENTAL! Returns a string given from user.
```

# Building

```bash
# Clone repo
git clone https://github.com/ilyas-qalandarzoda/Rita
cd Rita && mkdir build && cd build
# Build 
cmake .. && cmake --build .

# Run
./rita --help
```

## TODO
- [X] - While-loops
- [ ] - Classes
- [ ] - Floats

## Author
Created with ♥ by Ilyas Qalandarzoda (Awaitable)

## Contacts
I always check my <a href='https://t.me/awaitable'>telegram</a>
