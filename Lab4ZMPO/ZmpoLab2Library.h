#ifndef ZMPOLAB2LIBRARY_H
#define ZmpoLab2Library_H
#include "pch.h"
#include <stdio.h>
#include <conio.h>
#include <string>

using namespace std;


//constans chars
const int NEW_LINE = '\n';
const char A = 'a';
const char DOT = '.';
const char LEFT_BRACKET = '(';
const char RIGHT_BRACKET = ')';
const char CLOSING_CURLY_BRATCHED = ']';
const char QUATIATION_MARK = '\'';
const char SEMICOLON = ';';
const char OPENING_CURLY_BRATCHED = '[';
const char COMMA = ',';
//constans ints

const int MAX_COUNT_OF_CTABLE_OBJECTS = 200;
const int THERE_IS_NOT_SUCH_OBJECT = -1;

//constans strings eng
const string CMENU_OBJECTS_HAVENT_DESCRIPTION = "CMenu objects haven't description";
const string CLASS_CMENUCOMMAND = "class CMenuCommand";
const string CLASS_CMENU = "class CMenu";
const string MENU_STRUCTURE_ISNT_PREPARED = "Menu structure isn't prepared";
const string COMMA_QUATIATION_MARK = ",'";
const string EMPTY_STRING = "";
const string RIGHT_ARROW = "->";
const string BEFORE_SYNAX = ". Before synax: ";
const string LACK_OF_COMMAND = "";
const string INCORECT_SYNAX_DOT_EXPECTED = "Incorect synax. Expected:";
const string AT_POSITION= " at position ";
const string MAIN = "main";
const string BACK = "back";
const string MENU = "menu";
const string SEARCH = "search ";
const string HELP = "help ";
const string ADD = "add";
const string LEN = "len";
const string DELALL = "delall";
const string RENAME = "rename";
const string DEL = "del";
const string CLON = "clon";
const string DATA = "data";
const string CHANGE = "change";
const string LAB1 = "lab1";
const string END = "end";
const string MENU_STRUC = "menustruc";
//constans strings pl
const string MENU_STRUCTURE = "Struktura menu";
const string THERE_IS_NOT_OPTION_LIKE_THIS = "Nie ma takiej pozycji";
const string YOU_CANT_USE_THIS_OPTION_NOW_CHOSE_ANOTHER_OPTION = "Nie mozesz teraz uzyc tej opcji, wybierz inna opcje";
const string PROGRAM_DISPLAYS = "program displays:";
const string DEFAULT_COMMAND = "Komenda domyœlna";
const string MAIN_MENU = "Main menu";
const string TAB_KEY_TO_CONTINUE = "Tab key to continue";
const string GIVE_OBJECT_NUMBER = "Podaj numer objektu:";
const string GIVE_IT_AGAIN = "Podat ponownie";
const string INCORECT_OBJECT_NUMBER_WRITE_IT_AGAIN = "Nieprawidlowy numer obiektu. Podaj numer ponownie:";
const string HOW_MANY_OBJECT_CREATE = "Ile obiektow stworzyc: ";
const string WRITE_VALUES_1_TO_MAX_COUNT_OF_CTABLE_OBJECTS = "Wpisz wartosc calkowita od 1 do "+to_string(MAX_COUNT_OF_CTABLE_OBJECTS)+":";
const string COLON = " : ";
const string END_OF_PROGRAM = "Zakonczenie pracy programu";
const string I_CHOSE = "Wybieram:";
const string GIVE_NEW_OBJECT_NAME = "Podaj nazwe nowego obiektu numer ";
const string GIVE_NEW_OBJECT_TABLE_SIZE = "Podaj rozmiar tablicy nowego obiektu numer ";
const string OBJECT_ADDING_ENDES_WITH_SUCCESS = "Pomyslnie zakonczono dodawanie obiektow";
const string GIVE_NEW_TABLE_LENGTH = "Podaj nowa dlugosc Tablicy";
const string TABLE_LENGTH_CANT_BE_NEGATIVE = "Dlugosc tablicy musi byc nieujemna:";
const string TABLE_SIZE_CHANGE_ENDES_WITH_SUCCESS = "Pomyslnie zakonczono zmiane dlugosci tablicy";
const string DELETING_ALL_OBJECTS_ENDS_WITH_SUCCESS = "Pomyslnie usunieto wszystkie obiekty CTable";
const string GIVE_NEW_NAME_OF_CTABLE_OBJECT = "Podaj nowa nazwe obiektu klasy CTable:";
const string LIST_HAVE_NOW = "Lista posiada teraz ";
const string ELEMENTS = " elementow";
const string THERE_IS_AN_MISTAKE_IT_ARENT_ALL_INFORMATIONS_ABOUT_OBJECT = "Wystapil blad. To nie sa wszystkie informacje o obiekcie";
const string GIVE_NEW_VALUE = "Podaj nowa wartosc:";
const string GIVE_POSITION_IN_TABLE = "Podaj pozycje w tablicy:";
const string INCORECT_TABLE_POSITION_GIVE_IT_AGAIN = "Nieprawidlowa pozycja w tablicy. Podaj j¹ ponownie:";
const string VALUE_CHANGED_SUCCESFULLY = "Pomyslnie zmieniono wartosc";
const string TRY_AGAIN = "Sprobuj ponownie";
const string CHOOSE_OPTION_TAPING_IT_MENU_NUMBER = "Wybierz opcje wpisujac jej numer w menu";
const string END_PROGRAM_WORK = "Zakoncz dzialanie programu";
const string MAKE_NEW_CTABLE_OBJECTS = "Utworz nowe obiekty typu CTabe";
const string CHANGE_TABLE_LENGTH_IN_CTABLE_OBJECT = "Zmien dlugosc tablicy w dowolnym obiekcie typu CTable";
const string DELETE_CTABLE_OBJECT = "Skasuj dowolny obiekt typu CTable";
const string DELETE_ALL_CTABLE_OBJECTS = "Skasuj wszystkie obiekty typu CTable";
const string CHANGE_CTABLE_OBJECT_NAME = "Zmien nazwe obiektu typu CTable";
const string WRITE_DATA_ABOUT_CTABLE_OBJECT = "Wypisz dane dotyczace obiektu typu CTable";
const string CHANGE_VALUE_IN_TABLE_IN_CTABLE_OBJECT = "Zmien wartosc w tablicy w obiekcie typu CTable";
const string CLASSES_MODYFICATION_CHANGE_TABLE_SIZE_AT_1 = "Modyfikacja na zajeciach: zmien rozmiar  tablicy na 1";
const string TAKE_OPTION_WRITING_ITS_NUMBER_FROM_MENU = "Wybierz opcje wpisujac jej numer w menu";
const string PROGRAM_FOR_USE_CTABLE_OBJECTS = "Program do obslugi obiektow typu CTable";
const string CLONE_CTABLE_OBJECT_AND_ADD_CLON_TO_LIST = "Sklonuj obiekt typu CTable i dodaj klon na listê";
const string MENU_1 = "menu1";
const string SUBMENU_1 = "Podmenu1";
const string MENU_2 = "menu2";
const string SUBMENU_2 = "Podmenu2";
const string INTERNET = "internet";
const string RUN_BROWSER = "Run Browser";
const string TEST_ = "test";
const string ALA = "ala";
const string ALA_HAS_CAT = "Ala has cat";
const string TEST = "Test";
const string DEF_COM = "defcom";
const string DAFAULT_COMMAND = "Defauld command";
const string TEST_IS_COMPLEATED = "Test zosta³ zakonczony pomyslnie";
const string BROWSER_WORKS = "Przegladaeka uruchomiona";
const string WRITE_ALA_HAS_CAT = "Write Ala Has Cat";
//CComands descriptions

const string WRITES_ALA_HAS_CAT = "Writes Ala Has Cat";
const string TESTS_PROGRAM_WORK = "Tests program work";
const string RUNS_BROWSER = "Runs browser";



//functions declarations

void waitForKey();

#endif