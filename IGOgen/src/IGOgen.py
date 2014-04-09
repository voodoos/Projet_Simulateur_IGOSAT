#!/usr/bin/env python
# -*- coding: UTF-8 -*-
import os, subprocess
from array import *

moduleName = "Module"
xmlPath = "module.xml"
messages = []#{'name':"m1", 'time':5}, {'name':"m2", 'time':2}
sockets = []#{'name':"s1"}
parameters = []#{'name':"p1", 'value':10, 'unit':"Ohm"}, {'name':"p2", 'value':20, 'unit':"Votre"}
isMacro = None

def addSocket():
	name=raw_input("Tapez le nom d'un socket: ")
	s = {'name':name}

	global sockets
	sockets.append(s)

def addParameter():
	name=raw_input("Tapez le nom d'un parametre: ")
	value=raw_input("Tapez la valeur d'un parametre: ")
	unit=raw_input("Tapez l'unité d'un parametre: ")

	p = {'name':name, 'value':value, 'unit':unit}

	global parameters
	parameters.append(p)

def addMessage():
	name=raw_input("Tapez le nom d'un message: ")
	time=raw_input("Tapez le temps de transmission d'un message: ")

	m = {'name':name, 'time':time}

	global messages
	messages.append(m);

def generateXML():

	xmlFile = open(xmlPath, "w")

	#Creation XML

	xmlFile.write("\n")
	xmlFile.write("<?xml version=\"1.0\" encoding=\"utf-8\"?>\n")
	xmlFile.write("<module name=\""+moduleName+"\">\n")

	#Parameter nodes

	xmlFile.write("    <parameters>\n")

	for i,parameter in enumerate(parameters):
		xmlFile.write("    		<parameter name=\""+parameter['name']+"\">\n")
		xmlFile.write("	   			<unit>"+parameter['unit']+"</unit>\n")
		xmlFile.write("	   			<value>"+str(parameter['value'])+"</value>\n")
		xmlFile.write("    		</parameter>\n")

	xmlFile.write("    </parameters>\n")

	#Message nodes

	xmlFile.write("    <messages>\n")

	for i,message in enumerate(messages):
		xmlFile.write("    		<message name=\""+message['name']+"\">\n")
		xmlFile.write("	   			<time>"+str(message['time'])+"</unit>\n")
		xmlFile.write("    		</message>\n")
	
	xmlFile.write("    </messages>\n")

	#Socket nodes

	xmlFile.write("    <sockets>\n")

	for i,socket in enumerate(sockets):
		xmlFile.write("    		<socket name=\""+socket['name']+"\">\n")
		xmlFile.write("    		</socket>\n")
	
	xmlFile.write("    </socket>\n")

	xmlFile.write("</module>\n")
	xmlFile.write("\n")

	xmlFile.close()


def generateCPP():

	implementationFile = open(moduleName+".cpp", "w")

	#Creation of class implementation
	implementationFile.write("\n")
	implementationFile.write("#include \""+moduleName+".h\"")
	implementationFile.write("\n")
	implementationFile.write("using namespace std;\n")
	implementationFile.write("\n")

	if isMacro:	
		implementationFile.write(moduleName+"::"+moduleName+"(std::string name, Params params) : MacroModule(name, params, \""+xmlPath+"\"){\n")
	else:
		implementationFile.write(moduleName+"::"+moduleName+"(std::string name, Params params) : Module(name, params, \""+xmlPath+"\"){\n")

	implementationFile.write("\n")
	implementationFile.write(moduleName+"::~"+moduleName+"() {\n")
	implementationFile.write("\n")
	implementationFile.write("}\n")
	implementationFile.write("\n")
	implementationFile.write("void "+moduleName+"::process(shared_ptr<Message>){\n")
	implementationFile.write("\n")
	implementationFile.write("}\n")

	implementationFile.close()
	
def generateHPP():
	headerFile = open(moduleName+".hpp", "w")

	#Creation of class declaration
	headerFile.write("#pragma once\n")
	headerFile.write("#include <iostream>\n")

	if isMacro:	
		headerFile.write("include \"MacroModule.h\"\n")
	else:
		headerFile.write("include \"Module.h\"\n")

	headerFile.write("/*!\n")
	headerFile.write("* \class "+moduleName+"\n")
	headerFile.write("* \\brief Description d'un module\n")
	headerFile.write("*\n")
	headerFile.write("*/\n")

	if isMacro:	
		headerFile.write("class "+moduleName+":public MacroModule{\n")
	else:
		headerFile.write("class "+moduleName+":public Module{\n")

	headerFile.write("public:\n")
	headerFile.write(" "+moduleName+"(std::string name, Params params = Params());\n")
	headerFile.write(" virtual ~"+moduleName+"();\n")
	headerFile.write("private:\n")
	headerFile.write(" virtual void process(std::shared_ptr<Message>);\n")
	headerFile.write("};\n")

	headerFile.close()

def generateClass():
	generateHPP()
	generateCPP()
	

options = {		'1' : addMessage,
          		'2' : addSocket,
           		'3' : addParameter,
           		'4' : generateClass,
           		'5' : generateXML
}


def main():
	choix = 0;

	print "Choisissez une composante à créer:"
	print "[1] : Module"
	print "[2] : Macromodule"
	while choix not in ["1","2"]:
		choix=raw_input("Votre choix: ")

	global isMacro
	isMacro = choix==1

	global moduleName
	moduleName=raw_input("Tapez le nom d'un module:")
	global xmlPath
	xmlPath=raw_input("Tapez le chemin vers fichier .xml avec la description d'un module: ")
	choix = 0

	while 1:
		print "Choisissez une composante à créer:"
		print "[1] : Ajouter un message"
		print "[2] : Ajouter un socket"
		print "[3] : Ajouter un parametre"
		print "[4] : Generer les .cpp + .hpp"
		print "[5] : Generer .xml"
		print "[6] : Sortie"
		while choix not in ["1","2","3","4","5","6"]:
			choix=raw_input("Votre choix: ")
		if choix == '6':
			break
		options[choix]()
		choix = 0


if __name__ == "__main__":
    main()