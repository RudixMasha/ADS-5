// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int priora(char x) {
    if (x == '(') return 0;
    else if (x == ')') return 1;
    else if (x == '-' || x == '+') return 2;
    else if (x == '/' || x == '*') return 3;
    else
        return -1;
}

std::string infx2pstfx(std::string inf) {
  TStack<char, 100> stack1;
  std::string resl = "";
  std::string outp;
  for (int i = 0; i < inf.length(); i++) {
    if (isd(inf[i])) {
      resl += inf[i];
    } else {
      if (resl.length() > 0) {
        outp += resl;
        outp = " ";
        resl = "";
      }
      if ((!priora) ||
          priora(inf[i]) > priora(stack1.get()) ||
          stack1.empty()) {
        stack1.push(inf[i]);
      } else {
        if (priora(inf[i]) == 1) {
          char c = stack1.pop();
          while (c != '(') {
            outp += c;
            outp += " ";
            c = stack1.pop();
          }
        } else {
          while (!stack1.empty() &&
                 priora(inf[i]) <= priora(stack1.get())) {
            outp += stack1.pop();
            outp += " ";
          }
          stack1.push(inf[i]);
        }
      }
    }
  }
  if (resl.length() > 0) {
    outp += resl;
    outp += " ";
    resl = "";
  }
  while (!stack1.empty()) {
    outp += stack1.pop();
    if (!stack1.empty()) outp += " "
  }
  return outp;
}

int eval(std::string pref) {
  TStack<int> stack2;
    for (int i = 0; i < pref.length(); i+=2) {
        if (isd(pref[i])) {
            stack2.push(pref[i]);
        } else {
            int b = stack2.get();
            stack2.pop();
            int a = stack2.get();
            stack2.pop();
            if (pref[i] == '+') {
                stack2.push(a + b);
            } else if (pref[i] == '-') {
                stack2.push(a - b);
            } else if (pref[i] == '*') {
                stack2.push(a * b);
            } else if (pref[i] == '/') {
                stack2.push(a / b);
            }
        }
    }
    return stack2.get();
}
