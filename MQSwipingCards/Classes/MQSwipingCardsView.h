//
//  MQSwipingCardsView.h
//  UIKitDynamics
//
//  Created by Daniel Devesa Derksen-Staats on 30/06/2016.
//  Copyright © 2016 Desfici. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "MQAutolayoutHelper.h"

typedef NS_ENUM(NSUInteger, MQSwipingCardsViewDisposition) {
    MQSwipingCardsViewDispositionPerfectStack,
    MQSwipingCardsViewDispositionDisordered,
};

typedef NS_ENUM(NSUInteger, MQSwipingCardsViewDirection) {
    MQSwipingCardsViewDirectionsUp = (1 << 0),
    MQSwipingCardsViewDirectionsRight = (1 << 1),
    MQSwipingCardsViewDirectionsLeft = (1 << 2),
    MQSwipingCardsViewDirectionsDown = (1 << 3),
    MQSwipingCardsViewDirectionsNone = (1 << 4)
};

@protocol MQSwipingCardsViewDataSource, MQSwipingCardsViewDelegate;

@interface MQSwipingCardsView : UIView

@property (assign, nonatomic) MQSwipingCardsViewDisposition cardsDisposition;
@property (assign, nonatomic) MQSwipingCardsViewDirection allowedDirections;

@property (weak, nonatomic) id<MQSwipingCardsViewDataSource> dataSource;
@property (weak, nonatomic) id<MQSwipingCardsViewDelegate> delegate;

- (UIView *)cardAtIndex:(NSUInteger)index;
- (void)swipeCardToDirection:(MQSwipingCardsViewDirection)direction;

@end

@protocol MQSwipingCardsViewDataSource

- (UIView *)swipingCardsView:(MQSwipingCardsView *)view cardAtIndex:(NSUInteger)index;
- (NSUInteger)numberOfCardsInSwipingCardsView:(MQSwipingCardsView *)view;

@end

@protocol MQSwipingCardsViewDelegate

- (void)swipingCardsView:(MQSwipingCardsView *)view
 didCancelSwipingAtIndex:(NSUInteger)index;
- (void)swipingCardsView:(MQSwipingCardsView *)view
      swipingCardAtIndex:(NSUInteger)index
            withPosition:(CGPoint)position;
- (void)swipingCardsView:(MQSwipingCardsView *)view
     didSwipeCardAtIndex:(NSUInteger)index
             inDirection:(MQSwipingCardsViewDirection)direction;

@end