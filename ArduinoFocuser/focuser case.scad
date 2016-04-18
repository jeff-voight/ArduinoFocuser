caseLength=110;
caseWidth=100;
caseHeight=60;
caseThickness=2;
standoffHeight=4;
caseScrewHeight=7;
$fn=30;


topPanel(caseLength, caseWidth, caseThickness);
translate([0, 0,  0]){
    rotate([90, 0, 0]){
        leftPanel(caseLength, caseHeight, caseThickness);
    }
}
translate([0 , caseWidth+caseThickness, 0]){
    rotate([90, 0, 0]){
        rightPanel(caseLength, caseHeight, caseThickness);
    }
}

translate([0,-1*caseThickness,0]){
    rotate([0, -90, 0]){
        endPanel(caseHeight, caseWidth+caseThickness*2, caseThickness);
    }
}

module topPanel(length, width, thickness){
    xor(){
        cube([length, width, thickness]);
        translate([5, 5, 0])
            knobBore(thickness);
        translate([29, 5, 0])
            buttonBoard(caseThickness);
        translate([6, 50, 0]){
            LCD_Panel(caseThickness);
        }
    }
    
//    translate([length-caseThickness-caseScrewHeight, width-caseScrewHeight, caseScrewHeight-caseThickness]){        
//            screwSocket(caseScrewHeight, caseThickness, 1);        
//    }
    translate([length-caseScrewHeight-caseThickness, 0, caseScrewHeight-caseThickness*2]){        
            screwSocket(caseScrewHeight, caseThickness, 1);        
    }
}

module leftPanel(length, width, thickness){
    cube([length, width, thickness]);
    translate([caseThickness, width-caseThickness, 2-caseThickness]){
        verticalScrewSocket(caseScrewHeight, caseThickness, 1);
    }
    translate([length-caseThickness-caseScrewHeight, width-caseThickness, caseThickness-2]){
        verticalScrewSocket(caseScrewHeight, caseThickness, 1);
    }
}

module rightPanel(length, width, thickness){
    cube([length, width, thickness]);
    translate([caseThickness, width-caseThickness, caseThickness+caseScrewHeight]){
        verticalScrewSocket(caseScrewHeight, caseThickness, 1);
    }
    translate([length-caseThickness-caseScrewHeight, width-caseThickness, caseScrewHeight+2]){
        verticalScrewSocket(caseScrewHeight, caseThickness, 1);
    }
}

module endPanel(length, width, thickness){
    mirror([0, 0, 180])
    xor(){
        cube([length, width, thickness]);
        translate([20, 40, 0])
            tempBore(caseThickness);
        
    }
}

module LCD_Panel(caseThickness){
    lcdPanelLength=98;
    lcdPanelWidth=40;
    screwOffsetX=2.075;
    screwOffsetY=-7.675;
    cube([lcdPanelLength, lcdPanelWidth, caseThickness]);
    translate([screwOffsetX, screwOffsetY, caseThickness]) standoff(5, 1.2);  // TO DO: Correct location
    translate([lcdPanelLength-screwOffsetX, lcdPanelWidth-screwOffsetY, caseThickness]) standoff(5, 1.2);
    translate([screwOffsetX, lcdPanelWidth-screwOffsetY, caseThickness]) standoff(5, 1.2);
    translate([lcdPanelLength-screwOffsetX, screwOffsetY, 1]) standoff(5, 1.2);
}

module knobBore(caseThickness){
    mountThickness=1;
    standoffKnobSquareBore=14.5;
    standoffKnobSquareHeight=6;
    // outer walls
    standoffBoxSize=standoffKnobSquareBore+mountThickness*2;
    standoffKnobBore=9;
    standoffKnobBoreDepth=5.8;
    standoffKnobHole=3.5;
    standoffBoxHeight=standoffKnobBoreDepth+standoffKnobSquareHeight;
    translate([1, 2, 0]){
    difference(){
//    // Rectangular Holder
            translate([0,0,caseThickness])
                cube([standoffBoxSize,   standoffBoxSize, standoffBoxHeight]);        
            translate([(standoffBoxSize-standoffKnobBore)/2, (standoffBoxSize-standoffKnobBore)/2, caseThickness]) 
                cube(standoffKnobBore, standoffKnobBore, standoffKnobBoreDepth);
            translate([mountThickness, mountThickness, caseThickness+standoffKnobBoreDepth])
                cube([standoffKnobSquareBore, standoffKnobSquareBore, standoffKnobSquareHeight]);
            
        };
        translate([standoffBoxSize/2, standoffBoxSize/2, 0])
            cylinder(caseThickness, r=standoffKnobHole);
    }
    translate([16, 25, caseThickness]) standoff(standoffBoxHeight, 1.5);
}

module buttonBoard(){

    translate([11.2, 7.35, 0]) Button_Holder(caseThickness);
    translate([12.2, 18.35, 0]) LED_Holder(caseThickness);

    translate([26.4, 7.35, 0]) Button_Holder(caseThickness);
    translate([27.2, 18.35, 0]) LED_Holder(caseThickness);

    translate([41.6, 7.35, 0]) Button_Holder(caseThickness);
    translate([42.2, 18.35, 0]) LED_Holder(caseThickness);

    translate([56.8, 7.35, 0]) Button_Holder(caseThickness);
    translate([57.2, 18.35, 0]) LED_Holder(caseThickness);
    
    translate([2.25, 2.25, caseThickness]) standoff(3, 1.5);
    translate([67.75, 2.25, caseThickness]) standoff(3,1.5);
    translate([2.25, 27.75, caseThickness]) standoff(3,1.5);
    translate([67.75, 27.75, caseThickness]) standoff(3,1.5);
    
}


/*module standoff(standoffHeight, screwRadius){
	overage=1;
	difference(){
		cylinder(standoffHeight, r=screwRadius+overage);
		cylinder(standoffHeight, r=screwRadius);
	}
}*/


module Button_Holder(caseThickness){
    buttonHoleRadius=4;
    cylinder(caseThickness, buttonHoleRadius*1.7, buttonHoleRadius);
    cylinder(caseThickness-1, r=buttonHoleRadius*1.7);

}

module LED_Holder(caseThickness){

    ledRadius=3;
    cylinder(caseThickness, r=ledRadius);
}



module tempBore(caseThickness){
    mountThickness=1;
    standoffSquareBoreWidth=15;
    standoffSquareBoreLength=19;
    standoffSquareHeight=2;
    standoffBoxSize=standoffSquareBoreWidth+mountThickness*2;    
    translate([1.5, 1.5, 0]){
        difference(){
            translate([0,0,caseThickness])
                cube([standoffSquareBoreWidth+mountThickness*2,standoffSquareBoreLength+mountThickness*2, standoffSquareHeight]);        
            translate([mountThickness, mountThickness, 0]) 
                cube([standoffSquareBoreWidth, standoffSquareBoreLength, standoffSquareHeight+caseThickness+1]);
     
        };
        translate([mountThickness, mountThickness, 0]) 
            cube([standoffSquareBoreWidth, standoffSquareBoreLength,caseThickness]);
        
    }
    translate([1.5+(mountThickness+standoffSquareBoreWidth)/2, 25, caseThickness]) standoff(standoffSquareHeight, 1.5);
}


module standoff(standoffHeight, screwRadius){
	overage=2;
	difference(){
		cylinder(standoffHeight, r=screwRadius+overage);
        
            cylinder(standoffHeight, r=screwRadius);
	}
}

module screwSocket(standoffHeight, caseDepth, screwRadius){
    overage=1;
    boxSize=standoffHeight;//+overage*2;
    difference(){
		cube(boxSize);
        rotate([90, 0, 90]){
        translate([boxSize/2, boxSize/2, 0]){            
                cylinder(boxSize, r=screwRadius);
            }
        }
    }
}

module verticalScrewSocket(standoffHeight, caseDepth, screwRadius){
    overage=1;
    boxSize=standoffHeight;//+overage*2;
   rotate([0, -270, -90])
    difference(){
		cube(boxSize);        
        translate([boxSize/2, boxSize/2, 0]){            
                cylinder(boxSize, r=screwRadius);
            }
       }
}

module xor(){
    difference(){
        union(){
            children(0);
//            children(1);
            children([1:$children-1]);
        };
        intersection(){
            children(0);
//            children(1);
            children([1:$children-1]);
        }
    }
}