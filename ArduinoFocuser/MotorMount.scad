$fn=360;
boreBaseRadius=69/2;
boreTopRadius=77.2/2;
boreLength=75.35;
focusRod=8.9/2;
focusRodProtusion=30; // TO DO: Measure this
focusRodHolderWidth=43.2;
focusRodHolderLength=20; // TO DO: Measure this
focusRodCenterOffset=41.75;
focusRodRackWidth=12.0;
maxClamshellLength=28.6;
focusRodOffset=28.25;
focusRodInset=1;
focusRodLength=110;
finderBaseWidth=20;
finderBaseLength=30;

difference(){
    outerShell();
    telescopeBore();
}

module telescopeBore(){
    cylinder(boreLength, boreBaseRadius, boreTopRadius);
    translate([boreTopRadius-13, 0, focusRodCenterOffset]){
        cube([24, focusRodHolderWidth, focusRodHolderLength], center=true);
        rotate([90, 0, 0]){
            cylinder(focusRodLength, r=focusRod, center=true);
        }
    }
    translate([boreBaseRadius/2, 0, focusRodCenterOffset/2]){
        cube([focusRodCenterOffset, 13, focusRodCenterOffset], center=true);
    }
    translate([-1.5*boreTopRadius, -1*boreTopRadius, maxClamshellLength]){
        cube([finderBaseWidth*2, finderBaseLength*3, boreLength-maxClamshellLength]);
    }
    translate([-.7*boreTopRadius, -2*boreTopRadius, focusRodCenterOffset-5]){
        cube([finderBaseWidth*3, finderBaseLength*3, boreLength-focusRodCenterOffset+5]);
    }
}

module outerShell(){
    cylinder(boreLength, boreBaseRadius+5, boreTopRadius+5);
}