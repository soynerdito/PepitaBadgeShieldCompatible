import shutil

class ArduinoPrint:
    
    def appendCommandCombo(self, keyRegular, keyModifier, keyCommand ):
        self.reference[keyRegular] = self.getCommand(  keyCommand )
        self.reference[keyModifier] = self.getCommand(  keyCommand, 'MOD_SHIFT_LEFT' )
    
    def getCommand(self, key_command, modifier = 0 ):
        if modifier == 0 :
            return 'UsbKeyboard.sendKeyStroke( ' + key_command + ' );'
        else:
            return 'UsbKeyboard.sendKeyStroke( ' + key_command + ' , ' + modifier + ' );'

    def _appendValues( self, prepend, validRange ):
        for inValue in validRange:
            self.reference[ chr(inValue) ] = self.getCommand( prepend + chr(inValue).upper() )

    def __init__( self ):
        #Initialize dictionary
        self.reference = {}
        prepend = 'KEY_'
        #Get all Upper case
        self._appendValues(prepend, range(65,91))
        #Get all lower case
        self._appendValues(prepend, range(97,123) )
        #Get numbers
        self._appendValues(prepend, range(48,58) )
        #Miscelaneous characters
        self.appendCommandCombo( '/', '?' ,'KEY_SLASH' )
        self.appendCommandCombo( '\\', '|' ,'KEY_BACKSLASH' )   
        self.appendCommandCombo( '-', '_' ,'KEY_MINUS' )
        self.appendCommandCombo( ',', '<' ,'KEY_COMMA' )
        self.appendCommandCombo( '.', '>' ,'KEY_PERIOD' )
        self.appendCommandCombo( ';', ':' ,'KEY_SEMICOLON' )
        
        #self.reference['/'] = self.getCommand(  'KEY_SLASH' )
        #self.reference['?'] = self.getCommand(  'KEY_SLASH', 'MOD_SHIFT_LEFT' )
        #self.reference['\\'] = self.getCommand( 'KEY_BACKSLASH' )
        #self.reference['|'] =  self.getCommand( 'KEY_BACKSLASH', 'MOD_SHIFT_LEFT' )
        #self.reference['<'] =  self.getCommand( 'KEY_COMMA' , 'MOD_SHIFT_LEFT' )
        #self.reference['<'] =  self.getCommand( 'KEY_PERIOD' , 'MOD_SHIFT_LEFT' )
        self.reference[' '] =  self.getCommand( 'KEY_SPACE' )
        self.reference['.'] =  self.getCommand( 'KEY_PERIOD' )
        #self.reference['-'] =  self.getCommand( 'KEY_MINUS' )
        #self.reference['_'] =  self.getCommand( 'KEY_MINUS' , 'MOD_SHIFT_LEFT' )
        self.reference['('] =  self.getCommand( 'KEY_9' , 'MOD_SHIFT_LEFT' )
        self.reference[')'] =  self.getCommand( 'KEY_0' , 'MOD_SHIFT_LEFT' )    
        
        self.reference['`'] =  self.getCommand( 'KEY_TILDE' )
        self.reference["'"] =  self.getCommand( 'KEY_QUOTE' )
    
    

    def getNewLineCommand(self):
        return self.getCommand( 'KEY_ENTER' )
    
    def parse( self , in_value ):
        return self.reference[ in_value ]

    def showData(self):
        print self.reference
    




translator = ArduinoPrint()
fo = open('payload.txt', 'r')
outFileName = 'payload.ino'
shutil.copyfile( 'template.ino', outFileName )
outFile = open( outFileName , 'a' )
#print 'void doPayload(){'
outFile.write ( 'void doPayload(){\n' )
for line in fo :
    lineFix = line.strip()    
    for c in lineFix:
        #print '	' + translator.parse( c )
        outFile.write ( '	' + translator.parse( c ) + '\n' )
    #print '	' + translator.getNewLineCommand()
    outFile.write ( '	' + translator.getNewLineCommand() + '\n')

#print '}'
outFile.write ( '}\n' )
