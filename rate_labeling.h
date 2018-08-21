
#ifndef rate_labeling_h
#define rate_labeling_h

TString get_leg(int j, TString charge){
    TString name;
    
    //Simple function that takes the info given and creates a label for the legend.
    
    if (j==0){
        name = "Run 0"+charge;
    }
    else if (j==1){
        name = "Run 1"+charge;
    }
    else if (j==2){
        name = "Run 2"+charge;
    }
    else if (j==3){
        name = "Run 3"+charge;
    }
    else if (j==4){
        name = "Run 4"+charge;
    }
    else if (j==5){
        name = "Run 5"+charge;
    }
    else if (j==6){
        name = "Run 6"+charge;
    }
    else if (j==7){
        name = "Run 7"+charge;
    }
    else if (j==8){
        name = "Run 8"+charge;
    }
    else if (j==9){
        name = "Run 9"+charge;
    }
    else if (j==10){
        name = "Run 10"+charge;
    }
    return name;
}


TString get_title(string subtract_or_no, string irr_or_ref, string type){
    
    TString title;
    TString sub;
    TString type_name;
    TString layer;
    
    // All these if functions take the argument provided when calling the program initially and create a nice title for the plot.
    if (subtract_or_no=="subtract"){
        sub = ", Background subtracted";
    }
    else if (subtract_or_no=="no"){
        sub = " ";
    }
    if (irr_or_ref=="irr"){
        layer = " Irradiated Layer, Hole (3,1)";
    }
    if (irr_or_ref=="irr_irr"){
        layer = " Irradiated Layer, Hole (2,2) (Irr.)";
    }
    else if (irr_or_ref=="ref"){
        layer = " Reference Layer, Hole (2,2)";
    }
    else if (irr_or_ref=="dark"){
        layer = " Dark Rate";
        sub = " ";
    }
    if (type=="LCT"){
        type_name="LCT Rate:";
    }
    else if (type=="CLCT"){
        type_name="CLCT Rate:";
    }
    else if (type=="ALCT"){
        type_name="ALCT Rate:";
    }
    
    
    title =type_name+layer+sub;
    return title;
}

#endif /* rate_labeling_h */
