//
//  ViewController.m
//  enno
//
//  Created by Vee on 27/09/21.
//

#import "ViewController.h"
//#import "OpenCVWrapper.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
//    print("\(OpenCVWrapper.openCVVersionString())")
    NSLog(OpenCVWrapper.openCVVersionString);
//    printf(OpenCVWrapper.openCVVersionString);
    // Do any additional setup after loading the view.
}


@end
