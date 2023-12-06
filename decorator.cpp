//
//  decorator.cpp
//  Stuctural_paterns
//
//  Created by Polina on 06.12.2023.
//

#include <stdio.h>
#include <iostream>
#include <string>

class Text{
public:
    virtual void render (const std::string& data) const{
        std::cout << data;
    }
};

//создаем обертку, которая будет принимать указатель на объект с текстом
//это абстрактный класс
class DecoratedText:public Text{
public:
    explicit DecoratedText(Text* text) : text_(text) {};
    Text* text_;
};

//создаем конкретную реализацию к декорированному тексту
class ItalicText:public DecoratedText{
public:
    explicit ItalicText(Text* text): DecoratedText(text){};
    //переопределяем (расширяем) метод для данного класса
    void render(const std::string& text)const{
        std::cout << "<i>";
        text_->render(text); //вызываем функцию из класса Text
        std::cout << "</i>";
    }
};

class BoldText:public DecoratedText{
public:
    explicit BoldText(Text* text):DecoratedText(text){};
    void render(const std::string& text) const{
        std::cout << "<b>";
        text_->render(text);
        std::cout << "/b" << std::endl;
    }
};

class Paragraph:public DecoratedText{
public:
    explicit Paragraph(Text* text): DecoratedText(text){};
    void render(const std::string& text) const{
        std::cout << "<p>";
        text_->render(text);
        std::cout << "</p>" << std::endl;
    }
};

class Reversed:public DecoratedText{
public:
    explicit Reversed(Text* text):DecoratedText(text){};
    void render (const std::string& text) const {
        std::string res = text;
        std::reverse(res.begin(), res.end());
        text_->render(res);
        std::cout << std::endl;
    }
};

class Link:public DecoratedText{
public:
    explicit Link(Text* text): DecoratedText(text){};
    void render (const std::string& link, const std::string& text) const{
        std::cout << "<a href=";
        text_->render(link);
        std::cout << ">";
        text_->render(text);
        std::cout << "</a>" << std::endl;
    }
};


int main_02 () {
   // auto text_block = new ItalicText(new BoldText(new Text));
    //мы не вызываем явным образом render() и з подклассов, то как у нас они вызывются?
    //это наследование вызывает render у каждого из подклассов?
  //  text_block->render("What the fuck is it??");
    
    auto tb1 = new Paragraph(new Text);
    tb1->render("Hi peace");
    
    auto tb2 = new Reversed(new Text);
    tb2-> render("Cualquier cosa");
    
    auto tb3 = new Link(new Text);
    tb3->render("netology.ru", "web-site");
    
    return 0;
}
