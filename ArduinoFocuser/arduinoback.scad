caseLength=110-4;
caseWidth=100;
caseHeight=60-3;
caseThickness=2;
$fn=30;


    caseBack(caseLength, caseWidth, caseThickness);
    rotate([0, -90, 0]){
        caseFront(caseWidth, caseHeight, caseThickness);
    }
    translate([72, 83, caseThickness]){
        rotate([0,0, -90])
            smallProtoStandoff();
    }



module caseFront(width, height, thickness){
    difference(){
    cube([height, width, thickness]);
        //translate([4,4,0]) screwHole(1.5, thickness);
        translate([height-3.5, 3.5, 0]) backscrewHole(1.5, thickness);
        translate([height-3.5, width-3.5, 0]) backscrewHole(1.5, thickness);
        //translate([4, width-4, 0]) screwHole(1.5, thickness);
        translate([thickness+6, 28, 0]) cube([13, 12, thickness]);
        translate([thickness+6, 59, 0]) cube([14, 13, thickness]);
        translate([thickness+25, 36, 0]) cube([8, 21.25, thickness]);
    }
}

module caseBack(length, width, thickness){
    difference(){
    cube([length, width, thickness]);
        translate([3.5,3.5,0]) screwHole(1.5, thickness);
        translate([length-3.5, 3.5, 0]) screwHole(1.5, thickness);
        translate([length-3.5, width-3.5, 0]) screwHole(1.5, thickness);
        translate([3.5, width-3.5, 0]) screwHole(1.5, thickness);
    }
    
    translate([0,width/2-53/2,thickness]){
        translate([15.5, 6.5, 0])
            standoff(4, 1.5);
        translate([17, 53.8, 0])
            standoff(4, 1.5);
        translate([67.3, 10.5, 0])
            standoff(4, 1.5);
        translate([67.3, 38.5, 0])
            standoff(4, 1.5);
    }
}

module screwHole(radius, thickness){
    cylinder(thickness, radius+.5, radius);
}

module backscrewHole(radius, thickness){
    cylinder(thickness, radius, radius+1);
}

module standoff(standoffHeight, screwRadius){
	overage=2;
	difference(){
		cylinder(standoffHeight, r=screwRadius+overage);        
		cylinder(standoffHeight, r=screwRadius);
	}
}


module smallProtoStandoff(){
    translate([2.25, 2.25, 0]) standoff(3, 1.5);
    translate([67.75, 2.25, 0]) standoff(3,1.5);
    translate([2.25, 27.75, 0]) standoff(3,1.5);
    translate([67.75, 27.75, 0]) standoff(3,1.5);
}